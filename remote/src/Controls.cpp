#include "Controls.h"

void Controls::init(Menu* menu)
// void Controls::init()
{
    Controls::menu = menu;

    Controls::buttons[LEFT_TOP_JOYSTICK_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftTopJoystickButtonClick();}, this);
    Controls::buttons[RIGHT_TOP_JOYSTICK_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightTopJoystickButtonClick();}, this);

    Controls::buttons[LEFT_LEFT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftLeftButtonClick();}, this);
    Controls::buttons[LEFT_UP_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftUpButtonClick();}, this);
    Controls::buttons[LEFT_DOWN_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftDownButtonClick();}, this);
    Controls::buttons[LEFT_RIGHT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftRightButtonClick();}, this);

    Controls::buttons[RIGHT_LEFT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightLeftButtonClick();}, this);
    Controls::buttons[RIGHT_UP_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightUpButtonClick();}, this);
    Controls::buttons[RIGHT_DOWN_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightDownButtonClick();}, this);
    Controls::buttons[RIGHT_DOWN_BUTTON].attachDoubleClick([](void *scope) { ((Controls *) scope)->rightDownButtonDoubleClick();}, this);
    Controls::buttons[RIGHT_RIGHT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightRightButtonClick();}, this);

    pinMode(MOTOR_ENABLE_PIN, INPUT_PULLUP);
}

void Controls::readInput()
{
    for (int i = 0; i < 10; i++) {
        Controls::buttons[i].tick();
    }
}

void Controls::leftTopJoystickButtonClick()
{
    Serial.println("leftTopJoystickButtonClick");
    Controls::direction = !Controls::direction;
    Controls::menu->setDirection(Controls::direction);
}

void Controls::rightTopJoystickButtonClick()
{
    Serial.println("rightTopJoystickButtonClick");
}

void Controls::leftLeftButtonClick()
{
    Serial.println("buttonBackClick");
    Controls::menu->buttonBackClick();
}

void Controls::leftUpButtonClick()
{
    Serial.println("buttonUpClick");
    Controls::menu->buttonUpClick();
}

void Controls::leftDownButtonClick()
{
    Serial.println("buttonDownClick");
    Controls::menu->buttonDownClick();
}

void Controls::leftRightButtonClick()
{
    Serial.println("buttonOkClick");
    Controls::menu->buttonOkClick();
}

void Controls::rightLeftButtonClick()
{
    Serial.println("rightLeftButtonClick");
    Controls::speed++;
    if(Controls::speed > 2) {
        Controls::speed = 0;
    }

    Controls::menu->setSpeed(Controls::speed);
}

void Controls::rightUpButtonClick()
{
    Serial.println("rightUpButtonClick");
    Controls::domeLightMode++;
    if(Controls::domeLightMode > 2) {
        Controls::domeLightMode = 0;
    }
}

void Controls::rightDownButtonClick()
{
    Serial.println("rightDownButtonClick");
    Controls::soundMusic++;
    if(Controls::soundMusic > 5) {
        Controls::soundMusic = 0;
    }
}

void Controls::rightDownButtonDoubleClick()
{
    Serial.println("rightDownButtonDoubleClick");

    Controls::soundMusic = 6;
}


void Controls::rightRightButtonClick()
{
    Serial.println("rightRightButtonClick");
    Controls::soundBip = !Controls::soundBip;
}

int Controls::getSpeed()
{
    return Controls::speed;
}

int Controls::getDirection()
{
    return Controls::direction;
}

int Controls::getSoundBip()
{
    return Controls::soundBip;
}

int Controls::getSoundMusic()
{
    return Controls::soundMusic;
}

int Controls::getMotorEnable()
{
    return digitalRead(MOTOR_ENABLE_PIN);
}

int Controls::getDomeLightMode()
{
    return Controls::domeLightMode;
}