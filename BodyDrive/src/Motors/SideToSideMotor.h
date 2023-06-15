#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>

class SideToSideMotor
{
    public:
        void init();
        void run(int val);
    private:
        GMotor motor = GMotor(DRIVER2WIRE, SIDE_TO_SIDE_MOTOR_R_PWM_PIN, SIDE_TO_SIDE_MOTOR_L_PWM_PIN);
};