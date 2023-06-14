#include <esp_now.h>
#include <WiFi.h>
#include <EasyTransfer.h>

typedef struct BodyTransmitData {
    int16_t TopLeftXJoystick = 512;
    int16_t TopLeftYJoystick = 512;

    int16_t TopRightXJoystick = 512;
    int16_t TopRightYJoystick = 512;

    int16_t BottomLeftXJoystick = 512;
    int16_t BottomRightXJoystick = 512;

    int16_t speed = 0;
    int16_t direction = 0;
    int16_t soundBip = 0;
    int16_t soundMusic = 0;
    int16_t calibrationId = 0;
    int16_t motorEnable = 0;
} BodyTransmitData;
 
BodyTransmitData bodyData;

EasyTransfer sendToBodyData;

uint32_t timer;
 
void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&bodyData, incomingData, sizeof(bodyData));
    sendToBodyData.sendData();
    // Serial.print(bodyData.TopLeftXJoystick); Serial.print(", ");
    // Serial.print(bodyData.TopLeftYJoystick); Serial.print(", ");
    // Serial.print(bodyData.TopRightXJoystick); Serial.print(", ");
    // Serial.print(bodyData.TopRightYJoystick); Serial.print(", ");
    // Serial.print(bodyData.BottomLeftXJoystick); Serial.print(", ");
    // Serial.print(bodyData.BottomRightXJoystick); Serial.print(", ");
    // Serial.print(bodyData.speed); Serial.print(", ");
    // Serial.print(bodyData.direction); Serial.print(", ");
    // Serial.print(bodyData.soundBip); Serial.print(", ");
    // Serial.print(bodyData.soundMusic); Serial.print(", ");
    // Serial.print(bodyData.calibrationId); Serial.print(", ");
    // Serial.println(bodyData.motorEnable);
}
 
void setup() {
    Serial.begin(115200);
    Serial2.begin(57600);
    
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        return;
    }

    sendToBodyData.begin(details(bodyData), &Serial2);
    
    esp_now_register_recv_cb(OnDataReceive);
}

void loop() {
}