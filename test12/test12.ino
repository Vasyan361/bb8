#include <GyverMotor.h>

GMotor motor(DRIVER2WIRE, 44, 46);


void setup() {
    motor.setMode(AUTO);
}

void loop() {
  motor.setSpeed(100);
  
}


  