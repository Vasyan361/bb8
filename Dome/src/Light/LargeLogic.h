#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LargeLogic
{
    public:
        void init();
        void topWhite();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(4, LARGE_LOGIC_PIN, NEO_GRB + NEO_KHZ800);
        int fadeState = 0;
        int fadeA = 0;
        int fadeB = 0;
        uint32_t randomTimer;
};
