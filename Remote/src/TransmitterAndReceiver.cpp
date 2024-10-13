#include "TransmitterAndReceiver.h"

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

typedef struct DomeData {
    float bodyBattery = 0;
    float domeBattery = 0;
} DomeData;
 
DomeData domeData;

void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&domeData, incomingData, sizeof(domeData));

    // Serial.print(domeData.bodyBattery); Serial.print(", ");
    // Serial.println(domeData.domeBattery);
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

    esp_now_register_recv_cb(OnDataReceive);
}

void TransmitterAndReceiver::setJoystickControl(JoystickControl* joystickControl)
{
    TransmitterAndReceiver::joystickControl = joystickControl;
}

void TransmitterAndReceiver::setButtonControl(Controls* buttonControl)
{
    TransmitterAndReceiver::buttonControl = buttonControl;
}

void TransmitterAndReceiver::setMenu(Menu* menu)
{
    TransmitterAndReceiver::menu = menu;
}

void TransmitterAndReceiver::sendData()
{
    BodyTransmitData bodyData = TransmitterAndReceiver::joystickControl->getJoystickControlTransmitData();

    bodyData.speed = TransmitterAndReceiver::buttonControl->getSpeed();
    bodyData.direction = TransmitterAndReceiver::buttonControl->getDirection();
    bodyData.soundBip = TransmitterAndReceiver::buttonControl->getSoundBip();
    bodyData.soundMusic = TransmitterAndReceiver::buttonControl->getSoundMusic();
    bodyData.motorEnable = TransmitterAndReceiver::buttonControl->getMotorEnable();
    bodyData.calibrationId = TransmitterAndReceiver::menu->getCalibrationId();
    bodyData.domeLightMode = TransmitterAndReceiver::buttonControl->getDomeLightMode();

    esp_err_t result = esp_now_send(TransmitterAndReceiver::bodyAddress, (uint8_t *) &bodyData, sizeof(bodyData));

    if (result == ESP_OK) {
        Serial.println("Sent with success");
    }
    else {
        Serial.println("Error sending the data");
    }

    TransmitterAndReceiver::menu->setBodyBattery(domeData.bodyBattery);
    TransmitterAndReceiver::menu->setDomeBattery(domeData.domeBattery);
}