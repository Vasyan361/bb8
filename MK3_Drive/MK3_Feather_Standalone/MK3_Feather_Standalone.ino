   // ===================================================================================================================================================================================================== 
  //                         Joe's Drive  - Remote "MK3"  - Updated 4/11
  //
  //             ***         You are free to use, and share this code as long as it is not sold. There is no warranty, guarantee, or other tomfoolery. 
  //                         This entire project was masterminded by an average Joe, your mileage may vary. 
  // ===================================================================================================================================================================================================== 
  //                            Written by Joe Latiola - https://www.facebook.com/groups/JoesDrive/
  //
  //                            You will need libraries: Modified Low PowerLab: https://travis-ci.org/LowPowerLab/RFM69  
  //                                                     EasyTransfer: https://github.com/madsci1016/Arduino-EasyTransfer
  //                                                     
  //
  // ===================================================================================================================================================================================================== 
  // =====================================================================================================================================================================================================
   
  /*
   * 
   * 
   * 
   *        Find file: RFM69.h
   *        Find: #define RF69_CSMA_LIMIT_MS 1000
   *        Change to: #define RF69_CSMA_LIMIT_MS 100
   * 
   * 
   * 
   * 
   */ 


  
  #define dataDelay 5
  #define sendDelay 45
  
  #include "Arduino.h"
  #include <EasyTransfer.h>
  #include <esp_now.h>
  #include <WiFi.h>

  EasyTransfer SendRemote;
  // EasyTransfer SendBody;

  
  unsigned long lastLoop, lastRec, lastSent;

  typedef struct RECEIVE_DATA_STRUCTURE_REMOTE{
        int16_t Joy1Y=256; //main drive
        int16_t Joy1X=256; //tilt / steer
        int16_t Joy2Y=256; //head tilt
        int16_t Joy2X=256; //head spin
        int16_t Joy3X=256; //spin Flywheel
        int16_t Joy4X=256;
        int16_t ServoMode; //Select on left joystick
        int16_t lBut1=1; //left 1
        int16_t lBut2=1; //left 2
        int16_t lBut3; //left3
        int16_t Fwd; //Select on right joystick = rJoySelect
        int16_t Speed;
        int16_t rBut2; //right 2
        int16_t rBut3=1; //right 3
        int16_t motorEnable=1; //toggle on top
        int16_t CalibID;
        int16_t wireless=1;
  }recRemoteData; 
  recRemoteData recFromRemote;

  bool Send;   


  typedef struct RECEIVE_DATA_STRUCTURE_DRIVE{
        int16_t PSI;
        byte ledStatus;
        float bodyBatt;
        //float domeBatt;
        
  }recBodyData;
  recBodyData recFromBody;

  typedef struct RECEIVE_DATA_STRUCTURE_DOME{
 
        float domeBatt;
        
  }recDomeData;
  recDomeData recFromDome;


  
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial2.begin(57600);

    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        return;
    }

    SendRemote.begin(details(recFromRemote), &Serial2);
  // SendBody.begin(details(recFromBody), &Serial2);

    esp_now_register_recv_cb(OnDataReceive);
  }

  void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
   
    if(millis() - lastLoop >= 2){
      lastLoop = millis();
      memcpy(&recFromRemote, incomingData, sizeof(recFromRemote));
      SendRemote.sendData();
      // Serial.print("Bytes received: ");
      // Serial.println(len);
    } 
    // Serial.print("Bytes received: ");
    // Serial.println(len);
    // Serial.print("Joy2X: "); Serial.println(recFromRemote.Joy2X);
    Serial.print(recFromRemote.Joy1X); Serial.print(", ");
    Serial.print(recFromRemote.Joy1Y); Serial.print(", ");
    Serial.print(recFromRemote.Joy2X); Serial.print(", ");
    Serial.print(recFromRemote.Joy2Y); Serial.print(", ");
    Serial.print(recFromRemote.Joy3X); Serial.print(", ");
    Serial.print(recFromRemote.Joy4X); Serial.print(", ");
    Serial.print(recFromRemote.ServoMode); Serial.print(", ");
    Serial.print(recFromRemote.lBut1); Serial.print(", ");
    Serial.print(recFromRemote.lBut2); Serial.print(", ");
    Serial.print(recFromRemote.lBut3); Serial.print(", ");
    Serial.print(recFromRemote.Fwd); Serial.print(", ");
    Serial.print(recFromRemote.Speed); Serial.print(", ");
    Serial.print(recFromRemote.rBut2); Serial.print(", ");
    Serial.print(recFromRemote.rBut3); Serial.print(", ");
    Serial.print(recFromRemote.motorEnable); Serial.print(", ");
    Serial.print(recFromRemote.CalibID); Serial.print(", ");
    Serial.println(recFromRemote.wireless);
  }
  
  void loop() {
    // if(millis() - lastLoop >= 2){
    //   lastLoop = millis();
    //   // recRemote();
    // } 
     
    // if(millis() - lastSent >= 80){
    //   recBody();
    // }


  
  }  
  
  
  
  

