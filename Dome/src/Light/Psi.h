#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Psi
{
    public:
        void init();
        void low();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, PSI_PIN, NEO_GRB + NEO_KHZ800);
        int state = 0;
        int pointer = 0;
        int randomPointer = 0;
        uint32_t timer;
        int randomInterval = 0;
};
