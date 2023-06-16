#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>

class MainDriveMotor
{
    public:
        void init();
        void run(int val);
        void setSpeed(int speed);
    private:
        GMotor motor = GMotor(DRIVER2WIRE, MAIN_DRIVE_MOTOR_R_PWM_PIN, MAIN_DRIVE_MOTOR_L_PWM_PIN);
        int speed = 124;
};