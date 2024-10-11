#include <esp_now.h>
#include <WiFi.h>
#include <EasyTransfer.h>

uint8_t domeAddress[] = {0x40, 0x22, 0xD8, 0x03, 0xBA, 0x68};

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
    int16_t domeLightMode = 0;
} BodyTransmitData;

typedef struct BodyReceiveData {
    int16_t psi = 0;
    int16_t domeLightMode = 0;
    float bodyBattery;
} BodyReceiveData;
 
BodyTransmitData bodyData;
BodyReceiveData bodyReceiveData;

EasyTransfer sendToBodyData;
EasyTransfer receiveFromBodyData;

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
    // Serial.print(bodyData.motorEnable); Serial.print(", ");
    // Serial.println(bodyData.domeLightMode);
    
}
 
void setup() {
    Serial.begin(115200);
    Serial2.begin(57600);
    
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        return;
    }

    // Регистрируем отправку сообщения
    esp_now_register_send_cb(OnDataSent);
    
    // Указываем получателя
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, domeAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Failed to add peer");
        return;
    }

    sendToBodyData.begin(details(bodyData), &Serial2);
    receiveFromBodyData.begin(details(bodyReceiveData), &Serial2);
    
    esp_now_register_recv_cb(OnDataReceive);
}

void loop() {
    if(receiveFromBodyData.receiveData()){
        // Serial.print(bodyReceiveData.psi); Serial.print(", ");
        // Serial.print(bodyReceiveData.domeLightMode); Serial.print(", ");
        // Serial.println(bodyReceiveData.bodyBattery);

        esp_err_t result = esp_now_send(domeAddress, (uint8_t *) &bodyReceiveData, sizeof(bodyReceiveData));

        // if (result == ESP_OK) {
        //     Serial.println("Sent with success");
        // }
        // else {
        //     Serial.println("Error sending the data");
        // }
    }
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}