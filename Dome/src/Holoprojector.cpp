#include "Holoprojector.h"

void Holoprojector::init()
{
    Holoprojector::pixel.begin();
}

void Holoprojector::dissable()
{
    Holoprojector::pixel.clear();
    Holoprojector::pixel.setPixelColor(0, Holoprojector::pixel.Color(0, 0, 0));
    Holoprojector::pixel.show();
}