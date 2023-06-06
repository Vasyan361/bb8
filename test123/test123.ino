#include <EasyTransfer.h>

//create object
EasyTransfer ET; 

struct SEND_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int16_t Joy1Y=256; //main drive
  int16_t Joy1X=256; //tilt / steer
  int16_t Joy2Y=256; //head tilt
  int16_t Joy2X=256; //head spin
  int16_t Joy3X=256; //spin Flywheel
  int16_t Joy4X=256;
  int16_t ServoMode=1; //Select on left joystick
  int16_t lBut1=1; //left 1
  int16_t lBut2=1; //left 2
  int16_t lBut3=1; //left3
  int16_t Fwd=1; //Select on right joystick = rJoySelect
  int16_t Speed=1;
  int16_t rBut2=1; //right 2
  int16_t rBut3=1; //right 3
  int16_t motorEnable=1; //toggle on top
  int16_t CalibID=1;
  int16_t wireless=1;
};

//give a name to the group of data
SEND_DATA_STRUCTURE mydata;

void setup(){
  Serial2.begin(57600);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
  ET.begin(details(mydata), &Serial2);
  
  randomSeed(42);
  
}

void loop(){
  //this is how you access the variables. [name of the group].[variable name]
  mydata.Joy1Y = random(512);
  mydata.Joy1X = random(512);
  //send the data
  ET.sendData();
  
  delay(1000);
}