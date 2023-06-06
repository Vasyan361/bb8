#include <esp_now.h>
#include <WiFi.h>
#include <EasyTransfer.h>

typedef struct BodyTransmitData {
    int16_t TopLeftXJoystick = 512;
    int16_t TopLeftYJoystick = 512;
    int16_t TopRightXJoystick = 512;
    int16_t TopRightYJoystick = 512;

    int16_t BottomLeftXJoystick = 512;
    int16_t BottomLeftYJoystick = 512;
    int16_t BottomRightXJoystick = 512;
    int16_t BottomRightYJoystick = 512;
} BodyTransmitData;
 
BodyTransmitData bodyData;

EasyTransfer sendToBodyData;

uint32_t timer;
 
void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&bodyData, incomingData, sizeof(bodyData));
    sendToBodyData.sendData();
    Serial.print("Bytes received: ");
    Serial.println(len);
    Serial.print("TopLeftXJoystick: ");
    Serial.println(bodyData.TopLeftXJoystick);
    Serial.print("TopLeftYJoystick: ");
    Serial.println(bodyData.TopLeftYJoystick);
}
 
void setup() {
    Serial.begin(115200);
    Serial2.begin(9600);
    
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        return;
    }

    sendToBodyData.begin(details(bodyData), &Serial2);
    
    esp_now_register_recv_cb(OnDataReceive);
}

void loop() {
}