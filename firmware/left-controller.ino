#include <esp_now.h>
#include <WiFi.h>

// replace with the right controller's MAC address!
uint8_t rightAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

const int channelNum = 11; // 11 channels total

const int stickXPin = 3; // gpio 3
const int stickYPin = 4; // gpio 4
const int stickButton = 10; // etc.
const int potPin = 2;
const int indexPin = 5; // index finger button
const int middlePin = 6; // middle finger button

// values for the above thingies
int xval = 0;
int yval = 0;
int stickVal = 0;
int potVal = 0;
int indexVal = 0;
int middleVal = 0;

// must match the receiver structure
typedef struct struct_message {
    int source_id; // source A (1) is left controller, B (2) is right controller
    int16_t ch[channelNum];
} struct_message;

// Create a struct_message called sentData
struct_message sentData;

// Create peer interface
esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // initialize serial monitor
  Serial.begin(115200);

  // set device as a wifi station
  WiFi.mode(WIFI_STA);

  // Init ESP-Now
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_send_cb(OnDataSent);
  
  // register peer
  memcpy(peerInfo.peer_addr, rightAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  sentData.source_id = 1;
}
 
void loop() {
  // read inputs
  // analog vals are from 0 to 4095, but we need to get them to from -1000 to 1000
  xval = map(analogRead(stickXPin), 0, 4095, -1000, 1000);
  yval = map(analogRead(stickYPin), 0, 4095, -1000, 1000);
  stickVal = digitalRead(stickButton);
  potVal = map(analogRead(potPin), 0, 4095, -1000, 1000);
  indexVal = digitalRead(indexPin);
  middleVal = digitalRead(middlePin);
  
  // set values to send
  sentData.ch[0] = 0;         // channel 1  is Y on the right   : Roll (not in this code)
  sentData.ch[1] = 0;         // channel 2  is X on the right   : Pitch (not in this code)
  sentData.ch[2] = yval;      // channel 3  is Y on the left    : Yaw
  sentData.ch[3] = xval;      // channel 4  is X on the left    : Throttle
  sentData.ch[4] = stickVal;  // channel 5  (AUX 1) is left thumb button
  sentData.ch[5] = 0;         // channel 6  (AUX 2) is right thumb button (not in this code)
  sentData.ch[6] = indexVal;  // channel 7  (AUX 3) is left index button
  sentData.ch[7] = 0;         // channel 8  (AUX 4) is right index button (not in this code)
  sentData.ch[8] = middleVal; // channel 9  (AUX 5) is left middle button
  sentData.ch[9] = 0;         // channel 10 (AUX 6) is right middle button (not in this code)
  sentData.ch[10] = potVal;   // channel 11 (AUX 7) is the left potentiometer (camera angle)

  // all the values not in this code snippet will be added by the "relay" esp32, on the right controller. the left controller reads its own values and transmits them to the right controller, which adds its values to the mix and sends them to the drone.

  // send message via ESP-Now      address        data                  data length
  esp_err_t result = esp_now_send(rightAddress, (uint8_t *) &sentData, sizeof(sentData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success"); // yippee!!11!
  }
  else {
    Serial.println("Error sending the data"); // oh noes :(
  }
  delay(20); // wait 20ms
}
