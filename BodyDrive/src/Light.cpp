#include "Light.h"

void Light::init()
{
    Light::pixel.begin();
    Light::pixel.clear();

    Light::pixel.setPixelColor(0, Light::pixel.Color(0, 0, 255));
    Light::pixel.setPixelColor(1, Light::pixel.Color(255, 0, 0));
    Light::pixel.setPixelColor(2, Light::pixel.Color(0, 0, 255));
    Light::pixel.setPixelColor(3, Light::pixel.Color(255, 0, 0));
    Light::pixel.setPixelColor(4, Light::pixel.Color(255, 0, 0));
    Light::pixel.setPixelColor(5, Light::pixel.Color(255, 0, 0));
    Light::pixel.setPixelColor(6, Light::pixel.Color(255, 233,0));
    Light::pixel.setPixelColor(7, Light::pixel.Color(255, 0,0));
    Light::pixel.setPixelColor(8, Light::pixel.Color(0, 0, 255));
    Light::pixel.setPixelColor(9, Light::pixel.Color(0, 0, 255));
    Light::pixel.setPixelColor(10, Light::pixel.Color(0, 0, 255));
    Light::pixel.setPixelColor(11, Light::pixel.Color(0, 0, 255));
    Light::pixel.setPixelColor(12, Light::pixel.Color(0, 0, 255));
    
    Light::pixel.show();
}