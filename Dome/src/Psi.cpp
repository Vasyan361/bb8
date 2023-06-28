#include "Psi.h"

void Psi::init()
{
    Psi::pixel.begin();
    
}

void Psi::low()
{
    Psi::pixel.setPixelColor(0, Psi::pixel.Color(60, 60, 60));
    Psi::pixel.show();
}

void Psi::fade()
{
    if (millis() - Psi::timer > 500)
    {
        Psi::pixel.setPixelColor(0, Psi::pixel.Color(60, 60, 60));
    }

    if (millis() - Psi::timer > 1000)
    {
        Psi::timer = millis();

        Psi::pixel.setPixelColor(0, Psi::pixel.Color(200, 200, 200));
    }

    Psi::pixel.show();
}

void Psi::randomBlink()
{
    if (millis() - Psi::timer > Psi::randomInterval)
    {
        Psi::timer = millis();
        Psi::randomInterval = random(100,300);

        Psi::pixel.setPixelColor(0, Psi::pixel.Color(random(0, 255),random(0, 255),random(0, 255)));
    }

    Psi::pixel.show();
}