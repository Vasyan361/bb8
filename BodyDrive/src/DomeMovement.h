#pragma once

#include <Arduino.h>
#include "../Config.h"
#include "Receivers/BodyReceiver.h"
#include "Receivers/ImuReceiver.h"
#include "Calibration.h"
#include "DomeServo.h"

class DomeMovement {
    public:
        void init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver, Calibration* calibration);
        void run();
    private:
        BodyReceiver* bodyReceiver;
        ImuReceiver* imuReveiver;
        Calibration* calibration;
        DomeServo domeServo = DomeServo();
};