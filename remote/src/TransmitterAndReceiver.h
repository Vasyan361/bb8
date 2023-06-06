#pragma once

#include "../Config.h"
#include <esp_now.h>
#include <WiFi.h>
#include "JoystickControl.h"

class TransmitterAndReceiver {
    public:
        void init(uint8_t bodyAddress[]);
        void setJoystickControl(JoystickControl* joystickControl);
        void sendData();
    private:
        JoystickControl* joystickControl;
        uint8_t bodyAddress[6];
};