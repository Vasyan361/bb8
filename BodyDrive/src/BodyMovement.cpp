#include "BodyMovement.h"

void BodyMovement::init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver)
{
    BodyMovement::bodyReceiver = bodyReceiver;
    BodyMovement::imuReveiver = imuReveiver;

    pinMode(FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN, OUTPUT);
    pinMode(SIDE_TO_SIDE_ENABLE_PIN, OUTPUT);

    BodyMovement::sideToSideMotor.init();
    BodyMovement::flywheelSpinMotor.init();
    BodyMovement::mainDriveMotor.init();
}

void BodyMovement::run()
{
    BodyMovement::setSpeed();
    
    if (BodyMovement::bodyReceiver->isActive() && BodyMovement::imuReveiver->isActive() && BodyMovement::bodyReceiver->isEnabledMotor())
    {
        BodyMovement::enableMotor();

        BodyMovement::sideToSideMotor.run(BodyMovement::bodyReceiver->getTopRightXJoystickValue());
        BodyMovement::mainDriveMotor.run(BodyMovement::bodyReceiver->getTopRightYJoystickValue());
        BodyMovement::flywheelSpinMotor.run(BodyMovement::bodyReceiver->getBottomRightXJoystickValue());
    } else {
        BodyMovement::shutdownMotor();
    }
    
}

void BodyMovement::enableMotor()
{
    digitalWrite(FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN, HIGH);
    digitalWrite(SIDE_TO_SIDE_ENABLE_PIN, HIGH);
}

void BodyMovement::shutdownMotor()
{
    digitalWrite(FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN, LOW);
    digitalWrite(SIDE_TO_SIDE_ENABLE_PIN, LOW);
}

void BodyMovement::setSpeed()
{
    if (BodyMovement::lastSpeedValue != BodyMovement::bodyReceiver->getSpeedValue())
    {
        BodyMovement::lastSpeedValue = BodyMovement::bodyReceiver->getSpeedValue();

        BodyMovement::sideToSideMotor.setSpeed(BodyMovement::speedMap[BodyMovement::bodyReceiver->getSpeedValue()]);
        BodyMovement::mainDriveMotor.setSpeed(BodyMovement::speedMap[BodyMovement::bodyReceiver->getSpeedValue()]);
        BodyMovement::flywheelSpinMotor.setSpeed(BodyMovement::speedMap[BodyMovement::bodyReceiver->getSpeedValue()]);
    }
    
}