#include <Adafruit_NeoPixel.h>
#include <esp_now.h>
#include <WiFi.h>
#include "src/Eye.h"
#include "src/LargeLogic.h"
#include "src/SmallLogic.h"
#include "src/Holoprojector.h"

Eye eye;
LargeLogic largeLogic;
SmallLogic smallLogic;
Holoprojector holoprojector;

uint32_t timer;


//40:22:D8:02:A1:58 remote

typedef struct BodyReceiveData {
    int16_t psi = 0;
    int16_t domeLightMode = 0;
    float bodyBattery;
} BodyReceiveData;
 
BodyReceiveData bodyData;


void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&bodyData, incomingData, sizeof(bodyData));
    Serial.print(bodyData.psi); Serial.print(", ");
    Serial.print(bodyData.domeLightMode); Serial.print(", ");
    Serial.println(bodyData.bodyBattery);
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
      return;
  }
  esp_now_register_recv_cb(OnDataReceive);

  eye.init();
  largeLogic.init();
  smallLogic.init();
  holoprojector.init();
}

void loop() {
  if (millis() - timer >= 40) {
        timer = millis();

        eye.fade();
        largeLogic.randomBlink();
        smallLogic.randomBlink();
        holoprojector.cycle();
  }
}