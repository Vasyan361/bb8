#include "Inputs.h"

void Inputs::readBatteryVoltage()
{
    if(millis() - Inputs::lastBatteryUpdate >= 15000 || 0 == Inputs::batteryVoltage){
      Inputs::lastBatteryUpdate = millis();
      Inputs::batteryVoltage = (analogRead(BATTERY_PIN) * 3.3 / 4096.0) / 0.5;
    }
}

float Inputs::getBatteryVoltage()
{
    return Inputs::batteryVoltage;
}