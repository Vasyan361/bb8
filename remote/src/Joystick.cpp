#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin)
{
    Joystick::xPin = xPin;
    
    if (yPin == 0) {
        Joystick::isSingleDirection = true;
    } else {
        Joystick::yPin = yPin;
    }
    
}

Joystick::Joystick(int xPin, int yPin, char *name, bool reverseX, bool reverseY)
{
    Joystick::xPin = xPin;

    if (yPin == 0) {
        Joystick::isSingleDirection = true;
    } else {
        Joystick::yPin = yPin;
    }

    Joystick::name = name;
    Joystick::reverseX = reverseX;
    Joystick::reverseY = reverseY;
}

int Joystick::getXValue()
{
    if (Joystick::reverseX) {
        return constrain(map(analogRead(Joystick::xPin), 0, 4096, 4096, 0), 0, 4096);
    }
    
    return analogRead(Joystick::xPin);
}

int Joystick::getYValue()
{
    if (Joystick::isSingleDirection) {
        return 2096;
    }

    if (Joystick::reverseY) {
        return constrain(map(analogRead(Joystick::yPin), 0, 4096, 4096, 0), 0, 4096);
    }
    
    return analogRead(Joystick::yPin);
}

char* Joystick::getName()
{
    return Joystick::name;
}

int Joystick::calculateMinX()
{
    if (Joystick::getXValue() < Joystick::minX) {
        Joystick::minX = Joystick::getXValue();
    }

    return Joystick::minX;
}

int Joystick::calculateMaxX()
{
    if (Joystick::getXValue() > Joystick::maxX) {
        Joystick::maxX = Joystick::getXValue();
    }

    return Joystick::maxX;
}

int Joystick::calculateMinY()
{
    int yValue = Joystick::getYValue();

    if (yValue < Joystick::minY) {
        Joystick::minY = yValue;
    }

    return Joystick::minY;
}

int Joystick::calculateMaxY()
{
    int yValue = Joystick::getYValue();

    if (yValue > Joystick::maxY) {
        Joystick::maxY = yValue;
    }

    return Joystick::maxY;
}

int Joystick::getMinX()
{
    return Joystick::minX;
}

int Joystick::getMaxX()
{
    return Joystick::maxX;
}

int Joystick::getMinY()
{
    return Joystick::minY;
}

int Joystick::getMaxY()
{
    return Joystick::maxY;
}

void Joystick::setConfig(joystckConfig config)
{
    Joystick::config = config;
}

int Joystick::getXValueForTransmit()
{
    if (Joystick::getXValue() > (Joystick::config.centerX - 300) && Joystick::getXValue() < (Joystick::config.centerX + 300))
    {
        return 512;
    }
    

    return constrain(map(Joystick::getXValue(), Joystick::config.minX, Joystick::config.maxX, 0, 1023), 0, 1023);
}

int Joystick::getYValueForTransmit()
{
    if (Joystick::getYValue() > (Joystick::config.centerY - 300) && Joystick::getYValue() < (Joystick::config.centerY + 300))
    {
        return 512;
    }
    

    return constrain(map(Joystick::getYValue(), Joystick::config.minY, Joystick::config.maxY, 0, 1023), 0, 1023);
}