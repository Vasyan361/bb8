#include "JoystickControl.h"

void JoystickControl::init()
{
    JoystickControl::readConfigFromEeprom();
    // Serial.print("minX "); Serial.println(JoystickControl::joystcksConfigs[2].minX);
    // Serial.print("centerX "); Serial.println(JoystickControl::joystcksConfigs[2].centerX);
    // Serial.print("maxX "); Serial.println(JoystickControl::joystcksConfigs[2].maxX);
    
    // Serial.print("minY "); Serial.println(JoystickControl::joystcksConfigs[2].minY);
    // Serial.print("centerY "); Serial.println(JoystickControl::joystcksConfigs[2].centerY);
    // Serial.print("maxY "); Serial.println(JoystickControl::joystcksConfigs[2].maxY);
}

void JoystickControl::setSelectedJoystick(int selectedJoystick)
{
    JoystickControl::selectedJoystick = selectedJoystick;
}

Joystick* JoystickControl::getSelectedJoystick()
{
    return &JoystickControl::joysticks[JoystickControl::selectedJoystick];
}

void JoystickControl::updateSelectedJoystickCenter()
{
    JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].centerX = JoystickControl::getSelectedJoystick()->getXValue();
    JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].centerY = JoystickControl::getSelectedJoystick()->getYValue();
}

void JoystickControl::updateSelectedJoystickMinMax()
{
    JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].minX = JoystickControl::getSelectedJoystick()->getMinX();
    JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].maxX = JoystickControl::getSelectedJoystick()->getMaxX();

    JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].minY = JoystickControl::getSelectedJoystick()->getMinY();
    JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].maxY = JoystickControl::getSelectedJoystick()->getMaxY();
}

void JoystickControl::saveJoystickConfig()
{
    // Serial.print("minX "); Serial.println(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].minX);
    // Serial.print("centerX "); Serial.println(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].centerX);
    // Serial.print("maxX "); Serial.println(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].maxX);
    
    // Serial.print("minY "); Serial.println(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].minY);
    // Serial.print("centerY "); Serial.println(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].centerY);
    // Serial.print("maxY "); Serial.println(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick].maxY);
    JoystickControl::joysticks[JoystickControl::selectedJoystick].setConfig(JoystickControl::joystcksConfigs[JoystickControl::selectedJoystick]);
    EEPROM.put(CONFIG_ADDRESS, JoystickControl::joystcksConfigs);
    EEPROM.commit();
}

void JoystickControl::readConfigFromEeprom()
{
    EEPROM.begin(256);
    if (EEPROM.read(INIT_ADDRESS) != 'w') {
        for (int i = 0; i < 3; i++)
        {
            joystckConfig initJoystckConfig;
            JoystickControl::joystcksConfigs[i] = initJoystckConfig;
        }

        EEPROM.put(CONFIG_ADDRESS, JoystickControl::joystcksConfigs);
        EEPROM.write(INIT_ADDRESS, 'w');
        EEPROM.commit();
    } else {
        EEPROM.get(CONFIG_ADDRESS, JoystickControl::joystcksConfigs);
    }

    for (int i = 0; i < 3; i++)
    {
        JoystickControl::joysticks[i].setConfig(JoystickControl::joystcksConfigs[i]);
    }
}

BodyTransmitData JoystickControl::getJoystickControlTransmitData()
{
    BodyTransmitData data;
    data.TopLeftXJoystick = JoystickControl::joysticks[LEFT_TOP].getXValueForTransmit();
    data.TopLeftYJoystick = JoystickControl::joysticks[LEFT_TOP].getYValueForTransmit();
    data.TopRightXJoystick = JoystickControl::joysticks[RIGHT_TOP].getXValueForTransmit();
    data.TopRightYJoystick = JoystickControl::joysticks[RIGHT_TOP].getYValueForTransmit();

    data.BottomLeftXJoystick = JoystickControl::joysticks[LEFT_BOTTOM].getXValueForTransmit();
    data.BottomRightXJoystick = JoystickControl::joysticks[RIGHT_BOTTOM].getXValueForTransmit();

    return data;
}