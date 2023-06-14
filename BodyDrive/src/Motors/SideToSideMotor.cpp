#include "SideToSideMotor.h"

void SideToSideMotor::init()
{
    SideToSideMotor::motor = &GMotor(DRIVER2WIRE, SIDE_TO_SIDE_MOTOR_R_PWM_PIN, SIDE_TO_SIDE_MOTOR_L_PWM_PIN);
    SideToSideMotor::motor->setMode(AUTO);
}

void SideToSideMotor::run(int val)
{
    SideToSideMotor::motor->setSpeed(map(val, 0, 1024, -255, 255));
}