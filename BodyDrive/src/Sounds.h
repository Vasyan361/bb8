#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "../Config.h"

class Sounds
{
    public:
        void init();
        void playSound();
    private:
        DFRobotDFPlayerMini myDFPlayer;
};