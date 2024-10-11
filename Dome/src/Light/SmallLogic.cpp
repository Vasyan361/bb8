#include "SmallLogic.h"

void SmallLogic::init()
{
    SmallLogic::pixel.begin();
}

void SmallLogic::low()
{
    SmallLogic::pixel.clear();

    for (int i = 0; i < 2; i++) {
        SmallLogic::pixel.setPixelColor(i, SmallLogic::pixel.Color(23, 67, 96));
    }

    SmallLogic::pixel.show();
}

void SmallLogic::fade()
{
    switch (SmallLogic::fadeState)
    {
    case 0:
        if(SmallLogic::red < 24) {
            SmallLogic::red++;
            SmallLogic::green = map(SmallLogic::red, 0, 23, 0, 67);
            SmallLogic::blue = map(SmallLogic::red, 0, 23, 0, 96);
        } else {
            SmallLogic::fadeState = 1;
        }
        break;
    case 1:
        if(SmallLogic::red > 0) {
            SmallLogic::red--;
            SmallLogic::green = map(SmallLogic::red, 0, 23, 0, 67);
            SmallLogic::blue = map(SmallLogic::red, 0, 23, 0, 96);
        } else {
            SmallLogic::fadeState = 0;
        }
        break;
    
    default:
        break;
    }

    for (int i = 0; i < 2; i++)
    {
        SmallLogic::pixel.setPixelColor(i, SmallLogic::pixel.Color(SmallLogic::red, SmallLogic::green, SmallLogic::blue));
    }

    SmallLogic::pixel.show();
}

void SmallLogic::randomBlink()
{
    if(millis() - SmallLogic::randomTimer > 300) {
      SmallLogic::randomTimer = millis();

      SmallLogic::pixel.setPixelColor(random(0, 2), SmallLogic::pixel.Color(random(0, 255),random(0, 255),random(0, 255))); 
      SmallLogic::pixel.show();
    }
}