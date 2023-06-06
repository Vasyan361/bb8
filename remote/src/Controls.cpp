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
    Controls::buttons[RIGHT_RIGHT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightRightButtonClick();}, this);
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
}

void Controls::rightUpButtonClick()
{
    Serial.println("rightUpButtonClick");
}

void Controls::rightDownButtonClick()
{
    Serial.println("rightDownButtonClick");
}

void Controls::rightRightButtonClick()
{
    Serial.println("rightRightButtonClick");
}