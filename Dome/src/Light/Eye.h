#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Eye
{
    public:
        void init();
        void low();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(6, EYE_PIN, NEO_GRB + NEO_KHZ800);
        int state = 0;
        int pointer = 0;
        int randomPointer = 0;
        uint32_t timer;
};
