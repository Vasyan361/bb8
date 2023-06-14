#include "ImuReceiver.h"

ImuReceiveData imuData;

void ImuReceiver::init()
{
    Serial2.begin(115200);

    ReceiveImu.begin(details(imuData), &Serial2);
}

void ImuReceiver::receiveData()
{
    if(ReceiveImu.receiveData()){
        // Serial.print("imuLoop"); Serial.print(imuData.imuLoop); Serial.print(", ");
        // Serial.print("pitch"); Serial.print(imuData.pitch); Serial.print(", ");
        // Serial.print("roll"); Serial.println(imuData.roll);
    }
}

float ImuReceiver::getImuLoop()
{
    return imuData.imuLoop;
}

float ImuReceiver::getPitch()
{
    return imuData.pitch;
}

float ImuReceiver::getRoll()
{
    return imuData.roll;
}