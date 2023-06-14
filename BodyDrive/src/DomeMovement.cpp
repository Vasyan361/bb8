#include "DomeMovement.h"

#define DomeXEase 0.7          // Speed of side to side domemovement, higher == faster
#define DomeYEase 0.4          // Spead of front to back dome movement, higher == faster

void DomeMovement::init()
{
    DomeMovement::leftServo.attach(LEFT_SERVO_PIN);
    DomeMovement::rightServo.attach(RIGHT_SERVO_PIN);
}

void DomeMovement::moveServo(int x, int y)
{
}