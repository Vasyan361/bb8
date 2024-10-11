#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Holoprojector
{
    public:
        void init();
        void disable();
        void pulse();
        void cycle();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, HOLOPROJECTOR_PIN, NEO_GRB + NEO_KHZ800);
        int pulseState = 0;
        int cycleState = 0;
        int red = 0;
        int green = 0;
        int blue = 0;
};
