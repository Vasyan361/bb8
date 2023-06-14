#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <EasyTransfer.h>
#include "ImuReceiveStruct.h"

class ImuReceiver
{
    public:
        void init();
        void receiveData();
        float getImuLoop();
        float getPitch();
        float getRoll();
    private:
        EasyTransfer ReceiveImu;
};