#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>

class DomeMotor
{
    public:
        void init();
        void run(int val);
    private:
        GMotor* motor;
};