#include "LargeLogic.h"

void LargeLogic::init()
{
    LargeLogic::pixel.begin();
}

void LargeLogic::topWhite()
{
    LargeLogic::pixel.clear();

    for (int i = 0; i < 2; i++) {
        LargeLogic::pixel.setPixelColor(i, LargeLogic::pixel.Color(47, 49, 50));
    }

    LargeLogic::pixel.show();
}

void LargeLogic::fade()
{
    


    switch (LargeLogic::fadeState)
    {
    case 0:
        LargeLogic::fadeA++;
        if (LargeLogic::fadeB > 0) {
            LargeLogic::fadeB--;
        }
        break;
    case 1:
        LargeLogic::fadeA--;
        LargeLogic::fadeB++;
        break;
    default:
        break;
    }

    constrain(LargeLogic::fadeA, 0, 50);
    constrain(LargeLogic::fadeB, 0, 50);

    if(LargeLogic::fadeA == 50){
        LargeLogic::fadeState = 1;
    } else if (LargeLogic::fadeA == 0){
        LargeLogic::fadeState = 0;
    }

    LargeLogic::pixel.setPixelColor(0, LargeLogic::pixel.Color(LargeLogic::fadeA, LargeLogic::fadeA, LargeLogic::fadeA)); 
    LargeLogic::pixel.setPixelColor(1, LargeLogic::pixel.Color(LargeLogic::fadeA, LargeLogic::fadeA, LargeLogic::fadeA)); 
    LargeLogic::pixel.setPixelColor(2, LargeLogic::pixel.Color(LargeLogic::fadeB, LargeLogic::fadeB, LargeLogic::fadeB)); 
    LargeLogic::pixel.setPixelColor(3, LargeLogic::pixel.Color(LargeLogic::fadeB, LargeLogic::fadeB, LargeLogic::fadeB)); 
    LargeLogic::pixel.show();

    
}

void LargeLogic::randomBlink()
{
    if(millis() - LargeLogic::randomTimer > 300) {
      LargeLogic::randomTimer = millis();

      LargeLogic::pixel.setPixelColor(random(0, 6), LargeLogic::pixel.Color(random(0, 255),random(0, 255),random(0, 255))); 
      LargeLogic::pixel.show();
    }
}