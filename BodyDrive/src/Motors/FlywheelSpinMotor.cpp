#include "FlywheelSpinMotor.h"

void FlywheelSpinMotor::init()
{
    FlywheelSpinMotor::motor.setMode(AUTO);
}

void FlywheelSpinMotor::run(int val)
{
    FlywheelSpinMotor::motor.setSpeed(map(val, 0, 1024, -255, 255));
}