#include "BodyReceiver.h"

BodyReceiveData bodyData;

void BodyReceiver::init()
{
    Serial1.begin(57600);

    BodyReceiver::ReceiveBody.begin(details(bodyData), &Serial1);
}

void BodyReceiver::receiveData()
{
    if(BodyReceiver::ReceiveBody.receiveData()){
        // Serial.print(bodyData.TopLeftXJoystick); Serial.print(", ");
        // Serial.print(bodyData.TopLeftYJoystick); Serial.print(", ");
        // Serial.print(bodyData.TopRightXJoystick); Serial.print(", ");
        // Serial.print(bodyData.TopRightYJoystick); Serial.print(", ");
        // Serial.print(bodyData.BottomLeftXJoystick); Serial.print(", ");
        // Serial.print(bodyData.BottomRightXJoystick); Serial.print(", ");
        // Serial.print(bodyData.speed); Serial.print(", ");
        // Serial.print(bodyData.direction); Serial.print(", ");
        // Serial.print(bodyData.happySound); Serial.print(", ");
        // Serial.print(bodyData.calibrationId); Serial.print(", ");
        // Serial.println(bodyData.motorEnable);
    }
}

int16_t BodyReceiver::getTopLeftXJoystickValue()
{
    return bodyData.TopLeftXJoystick;
}

int16_t BodyReceiver::getTopLeftYJoystickValue()
{
    return bodyData.TopLeftYJoystick;
}

int16_t BodyReceiver::getTopRightXJoystickValue()
{
    return bodyData.TopRightXJoystick;
}

int16_t BodyReceiver::getTopRightYJoystickValue()
{
    return bodyData.TopRightYJoystick;
}

int16_t BodyReceiver::getBottomLeftXJoystickValue()
{
    return bodyData.BottomLeftXJoystick;
}

int16_t BodyReceiver::getBottomRightXJoystickValue()
{
    return bodyData.BottomRightXJoystick;
}