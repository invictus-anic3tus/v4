#include <WiFi.h>
#include <esp_now.h>
#include "SBUS.h"

/*
  IMPORTANT!
  As soon as you're able to fine-tune hover value, replace the following with a value that slowly lowers the drone.
  This is in case the controllers fail, so that the drone can lower itself regardless.
*/

const int throttleToSlowlySink = 400; // replace this with the just-below hover value!

/*
  End important stuff :)
*/

HardwareSerial SerialSbus(1); // UART1
#define SBUS_TX_PIN 21 // sbus pin for communicating with the fc

const int channelNum = 11;

// non-inverted sbus: if it doesn't register when connected to SBUS (R2), try connected to R3, and vice versa.
SBUS sbus(&SerialSbus, -1, SBUS_TX_PIN, false);

typedef struct struct_message {
  uint8_t source_id;      // source A (1) is left controller, B (2) is right controller
  int16_t ch[channelNum]; // 11 channels, -1000 to 1000 from 2 joysticks with buttons (6 channels), four buttons (4 channels), and a potentiometer (one channel)
} struct_message;

struct_message receivedData;

// sbus expects 16 channels, 0-2047 per channel
uint16_t sbusChannels[16] = {0};

// map function: -1000 to 1000 to sbus range 172 to 1811
uint16_t mapToSBUS(int16_t val) {
  if (val < -1000) val = -1000; // these ifs clamp the sbus values in case they're over/under the limits
  if (val > 1000) val = 1000;
  // map to sbus range
  return map(val, -1000, 1000, 172, 1811);
}

// ESP-Now receive callback
//                      mac address,                        data, data length
void onDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {

  memcpy(&receivedData, incomingData, sizeof(receivedData)); // copy data from incoming data to received data

  // map received channels to sbus
  for (int i = 0; i < channelNum; i++) {
    sbusChannels[i] = mapToSBUS(receivedData.ch[i]); // map the received data channels to sbus channels
  }

  // fill unused channels (channels 12-16) with middle or default value
  for (int i = channelNum; i < 16; i++) {
    sbusChannels[i] = 992; // sbus midpoint
  }
}

void setup() {
  Serial.begin(115200);

  // wifi and ESP-Now init
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(onDataRecv);

  // sbus init
  sbus.Begin();
}

void loop() {
  // send sbus packet every 20ms
  sbus.data(sbusChannels);
  sbus.Write();
  delay(20);
}
