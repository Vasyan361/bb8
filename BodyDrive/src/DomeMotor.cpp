#include "DomeMotor.h"

void DomeMotor::init()
{
    DomeMotor::motor = &GMotor(DRIVER2WIRE, DOME_MOTOR_IN3_PIN, DOME_MOTOR_IN4_PIN);
    DomeMotor::motor->setMode(AUTO);
}

void DomeMotor::run(int val)
{
    DomeMotor::motor->setSpeed(map(val, 0, 1024, -255, 255));
}