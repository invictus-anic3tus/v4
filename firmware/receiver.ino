#include <WiFi.h>
#include <esp_now.h>
#include "SBUS.h"

HardwareSerial SerialSbus(1); // UART1
#define SBUS_TX_PIN 21

int channelNum = 11

// non-inverted sbus: if it doesn't register when connected to SBUS (R2), try connected to R3, and vice versa.
SBUS sbus(&SerialSbus, -1, SBUS_TX_PIN, false);

typedef struct struct_message {
  int16_t ch[channelNum]; // 11 channels, -1000 to 1000 from 2 joysticks with buttons, four buttons, and a potentiometer
} struct_message;

struct_message receivedData;

// sbus expects 16 channels, 0-2047 per channel
uint16_t sbusChannels[16] = {0};

// map function: -1000 to 1000 to sbus range 172 to 1811
uint16_t mapToSBUS(int16_t val) {
  if (val < -1000) val = -1000;
  if (val > 1000) val = 1000;
  // map to sbus range
  return map(val, -1000, 1000, 172, 1811);
}

// ESP-Now receive callback
void onDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  // map received channels to sbus
  for (int i = 0; i < channelNum; i++) {
    sbusChannels[i] = mapToSBUS(receivedData.ch[i]);
  }
  // fill unused channels with middle or default value
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
