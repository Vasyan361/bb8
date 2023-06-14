#include "FlywheelSpinMotor.h"

void FlywheelSpinMotor::init()
{
    FlywheelSpinMotor::motor = &GMotor(DRIVER2WIRE, FLYWHEEL_SPIN_MOTOR_R_PWM_PIN, FLYWHEEL_SPIN_MOTOR_L_PWM_PIN);
    FlywheelSpinMotor::motor->setMode(AUTO);
}

void FlywheelSpinMotor::run(int val)
{
    FlywheelSpinMotor::motor->setSpeed(map(val, 0, 1024, -255, 255));
}