#include "Menu.h"

void Menu::init(JoystickControl* joystickControl)
{
    Menu::joystickControl = joystickControl;
    Menu::display.init();
}

void Menu::navigate()
{
    Menu::display.setPointer(Menu::pointer);

    switch (Menu::mode)
    {
        case INFO_SCREEN: Menu::display.infoScreen(Menu::speed, Menu::direction, Menu::bodyBattery, Menu::domeBattery); break;
        case MENU_SCREEN: Menu::display.menuScreen(); break;
        case DOME_REVERSE_SCREEN: Menu::display.domeReverseScreen(); break;
        case DOME_CONFIG_SCREEN: Menu::display.domeConfigScreen(); break;
        case BODY_CONFIG_SCREEN: Menu::display.bodyConfigScreen(); break;
        case JOYSTICK_CONFIG_SCREN: Menu::display.joystickConfigScreen(); break;
        case JOYSTICK_CALIBRATION_STEP_1_SCREEN:
            Menu::display.joystickCalibrationStep1Screen(
                Menu::joystickControl->getSelectedJoystick()->getName(),
                Menu::joystickControl->getSelectedJoystick()->getXValue(),
                Menu::joystickControl->getSelectedJoystick()->getYValue()
            );
            break;
        case JOYSTICK_CALIBRATION_STEP_2_SCREEN:
            Menu::display.joystickCalibrationStep2Screen(
                Menu::joystickControl->getSelectedJoystick()->getName(),
                Menu::joystickControl->getSelectedJoystick()->calculateMinX(),
                Menu::joystickControl->getSelectedJoystick()->calculateMaxX(),
                Menu::joystickControl->getSelectedJoystick()->calculateMinY(),
                Menu::joystickControl->getSelectedJoystick()->calculateMaxY()
            );
            break;
        case JOYSTICK_CALIBRATION_STEP_3_SCREEN:
            Menu::display.joystickCalibrationStep3Screen();
            break;
        case BODY_CONFIG_STEP_1_SCREEN: Menu::display.bodyConfigStep1Screen(); break;
        case BODY_CONFIG_STEP_2_SCREEN: Menu::display.bodyConfigStep2Screen(); break;
        case BODY_CONFIG_STEP_3_SCREEN: Menu::display.bodyConfigStep3Screen(); break;
        default: break;
    }
}

void Menu::buttonOkClick()
{
    Menu::mode = Menu::nextModeMap[Menu::mode][Menu::pointer];
    
    if (Menu::mode > Menu::maxMode) {
        Menu::mode = 0;
    }

    Menu::modeAction();

    Menu::pointer = 0;   
}

void Menu::buttonUpClick()
{
    Menu::pointer--;
    if (Menu::pointer < 0) {
        Menu::pointer = Menu::maxPointerByMode[Menu::mode];
    }
}

void Menu::buttonDownClick()
{
    Menu::pointer++;
    if (Menu::pointer > Menu::maxPointerByMode[Menu::mode]) {
       Menu::pointer = 0;
    }
}

void Menu::buttonBackClick()
{
    Menu::mode = Menu::previousModeMap[Menu::mode];
}

void Menu::modeAction()
{
    switch (Menu::mode)
    {
        case JOYSTICK_CALIBRATION_STEP_1_SCREEN: Menu::joystickControl->setSelectedJoystick(Menu::pointer); break;
        case JOYSTICK_CALIBRATION_STEP_2_SCREEN: Menu::joystickControl->updateSelectedJoystickCenter(); break;
        case JOYSTICK_CALIBRATION_STEP_3_SCREEN:
            Menu::joystickControl->updateSelectedJoystickMinMax();
            Menu::joystickControl->saveJoystickConfig();
            break;
        case BODY_CONFIG_STEP_1_SCREEN: Menu::calibrationId = 3; break;
        case BODY_CONFIG_STEP_3_SCREEN: Menu::calibrationId = 4; break;
        default: break;
    }
}

void Menu::setSpeed(int speed)
{
    Menu::speed = speed;
}

void Menu::setDirection(int direction)
{
    Menu::direction = direction;
}

int Menu::getCalibrationId()
{
    return Menu::calibrationId;
}

void Menu::setBodyBattery(float bodyBattery)
{
    Menu::bodyBattery = bodyBattery;
}

void Menu::setDomeBattery(float domeBattery)
{
    Menu::domeBattery = domeBattery;
}