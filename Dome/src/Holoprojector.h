#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Holoprojector
{
    public:
        void init();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, HOLOPROJECTOR_PIN, NEO_GRB + NEO_KHZ800);
};
