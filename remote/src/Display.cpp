#include "Display.h"

void Display::init()
{
    display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        for(;;); // Don't proceed, loop forever
    }

    prepareForPrint();

    Display::display.println(F("====================="));
    Display::display.println(F("     Joe's Drive"));
    Display::display.println(F("====================="));

    Display::display.display();

    Serial.println("Ready");

    delay(1000);
}

void Display::setPointer(int pointer)
{
    Display::pointer = pointer;
}

void Display::prepareForPrint()
{
    Display::display.clearDisplay();
    Display::display.setCursor(0,0); 

    Display::display.setTextSize(1);
    Display::display.setTextColor(SSD1306_WHITE);
}

void Display::printPointer()
{
    Display::printPointer(0);
}

void Display::printPointer(int alignment)
{
    Display::display.setCursor(0, 8 * (Display::pointer + alignment));
    Display::display.print(">");
}

void Display::infoScreen(int speed, int direction, float bodyBattery, float domeBattery)
{
    Display::prepareForPrint();

    // TODO:: реализовать логику
    Display::display.print(Display::speedNameMap[speed]); Display::display.println(Display::directionNameMap[direction]);
    Display::display.println(F(""));
    Display::display.print("Body: ");
    if (bodyBattery > 0) {
        Display::display.print(bodyBattery); Display::display.println("V");
    } else {
        Display::display.println("dissconnected");
    }

    Display::display.println(F(""));
    Display::display.print("Dome: ");
    if (domeBattery > 0) {
        Display::display.print(domeBattery); Display::display.println("V");
    } else {
        Display::display.println("dissconnected");
    }

    Display::display.display();
}

void Display::menuScreen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "      Main meny\n"
        "=====================\n"
        " Reverse Dome\n"
        " Dome Config\n"
        " Body Config\n"
        " Joystick calibration\n"
    ));

    Display::printPointer(2);

    Display::display.display();
}

void Display::domeReverseScreen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        " Reverse Dome\n"
    ));

    Display::display.display();
}

void Display::domeConfigScreen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        " Dome Config\n"
    ));

    Display::display.display();
}

void Display::bodyConfigScreen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Adjust dome tilt\n"
        "until the dome is\n"
        "centered front to back.\n"
        "\n"
        "Then press 'Ok"
    ));

    Display::display.display();
}

void Display::joystickConfigScreen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "Joystick calibration\n"
        "   select joystick\n"
        "=====================\n"
        " Top left\n"
        " Top right\n"
        " Bottom left\n"
        " Bottom right\n"
    ));

    Display::printPointer(3);

    Display::display.display();
}

void Display::joystickCalibrationStep1Screen(char *joystickName, int valX, int valY)
{
    Display::prepareForPrint();

    Display::display.println(F("  Center calibration"));
    Display::display.println(joystickName);
    Display::display.print(F(
        "=====================\n"
        "  Release joystick\n"
    ));
    Display::display.print(F("X center: ")); Display::display.println(valX);
    Display::display.print(F("Y center: ")); Display::display.println(valY);
    Display::display.print(F(
        "\n"
        "Press OK to save\n"
    ));

    Display::display.display();
}
void Display::joystickCalibrationStep2Screen(char *joystickName, int minX, int maxX, int minY, int maxY)
{
    Display::prepareForPrint();

    Display::display.println(F("  min/max calibration"));
    Display::display.println(joystickName);
    Display::display.print(F(
        "=====================\n"
        "  Rotate joystick\n"
    ));
    Display::display.print(F("X min:")); Display::display.print(minX); Display::display.print(F(" X max:")); Display::display.println(maxX);
    Display::display.print(F("Y min:")); Display::display.print(minY); Display::display.print(F(" Y max:")); Display::display.println(maxY);
    Display::display.print(F(
        "\n"
        "Press OK to save\n"
    ));

    Display::display.display();
}

void Display::joystickCalibrationStep3Screen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "Config saved!!\n"
        "=====================\n"
    ));

    Display::display.display();
}

void Display::bodyConfigStep1Screen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Dome tilt offset\n"
        "and pitch offset\n"
        "saved to eeprom\n"
        "\n"
        "Press 'Ok"
    ));

    Display::display.display();
}

void Display::bodyConfigStep2Screen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Adjust Side to Side\n"
        "until BB-8\n"
        "is straight.\n"
        "\n"
        "Then press 'Ok"
    ));

    Display::display.display();
}

void Display::bodyConfigStep3Screen()
{
    Display::prepareForPrint();

    Display::display.print(F(
        "Body Configuration\n"
        "=====================\n"
        "Body Calibration\n"
        "Complete!\n"
        "\n"
        "Press 'Ok"
    ));

    Display::display.display();
}