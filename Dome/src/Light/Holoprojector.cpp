#include "Holoprojector.h"

void Holoprojector::init()
{
    Holoprojector::pixel.begin();
}

void Holoprojector::disable()
{
    Holoprojector::pixel.clear();
    Holoprojector::pixel.setPixelColor(0, Holoprojector::pixel.Color(0, 0, 0));
    Holoprojector::pixel.show();
}

void Holoprojector::pulse()
{
    if(Holoprojector::pulseState == 0 && Holoprojector::blue <= 100) {
        Holoprojector::blue++;
    }
    
    if(Holoprojector::blue >= 100) {
        Holoprojector::pulseState = 1;
    }
  
    if(Holoprojector::pulseState == 1 && Holoprojector::blue >= 10){
      Holoprojector::blue--;
    }
    
    if(Holoprojector::blue <= 10) {
        Holoprojector::pulseState = 0;
    }
    
    Holoprojector::pixel.setPixelColor(0, Holoprojector::pixel.Color(0, 0, Holoprojector::blue));
    Holoprojector::pixel.show();
}

void Holoprojector::cycle()
{
    switch (Holoprojector::cycleState)
    {
    case 0:
        Holoprojector::red = 0;
        Holoprojector::green = 0;
        Holoprojector::blue = 0;
        Holoprojector::cycleState = 1;
        break;
    case 1:
        if(Holoprojector::red <= 250) {
            Holoprojector::red += 3;
        } else {
            Holoprojector::cycleState = 2;
        }
        break;
    case 2:
        if(Holoprojector::red >= 10) {
            Holoprojector::red -= 3;
        } else {
            Holoprojector::cycleState = 3;
        }
        break;
    case 3:
        if(Holoprojector::green <= 250) {
            Holoprojector::green += 3;
        } else {
            Holoprojector::cycleState = 4;
        }
        break;
    case 4:
        if(Holoprojector::green >= 10) {
            Holoprojector::green -= 3;
        } else {
            Holoprojector::cycleState = 5;
        }
        break;
    case 5:
        if(Holoprojector::blue <= 250) {
            Holoprojector::blue += 3;
        } else {
            Holoprojector::cycleState = 6;
        }
        break;
    case 6:
        if(Holoprojector::blue >= 10) {
            Holoprojector::blue -= 3;
        } else {
            Holoprojector::cycleState = 7;
        }
        break;
    case 7:
        if(Holoprojector::red <= 250) {
            Holoprojector::red += 3;
        } else if(Holoprojector::green <= 250) {
            Holoprojector::green += 3;
        } else if(Holoprojector::blue <= 250) {
            Holoprojector::blue += 3;
        } else {
            Holoprojector::cycleState = 8;
        }
        break;
    case 8:
        if(Holoprojector::red >= 10) {
            Holoprojector::red -= 3;
        } else if(Holoprojector::green >= 10) {
            Holoprojector::green -= 3;
        } else if(Holoprojector::blue >= 10) {
            Holoprojector::blue -= 3;
        } else {
            Holoprojector::cycleState = 1;
        }
        break;
    
    default:
        break;
    }
  
    Holoprojector::pixel.setPixelColor(0, Holoprojector::pixel.Color(Holoprojector::red, Holoprojector::green, Holoprojector::blue));
    Holoprojector::pixel.show();
}