#include <Arduino.h>
// #include <EasyTransfer.h>
// #include <GyverMotor2.h>
#include <DFRobotDFPlayerMini.h>
// #include <EncButton2.h>
// #include "src/DomeMovement.h"

// typedef struct BodyReceiveData {
//     int16_t TopLeftXJoystick;
//     int16_t TopLeftYJoystick;
//     int16_t TopRightXJoystick;
//     int16_t TopRightYJoystick;

//     int16_t BottomLeftXJoystick;
//     int16_t BottomLeftYJoystick;
//     int16_t BottomRightXJoystick;
//     int16_t BottomRightYJoystick;
// } BodyReceiveData;
 
// BodyReceiveData bodyData;

// EasyTransfer ReceiceBody;

// struct SEND_DATA_STRUCTURE{
//   //put your variable definitions here for the data you want to send
//   //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
//   int16_t blinks;
//   int16_t pause;
// };

// //give a name to the group of data
// SEND_DATA_STRUCTURE mydata;

// EasyTransfer ET;

// typedef struct ImuReceiveData{
//     float imuLoop;
//     float pitch;
//     float roll;
//   } ImuReceiveData;

// ImuReceiveData ImuData;

// EasyTransfer ReceiveImu;

// GMotor2<DRIVER2WIRE> sideToSideMotor(6, 7);
// GMotor2<DRIVER2WIRE> flywheelSpinMotor(8, 9);
// GMotor2<DRIVER2WIRE> domeMotor(10, 11);
// GMotor2<DRIVER2WIRE> mainDriveMotor(12, 13);

DFRobotDFPlayerMini myDFPlayer;


// DomeMovement domeMovement;


// EncButton2<EB_ENC> enc(INPUT, 20, 21);

void setup() {
    Serial.begin(115200);
    Serial1.begin(9600);
    Serial2.begin(115200);
    Serial3.begin(9600);
    
    // ReceiceBody.begin(details(bodyData), &Serial1);
    // ReceiveImu.begin(details(ImuData), &Serial2);

    // Serial.println("Ready");
    // pinMode(29, OUTPUT);
    // pinMode(33, OUTPUT);

    // digitalWrite(29, HIGH);
    // digitalWrite(33, HIGH);

    // sideToSideMotor.setSpeed(130);
    // flywheelSpinMotor.setSpeed(130);
    // domeMotor.setSpeed(130);
    // mainDriveMotor.setSpeed(130);

    if (!myDFPlayer.begin(Serial3)) {  //Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while(true){
        delay(0); // Code to compatible with ESP8266 watch dog.
        }
    }
    // Serial.println(F("DFPlayer Mini online."));

  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
    // ET.begin(details(mydata), &Serial2);


    
    myDFPlayer.setTimeOut(500);
    myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    myDFPlayer.playFolder(1, 1);

    // leftServo.attach(4);
    // rightServo.attach(5);

    // domeMovement.init();
}

void loop() {
    // if(ReceiceBody.receiveData()){ //== recFromRemote){
    //     // Serial.print("TopLeftXJoystick: "); Serial.println(bodyData.TopLeftXJoystick);
    //     // Serial.print("TopLeftYJoystick: "); Serial.println(bodyData.TopLeftYJoystick);
    //     // Serial.print("TopRightXJoystick: "); Serial.println(bodyData.TopRightXJoystick);
    //     // Serial.print("TopRightYJoystick: "); Serial.println(bodyData.TopRightYJoystick);

    //     // Serial.print("BottomLeftXJoystick: "); Serial.println(bodyData.BottomLeftXJoystick);
    //     // Serial.print("BottomRightXJoystick: "); Serial.println(bodyData.BottomRightXJoystick);

    //     // Serial.println("");
    // }


    // if(ReceiveImu.receiveData()){
        // Serial.print("ImuData.imuLoop"); Serial.println(ImuData.imuLoop);
        // Serial.print("ImuData.pitch"); Serial.println(ImuData.pitch);
        // Serial.print("ImuData.roll"); Serial.println(ImuData.roll);

        // Serial.println("");
    // }

    // if(ET.receiveData()){
        // Serial.print("ImuData.imuLoop"); Serial.println(ImuData.imuLoop);
        // Serial.print("ImuData.pitch"); Serial.println(ImuData.pitch);
        // Serial.print("ImuData.roll"); Serial.println(ImuData.roll);
        // Serial.print("ImuData.blinks"); Serial.println(mydata.blinks);
        // Serial.print("ImuData.pause"); Serial.println(mydata.pause);

        // Serial.println("");
    // }

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