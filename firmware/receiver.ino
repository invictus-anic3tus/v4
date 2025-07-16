#include <WiFi.h>
#include <esp_now.h>
#include "SBUS.h"

/*
  IMPORTANT!
  As soon as you're able to fine-tune hover value, replace the following with that hover value.
  This is in case the controllers fail, so that the drone can lower itself regardless, and also so that the midpoint on the joystick is the hover position.

  You can find it by slowly testing the drone itself while watching the values in the SpeedyBee app receiver tab. They should go from 1000 to 2000. Once you find the hover number in this range, say 1300, simply subtract 1000 to get 300.
*/

const int throttleToHover = 300;

/*
  End important stuff :)
*/

HardwareSerial SerialSbus(1); // UART1
#define SBUS_TX_PIN 21 // sbus pin for communicating with the fc

const int channelNum = 11;

// failsafe variables
unsigned long lastReceiveTime = 0;
const unsigned long FAILSAFE_TIMEOUT = 1000; // 1 second timeout
bool failsafeActive = false;

// non-inverted sbus: if it doesn't register when connected to SBUS (R2), try connected to R3, and vice versa.
SBUS sbus(&SerialSbus, -1, SBUS_TX_PIN, false);

typedef struct struct_message {
  uint8_t source_id;      // source A (1) is left controller, B (2) is right controller
  int16_t ch[channelNum]; // 11 channels, -1000 to 1000 from 2 joysticks with buttons (6 channels), four buttons (4 channels), and a potentiometer (one channel)
} struct_message;

struct_message receivedData;

bool validateData(const struct_message& data) {
  if (data.source_id != 1 && data.source_id != 2) {
    Serial.println("Invalid Source ID");
    return false;
  }

  for (int i=0; i<channelNum; i++) {
    if (data.ch[i] < -1000 || data.ch[i] > 1000) {
      Serial.printf("Channel %d out of range: %d\n", i, data.ch[i]);
      return false;
    }
  }

  int maxCount = 0;
  int minCount = 0;
  for (int i = 0; i < channelNum; i++) {
    if (data.ch[i] == 1000) maxCount++;
    if (data.ch[i] == -1000) minCount++;
  }

  if (maxCount > 8 || minCount > 8) {
    Serial.println("Suspicious data received");
    return false;
  }

  return true;
}


// sbus expects 16 channels, 0-2047 per channel
uint16_t sbusChannels[16] = {0};

// map function: -1000 to 1000 to sbus range 172 to 1811
uint16_t mapToSBUS(int16_t val) {
  if (val < -1000) val = -1000; // these ifs clamp the sbus values in case they're over/under the limits
  if (val > 1000) val = 1000;
  // map to sbus range
  return map(val, -1000, 1000, 172, 1811);
}

void setFailsafe() {
  for (int i = 0; i < channelNum; i++) {
    if (i < 4) sbusChannels[i] = mapToSBUS(0); // set all the joysticks to middle
    if (i >= 4 && i != 10) sbusChannels[i] = mapToSBUS(-1000); // set the aux channels to off
    if (i == 10) sbusChannels[i] = mapToSBUS(0); // servo channel -- set to midpoint of 0
  }

  // fill unused channels (channels 12-16) with middle or default value
  for (int i = channelNum; i < 16; i++) {
    sbusChannels[i] = 992; // sbus midpoint
  }

  sbusChannels[3] = mapToSBUS(throttleToHover-50); // slowly lower the drone
}

// ESP-Now receive callback
//                      mac address,                        data, data length
void onDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {

  // Check data length
  if (len != sizeof(receivedData)) {
    Serial.printf("Invalid data length: %d, expected: %d\n", len, sizeof(receivedData));
    return;
  }
  
  struct_message tempData;
  memcpy(&tempData, incomingData, sizeof(tempData)); // copy data from incoming to temp
  
  // Validate the data
  if (!validateData(tempData)) {
    Serial.println("Data validation failed - ignoring");
    return;
  }
  
  // valid data: update receive time and copy data
  lastReceiveTime = millis();
  memcpy(&receivedData, &tempData, sizeof(receivedData));
  
  // Clear failsafe if it was active
  if (failsafeActive) {
    failsafeActive = false;
    Serial.println("Communication restored - failsafe deactivated");
  }

  // map received channels to sbus
  for (int i = 0; i < channelNum; i++) {
    if (i == 3) {
      // make the throttle channel's midpoint at the hover point
      // the left joystick is giving the receiver esp32 values of -1000 to 1000 in the end, where 0 is the midpoint of the joystick
      // this makes sure that 0 is always throttleToHover
      // for example, if throttleToHover is 300, then we're mapping -1000->1000 to 172->428 (two times throttle minus 172)
      // so that the midpoint (receivedData gives a 0, which is when the joystick is at rest) is at exactly throttleToHover
      // this intentionally limits the throttle, as 100% throttle would cause the drone to go incredibly fast, at least for my motors.
      sbusChannels[i] = map(receivedData.ch[i], -1000, 1000, 172, (throttleToHover*2) - 172);
    }
    else {
      sbusChannels[i] = mapToSBUS(receivedData.ch[i]); // map the received data channels (-1000 to 1000) to sbus channels (172 to 1811)
    }
  }

  // fill unused channels (channels 12-16) with middle or default value
  for (int i = channelNum; i < 16; i++) {
    sbusChannels[i] = 992; // sbus midpoint
  }
}

void setup() {
  Serial.begin(115200);

  // wifi and ESP-Now long rage init
  WiFi.mode(WIFI_STA);
  esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_LR);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(onDataRecv);

  // sbus init
  sbus.Begin();

  // Initialize failsafe values
  setFailsafe();
  lastReceiveTime = millis();
  
  Serial.println("Receiver initialized - waiting for controller data...");
}

void loop() {

  // if it's been more than one second between controller sends, set the failsafes

  if (millis() - lastReceiveTime > FAILSAFE_TIMEOUT) {
    if (!failsafeActive) {
      failsafeActive = true;
      Serial.println("Communication timeout - FAILSAFE ACTIVATED");
      setFailsafe();
    }
  }

  // send sbus packet every 20ms
  sbus.data(sbusChannels);
  sbus.Write();
  delay(20);
}
