#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class SmallLogic
{
    public:
        void init();
        void low();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(2, SMALL_LOGIC_PIN, NEO_GRB + NEO_KHZ800);
        int fadeState = 0;
        int red = 0;
        int green = 0;
        int blue = 0;
        uint32_t randomTimer;
};
