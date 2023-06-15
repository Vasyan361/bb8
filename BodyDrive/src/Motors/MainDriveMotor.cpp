#include "MainDriveMotor.h"

void MainDriveMotor::init()
{
    MainDriveMotor::motor.setMode(AUTO);
}

void MainDriveMotor::run(int val)
{
    MainDriveMotor::motor.setSpeed(map(val, 0, 1024, -255, 255));
}