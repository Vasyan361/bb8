#include "DomeMovement.h"

void DomeMovement::init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver, Calibration* calibration)
{
    DomeMovement::bodyReceiver = bodyReceiver;
    DomeMovement::imuReveiver = imuReveiver;
    DomeMovement::calibration = calibration;

    DomeMovement::domeServo.init();
}

void DomeMovement::run()
{
    DomeMovement::domeServo.setSpeed(DomeMovement::bodyReceiver->getSpeedValue());

    DomeMovement::domeServo.setJoystickXValue(DomeMovement::bodyReceiver->getTopLeftXJoystickValue(), DomeMovement::bodyReceiver->getDirectionValue());
    DomeMovement::domeServo.setJoystickYValue(DomeMovement::bodyReceiver->getTopLeftYJoystickValue(), DomeMovement::bodyReceiver->getDirectionValue());
    DomeMovement::domeServo.setYPitchByMainDriveValue(
        DomeMovement::bodyReceiver->getTopRightYJoystickValue(),
        DomeMovement::imuReveiver->getPitchValue(),
        DomeMovement::calibration->getPitchOffset()
    );

    DomeMovement::domeServo.move();
}