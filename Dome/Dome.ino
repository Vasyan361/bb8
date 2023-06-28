#include <Adafruit_NeoPixel.h>
#include <esp_now.h>
#include <WiFi.h>
#include "src/Eye.h"
#include "src/LargeLogic.h"
#include "src/SmallLogic.h"
#include "src/Holoprojector.h"
#include "src/Psi.h"
#include "src/Inputs.h"

Eye eye;
LargeLogic largeLogic;
SmallLogic smallLogic;
Holoprojector holoprojector;
Psi psi;

Inputs inputs;

uint32_t timer;

uint32_t sendTimer;

bool needSend = false;

uint8_t remoteAddress[] = {0x40, 0x22, 0xD8, 0x02, 0xA1, 0x58};

typedef struct BodyReceiveData {
    int16_t psi = 0;
    int16_t domeLightMode = 0;
    float bodyBattery = 0;
} BodyReceiveData;
 
BodyReceiveData bodyData;

typedef struct SendRemoteData {
    float bodyBattery = 0;
    float domeBattery = 0;
} SendRemoteData;
 
SendRemoteData remoteData;


void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
	if (bodyData.bodyBattery == 0) {
		needSend =true;
	}
    memcpy(&bodyData, incomingData, sizeof(bodyData));


    // Serial.print(bodyData.psi); Serial.print(", ");
    // Serial.print(bodyData.domeLightMode); Serial.print(", ");
    // Serial.println(bodyData.bodyBattery);
}

void setup() {
	Serial.begin(115200);

	WiFi.mode(WIFI_STA);
	if (esp_now_init() != ESP_OK) {
		return;
	}
	// Регистрируем отправку сообщения
	esp_now_register_send_cb(OnDataSent);

	// Указываем получателя
	esp_now_peer_info_t peerInfo;
	memcpy(peerInfo.peer_addr, remoteAddress, 6);
	peerInfo.channel = 0;  
	peerInfo.encrypt = false;
	if (esp_now_add_peer(&peerInfo) != ESP_OK){
		Serial.println("Failed to add peer");
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

        switch (bodyData.domeLightMode)
		{
		case 0:
			eye.low();
			largeLogic.topWhite();
			smallLogic.low();
			holoprojector.disable();
			psi.low();
			break;
		case 1:
			eye.fade();
			largeLogic.fade();
			smallLogic.fade();
			holoprojector.pulse();
			psi.fade();
			break;
		case 2:
			eye.randomBlink();
			largeLogic.randomBlink();
			smallLogic.randomBlink();
			holoprojector.cycle();
			psi.randomBlink();
			break;
		default:
			break;
		}
  	}

	if (millis() - sendTimer >= 15000 || needSend) {
        sendTimer = millis();

		inputs.readBatteryVoltage();

		remoteData.bodyBattery = bodyData.bodyBattery;
		remoteData.domeBattery = inputs.getBatteryVoltage();

		esp_err_t result = esp_now_send(remoteAddress, (uint8_t *) &remoteData, sizeof(remoteData));

        if (result == ESP_OK) {
            Serial.println("Sent with success");
        }
        else {
            Serial.println("Error sending the data");
        }
  	}
        
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}