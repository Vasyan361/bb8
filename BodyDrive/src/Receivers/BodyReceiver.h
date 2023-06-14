#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <EasyTransfer.h>
#include "BodyReceiveStruct.h"

class BodyReceiver
{
    public:
        void init();
        void receiveData();
        int16_t getTopLeftXJoystickValue();
        int16_t getTopLeftYJoystickValue();
        int16_t getTopRightYJoystickValue();
        int16_t getTopRightXJoystickValue();
        int16_t getBottomLeftXJoystickValue();
        int16_t getBottomRightXJoystickValue();
    private:
        // typedef struct BodyReceiveData {
        //     int16_t TopLeftXJoystick = 512;
        //     int16_t TopLeftYJoystick = 512;

        //     int16_t TopRightXJoystick = 512;
        //     int16_t TopRightYJoystick = 512;

        //     int16_t  = 512;
        //     int16_t  = 512;

        //     int16_t speed = 0;
        //     int16_t direction = 0;
        //     int16_t happySound = 0;
        //     int16_t sadSound = 0;
        //     int16_t calibrationId = 0;
        //     int16_t motorEnable = 0;
        // } BodyReceiveData;
        EasyTransfer ReceiveBody;
};