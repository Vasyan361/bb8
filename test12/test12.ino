// #include <EasyTransfer.h>

// //create object
// EasyTransfer ET; 

// struct RECEIVE_DATA_STRUCTURE{
//   //put your variable definitions here for the data you want to receive
//   //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
//   int16_t Joy1Y=256; //main drive
//   int16_t Joy1X=256; //tilt / steer
//   int16_t Joy2Y=256; //head tilt
//   int16_t Joy2X=256; //head spin
//   int16_t Joy3X=256; //spin Flywheel
//   int16_t Joy4X=256;
//   int16_t ServoMode; //Select on left joystick
//   int16_t lBut1=1; //left 1
//   int16_t lBut2=1; //left 2
//   int16_t lBut3; //left3
//   int16_t Fwd; //Select on right joystick = rJoySelect
//   int16_t Speed;
//   int16_t rBut2; //right 2
//   int16_t rBut3=1; //right 3
//   int16_t motorEnable=1; //toggle on top
//   int16_t CalibID;
//   int16_t wireless=1;
// };

// //give a name to the group of data
// RECEIVE_DATA_STRUCTURE mydata;

// void setup(){
//   Serial.begin(115200);
//   Serial1.begin(57600);
//   //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
//   ET.begin(details(mydata), &Serial1);
  
//   pinMode(13, OUTPUT);
  
// }

// void loop(){
//   //check and see if a data packet has come in. 
//   if(ET.receiveData()){
//     //this is how you access the variables. [name of the group].[variable name]
//     //since we have data, we will blink it out. 
//     // Serial.print(mydata.Joy1Y); Serial.print(", "); Serial.println(mydata.Joy1X);
//     // Serial.print("mydata.Joy1Y: "); Serial.println(mydata.Joy1Y);
//     // Serial.print("mydata.Joy1X: "); Serial.println(mydata.Joy1X);
//     Serial.print(mydata.Joy1X); Serial.print(", ");
//     Serial.print(mydata.Joy1Y); Serial.print(", ");
//     Serial.print(mydata.Joy2X); Serial.print(", ");
//     Serial.print(mydata.Joy2Y); Serial.print(", ");
//     Serial.print(mydata.Joy3X); Serial.print(", ");
//     Serial.print(mydata.Joy4X); Serial.print(", ");
//     Serial.print(mydata.ServoMode); Serial.print(", ");
//     Serial.print(mydata.lBut1); Serial.print(", ");
//     Serial.print(mydata.lBut2); Serial.print(", ");
//     Serial.print(mydata.lBut3); Serial.print(", ");
//     Serial.print(mydata.Fwd); Serial.print(", ");
//     Serial.print(mydata.Speed); Serial.print(", ");
//     Serial.print(mydata.rBut2); Serial.print(", ");
//     Serial.print(mydata.rBut3); Serial.print(", ");
//     Serial.print(mydata.motorEnable); Serial.print(", ");
//     Serial.print(mydata.CalibID); Serial.print(", ");
//     Serial.println(mydata.wireless);
//   }
  
//   //you should make this delay shorter then your transmit delay or else messages could be lost
// }


#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>






DFRobotDFPlayerMini myDFPlayer;



void setup() {
    Serial.begin(115200);
    Serial1.begin(9600);
    Serial2.begin(115200);
    Serial3.begin(9600);
    

    if (!myDFPlayer.begin(Serial3)) {  //Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while(true){
        delay(0); // Code to compatible with ESP8266 watch dog.
        }
    }
    Serial.println(F("DFPlayer Mini online."));

    
    myDFPlayer.setTimeOut(500);
    myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    myDFPlayer.playFolder(1, 1);

}

void loop() {
 
}