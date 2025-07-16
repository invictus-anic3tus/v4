#include <esp_now.h>
#include <WiFi.h>

// replace with the drone receiver's MAC address!
uint8_t receiverAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

const int channelNum = 11; // 11 channels total

const int stickXPin = 3; // gpio 3
const int stickYPin = 4; // gpio 4
const int stickButton = 10; // etc.
const int indexPin = 5; // index finger button
const int middlePin = 6; // middle finger button

// values for the above thingies
int xval = 0;
int yval = 0;
int stickVal = 0;
int indexVal = 0;
int middleVal = 0;

// must match the receiver structure
typedef struct struct_message {
    int source_id; // source A (1) is left controller, B (2) is right controller
    int16_t ch[channelNum];
} struct_message;

// Create a struct_message called incomingData
struct_message incomingData;


// when data is received
void onReceive(const uint8_t *mac, const uint8_t *incomingDataBytes, int len) {
  memcpy(&incomingData, incomingDataBytes, sizeof(incomingData)); // copy all of ( sizeof(incomingData) ) incomingDataBytes to incomingData

  Serial.println("Successfully received data from A");

  // read inputs
  // analog vals are from 0 to 4095, but we need to get them to from -1000 to 1000
  xval = map(analogRead(stickXPin), 0, 4095, -1000, 1000);
  yval = map(analogRead(stickYPin), 0, 4095, -1000, 1000);
  stickVal = digitalRead(stickButton);
  indexVal = digitalRead(indexPin);
  middleVal = digitalRead(middlePin);
  
  // set values to send
  incomingData.source_id = 2;     // update ID since B is now sending
  incomingData.ch[0] = yval;      // channel 1  is Y on the right: Roll
  incomingData.ch[1] = xval;      // channel 2  is X on the right: Pitch
  incomingData.ch[5] = stickVal;  // channel 6  (AUX 2) is right thumb button
  incomingData.ch[7] = indexVal;  // channel 8  (AUX 4) is right index button
  incomingData.ch[9] = middleVal; // channel 10 (AUX 6) is right middle button

  // all the missing channels were added by the "sensor" esp32, on the right controller. the left controller reads its own values and transmits them to the right controller, which adds its values to the mix and sends them to the drone.

  // send message via ESP-Now      address        data                  data length
  esp_err_t result = esp_now_send(receiverAddress, (uint8_t *) &incomingData, sizeof(incomingData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success"); // yippee!!11!
  }
  else {
    Serial.println("Error sending the data"); // oh noes :(
  }
}


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
  esp_now_register_recv_cb(onReceive);
  

  // Create peer interface
  esp_now_peer_info_t peerInfo = {};

  // register peer
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  
  // add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  delay(20); // idle and wait
}
