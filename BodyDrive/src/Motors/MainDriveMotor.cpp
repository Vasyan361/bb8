#include "MainDriveMotor.h"

void MainDriveMotor::init()
{
    MainDriveMotor::motor = &GMotor(DRIVER2WIRE, MAIN_DRIVE_MOTOR_R_PWM_PIN, MAIN_DRIVE_MOTOR_L_PWM_PIN);
    MainDriveMotor::motor->setMode(AUTO);
}

void MainDriveMotor::run(int val)
{
    MainDriveMotor::motor->setSpeed(map(val, 0, 1024, -255, 255));
}