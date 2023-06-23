#include "Inputs.h"

int16_t Inputs::getSideToSiePotValue()
{
    
    return map(analogRead(SIDE_TO_SIDE_POT_PIN), 0, 1024, 135,-135);
}