#include "TransmitterAndReceiver.h"

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void TransmitterAndReceiver::init(uint8_t bodyAddress[])
{
    memcpy(TransmitterAndReceiver::bodyAddress, bodyAddress, 6);
    // Выбираем режим WiFi
    WiFi.mode(WIFI_STA);

    // Запускаем протокол ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Регистрируем отправку сообщения
    esp_now_register_send_cb(OnDataSent);
    
    // Указываем получателя
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, TransmitterAndReceiver::bodyAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Failed to add peer");
        return;
    }
}

void TransmitterAndReceiver::setJoystickControl(JoystickControl* joystickControl)
{
    TransmitterAndReceiver::joystickControl = joystickControl;
}

void TransmitterAndReceiver::sendData()
{
    BodyTransmitData bodyData = TransmitterAndReceiver::joystickControl->getJoystickControlTransmitData();

    esp_err_t result = esp_now_send(TransmitterAndReceiver::bodyAddress, (uint8_t *) &bodyData, sizeof(bodyData));
   
    if (result == ESP_OK) {
        Serial.println("Sent with success");
    }
    else {
        Serial.println("Error sending the data");
    }
}