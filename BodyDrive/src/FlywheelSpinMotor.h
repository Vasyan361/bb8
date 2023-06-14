#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>

class FlywheelSpinMotor
{
    public:
        void init();
        void run(int val);
    private:
        GMotor* motor;
};

