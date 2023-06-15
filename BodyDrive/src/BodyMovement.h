#pragma once

#include <Arduino.h>
#include "../Config.h"
#include "Receivers/BodyReceiver.h"
#include "Receivers/ImuReceiver.h"
#include "Motors/SideToSideMotor.h"
#include "Motors/FlywheelSpinMotor.h"
#include "Motors/MainDriveMotor.h"

class BodyMovement
{
    public:
        void init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver);
        void run();
    private:
        BodyReceiver* bodyReceiver;
        ImuReceiver* imuReveiver;
        SideToSideMotor sideToSideMotor = SideToSideMotor();
        FlywheelSpinMotor flywheelSpinMotor = FlywheelSpinMotor();
        MainDriveMotor mainDriveMotor = MainDriveMotor();
        void enableMotor();
        void shutdownMotor();
};