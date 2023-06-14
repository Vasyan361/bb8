#include <Arduino.h>
// 
// #include <DFRobotDFPlayerMini.h>
// #include <EncButton2.h>
// #include "src/DomeMovement.h"
#include "src/Receivers/BodyReceiver.h"
#include "src/Receivers/ImuReceiver.h"
 
BodyReceiver bodyReceiver;
ImuReceiver imuReceiver;



// DFRobotDFPlayerMini myDFPlayer;


// DomeMovement domeMovement;


// EncButton2<EB_ENC> enc(INPUT, 20, 21);

void setup() {
    Serial.begin(115200);

    bodyReceiver.init();
    imuReceiver.init();
    // Serial3.begin(9600);
    
    
    // Serial.println("Ready");
    pinMode(29, OUTPUT);
    pinMode(33, OUTPUT);

    digitalWrite(29, HIGH);
    digitalWrite(33, HIGH);


    // if (!myDFPlayer.begin(Serial3)) {  //Use softwareSerial to communicate with mp3.
    //     Serial.println(F("Unable to begin:"));
    //     Serial.println(F("1.Please recheck the connection!"));
    //     Serial.println(F("2.Please insert the SD card!"));
    //     while(true){
    //     delay(0); // Code to compatible with ESP8266 watch dog.
    //     }
    // }
    // Serial.println(F("DFPlayer Mini online."));

    // myDFPlayer.setTimeOut(500);
    // myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    // myDFPlayer.playFolder(1, 1);

    // leftServo.attach(4);
    // rightServo.attach(5);

    // domeMovement.init();
}

void loop() {
    bodyReceiver.receiveData();
    imuReceiver.receiveData();

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