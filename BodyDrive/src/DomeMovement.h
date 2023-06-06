#pragma once

#include <Arduino.h>
#include "../Config.h"
#include <Servo.h>

class DomeMovement {
    public:
        void init();
        void moveServo(int x, int y);
    private:
        Servo leftServo;
        Servo rightServo;
};