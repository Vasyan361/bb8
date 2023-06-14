#include <Arduino.h>
// 
// 
// #include <EncButton2.h>
// #include "src/DomeMovement.h"
#include "src/Receivers/BodyReceiver.h"
#include "src/Receivers/ImuReceiver.h"
#include "src/Sounds.h"
 
BodyReceiver bodyReceiver;
ImuReceiver imuReceiver;

Sounds sounds;

// DomeMovement domeMovement;


// EncButton2<EB_ENC> enc(INPUT, 20, 21);

void setup() {
    Serial.begin(115200);

    bodyReceiver.init();
    imuReceiver.init();
    sounds.init(&bodyReceiver);
    
    
    pinMode(29, OUTPUT);
    pinMode(33, OUTPUT);

    // digitalWrite(29, HIGH);
    // digitalWrite(33, HIGH);


    // leftServo.attach(4);
    // rightServo.attach(5);

    // domeMovement.init();
}

void loop() {
    bodyReceiver.receiveData();
    imuReceiver.receiveData();

    sounds.playSound();

    // domeMovement.moveServo(bodyData.TopLeftXJoystick, bodyData.TopLeftYJoystick);

    // delay(250);

    // Serial.println(analogRead(A0));
    // delay(250);

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