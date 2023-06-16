#include "SideToSideMotor.h"

void SideToSideMotor::init()
{
    SideToSideMotor::motor.setMode(AUTO);
}

void SideToSideMotor::run(int val)
{
    SideToSideMotor::motor.setSpeed(constrain(map(val, 0, 1024, -SideToSideMotor::speed, SideToSideMotor::speed), -SideToSideMotor::speed, SideToSideMotor::speed));
}

void SideToSideMotor::setSpeed(int speed)
{
    SideToSideMotor::speed = speed;
}