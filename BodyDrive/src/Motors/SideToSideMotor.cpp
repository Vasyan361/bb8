#include "SideToSideMotor.h"

void SideToSideMotor::init()
{
    SideToSideMotor::motor.setMode(AUTO);
}

void SideToSideMotor::run(int val)
{
    SideToSideMotor::motor.setSpeed(map(val, 0, 1024, -255, 255));
}