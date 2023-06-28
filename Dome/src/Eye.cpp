#include "Eye.h"

void Eye::init()
{
    Eye::pixel.begin();
    Eye::pixel.setPixelColor(0, Eye::pixel.Color(0, 200, 0));
    Eye::pixel.show();
}

void Eye::low()
{
    for (int i = 1; i < 6; i++)
    {
        Eye::pixel.setPixelColor(i, Eye::pixel.Color(0, 0, 0));
        Eye::pixel.show();
    }
    
}

void Eye::fade()
{
    if (millis() - Eye::timer > 300)
    {
        Eye::timer = millis();
        switch (Eye::state)
        {
        case 0:
            Eye::pointer++;

            if (Eye::pointer > 5) {
                Eye::state = 1;
            } else {
                Eye::pixel.setPixelColor(Eye::pointer, Eye::pixel.Color(0, 200, 0));
            }
            
            break;
        case 1:
            Eye::pointer--;

            if (Eye::pointer <= 0) {
                Eye::state = 0;
            } else {
                Eye::pixel.setPixelColor(Eye::pointer, Eye::pixel.Color(0, 0, 0));
            }
            break;
        
        default:
            break;
        }

        Eye::pixel.show();
    }
}

void Eye::randomBlink()
{
    if (millis() - Eye::timer > 100)
    {
        Eye::timer = millis();

        if (Eye::pointer <= 0) {
            Eye::randomPointer = random(1, 5);
        }

        switch (Eye::state)
        {
        case 0:
            Eye::pointer++;

            if (Eye::pointer > Eye::randomPointer) {
                Eye::state = 1;
            } else {
                Eye::pixel.setPixelColor(Eye::pointer, Eye::pixel.Color(0, 200, 0));
            }
            
            break;
        case 1:
            Eye::pointer--;

            if (Eye::pointer <= 0) {
                Eye::state = 0;
            } else {
                Eye::pixel.setPixelColor(Eye::pointer, Eye::pixel.Color(0, 0, 0));
            }
            break;
        
        default:
            break;
        }

        Eye::pixel.show();
    }
    
}