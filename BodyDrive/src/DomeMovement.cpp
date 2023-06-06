#include "DomeMovement.h"

#define DomeXEase 0.7          // Speed of side to side domemovement, higher == faster
#define DomeYEase 0.4          // Spead of front to back dome movement, higher == faster

void DomeMovement::init()
{
    DomeMovement::leftServo.attach(LEFT_SERVO_PIN);
    DomeMovement::rightServo.attach(RIGHT_SERVO_PIN);
}

void DomeMovement::moveServo(int x, int y)
{
    double Joy2XDirection = map(x, 0, 1023, -MAX_DOME_ANGLE_X, MAX_DOME_ANGLE_X);
    double Joy2YDirection = map(y, 0, 1023, -MAX_DOME_ANGLE_Y, MAX_DOME_ANGLE_Y);

    if(Joy2YDirection <= 1.7 && Joy2YDirection >= -1.7){  
       Joy2YDirection = 0;   
    }

    if(Joy2XDirection <= 1.7 && Joy2XDirection >= -1.7){  
       Joy2XDirection = 0;   
    }
      
    // if(Setpoint3 >= 2 || Setpoint3 <= -2){
      // Joy2YPitch = Joy2YDirection + pitch;
    // }else{
    //   Joy2YPitch = Joy2YDirection; - pitchOffset;
    // }

    double Joy2YPitch = Joy2YDirection;
    
    // double Joy2XEase = 0;
    // double Joy2YEase = 0;
    if((Joy2XDirection + DomeXEase) > Joy2XEase && (Joy2XDirection - DomeXEase) < Joy2XEase){
      Joy2XEase = Joy2XDirection;
    }else if(Joy2XEase > Joy2XDirection){
      Joy2XEase -= DomeXEase;
    }else if(Joy2XEase < Joy2XDirection){
      Joy2XEase += DomeXEase;
    }
    if((Joy2YPitch + DomeYEase) > Joy2YEase && (Joy2YPitch - DomeYEase) < Joy2YEase){
      Joy2YEase = Joy2YPitch;
    }else if(Joy2YEase > Joy2YPitch){
      Joy2YEase -= DomeYEase;
    }else if(Joy2YEase < Joy2YPitch){
      Joy2YEase += DomeYEase;
    }
    
    // double Joy2XEaseMap = Joy2XEase;
    // double Joy2YEaseMap = Joy2YEase;

    // int Joy2Ya = 0;
    // int Joy2XLowOffset = 0;
    // int Joy2XHighOffset = 0;
    if(Joy2YEaseMap< 0){
      Joy2Ya = map(Joy2YEaseMap, -20, 0, 70, 0);
      Joy2XLowOffset = map(Joy2Ya, 1, 70, -15, -50);
      Joy2XHighOffset = map(Joy2Ya, 1, 70, 30, 20);
    }else if(Joy2YEaseMap> 0){
      Joy2Ya = map(Joy2YEaseMap,0, 24, 0, -80); 
      Joy2XLowOffset = map(Joy2Ya, -1, -80, -15, 10);
      Joy2XHighOffset = map(Joy2Ya, -1, -80, 30, 90);
    }else{
      Joy2Ya = 0;
    }

    // int ServoLeft = 0;
    // int ServoRight = 0;
    // int Joy2XLowOffsetA = 0;
    // int Joy2XHighOffsetA = 0;
    
    if(Joy2XEaseMap> 0){
      Joy2XLowOffsetA = map(Joy2XEaseMap, 0, 18, 0, Joy2XLowOffset);
      Joy2XHighOffsetA = map(Joy2XEaseMap, 0, 18, 0, Joy2XHighOffset);
      ServoLeft = Joy2Ya + Joy2XHighOffsetA;
      ServoRight = Joy2Ya + Joy2XLowOffsetA;
     
    }else if(Joy2XEaseMap< 0){
      Joy2XLowOffsetA = map(Joy2XEaseMap, -18, 0, Joy2XLowOffset, 0);
      Joy2XHighOffsetA = map(Joy2XEaseMap, -18, 0, Joy2XHighOffset, 0);
      ServoRight = Joy2Ya + Joy2XHighOffsetA;
      ServoLeft = Joy2Ya + Joy2XLowOffsetA;
    }else{
      Joy2XHighOffsetA = 0;
      Joy2XLowOffsetA = 0; 
      ServoRight = Joy2Ya;
      ServoLeft = Joy2Ya;
    }
   
    // leftServo.write(constrain(map(ServoLeft, -90, 90, 0, 180),0, 180) +5, domeSpeed, false); 
    // rightServo.write(constrain(map(ServoRight,-90, 90, 180, 0), 0, 180), domeSpeed, false);

    
    // DomeMovement::leftServo.write(constrain(map(ServoLeft,  -90, 90, 0, 180), 0, 180));
    // DomeMovement::rightServo.write(constrain(map(ServoRight,  -90, 90, 0, 180), 0, 180));

    DomeMovement::leftServo.write(constrain(map(x,  0, 1023, 0, 180), 0, 180));
    DomeMovement::rightServo.write(constrain(map(y,  0, 1023, 0, 180), 0, 180));
}