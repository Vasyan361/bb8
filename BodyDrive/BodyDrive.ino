#include <Arduino.h>
#include "src/Receivers/BodyReceiver.h"
#include "src/Receivers/ImuReceiver.h"
#include "src/Inputs.h"
#include "src/BodyMovement.h"
#include "src/DomeMovement.h"
#include "src/Calibration.h"
#include "src/Sounds.h"
 
BodyReceiver bodyReceiver;
ImuReceiver imuReceiver;
Inputs inputs;

BodyMovement bodyMovement;
DomeMovement domeMovement;

Calibration calibration;

Sounds sounds;

uint32_t timer;

// EncButton2<EB_ENC> enc(INPUT, 20, 21);

void setup() {
    Serial.begin(115200);

    bodyReceiver.init();
    imuReceiver.init();

    calibration.init(&bodyReceiver, &imuReceiver, &inputs);
    
    domeMovement.init(&bodyReceiver, &imuReceiver, &calibration);
    bodyMovement.init(&bodyReceiver, &imuReceiver, &inputs, &calibration);
    
    

    sounds.init(&bodyReceiver);


    // leftServo.attach(4);
    // rightServo.attach(5);
}

void loop() {
    bodyReceiver.receiveData();
    imuReceiver.receiveData();

    calibration.checkCalibration();

    if (millis()- timer >= 20)
    {
        bodyMovement.run();
        domeMovement.run();
    }

    

    sounds.playSound();

    // domeMovement.moveServo(bodyData.TopLeftXJoystick, bodyData.TopLeftYJoystick);

    // Serial.println(analogRead(A1));
    // delay(250);

    // enc.tick();
    // if (enc.turn()) {
    //     Serial.println("turn");

    //     // можно опросить ещё:
    //     Serial.println(enc.counter);  // вывести счётчик
    //     //Serial.println(enc.fast());   // проверить быстрый поворот
    //     Serial.println(enc.dir()); // направление поворота
    // }
}