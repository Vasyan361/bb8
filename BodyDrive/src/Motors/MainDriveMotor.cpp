#include "MainDriveMotor.h"

void MainDriveMotor::init()
{
    MainDriveMotor::motor.setMode(AUTO);
}

void MainDriveMotor::run(int val)
{
    MainDriveMotor::motor.setSpeed(constrain(map(val, 0, 1024, -MainDriveMotor::speed, MainDriveMotor::speed), -MainDriveMotor::speed, MainDriveMotor::speed));
}

void MainDriveMotor::setSpeed(int speed)
{
    MainDriveMotor::speed = speed;
}