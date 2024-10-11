#include "Receiver.h"

typedef struct BodyReceiveData {
    int16_t psi = 0;
    int16_t domeLightMode = 0;
    float bodyBattery = 0;
} BodyReceiveData;

BodyReceiveData bodyData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&bodyData, incomingData, sizeof(bodyData));

    // Serial.print(bodyData.psi); Serial.print(", ");
    // Serial.print(bodyData.domeLightMode); Serial.print(", ");
    // Serial.println(bodyData.bodyBattery);
}

void Receiver::init()
{
    esp_now_register_recv_cb(OnDataRecv);
}

int16_t Receiver::getDomeLightMode()
{
    return bodyData.domeLightMode;
}

float Receiver::getBodyBattery()
{
    return bodyData.bodyBattery;
}