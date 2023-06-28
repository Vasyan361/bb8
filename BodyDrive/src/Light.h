#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Light
{
    public:
        void init();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(13, LIGHT_PIN, NEO_GRB + NEO_KHZ800);
};
