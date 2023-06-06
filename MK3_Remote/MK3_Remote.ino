   // ===================================================================================================================================================================================================== 
  //                         Joe's Drive  - Remote "MK3"  - Updated 4/15
  //
  //             ***         You are free to use, and share this code as long as it is not sold. There is no warranty, guarantee, or other tomfoolery. 
  //                         This entire project was masterminded by an average Joe, your mileage may vary. 
  // ===================================================================================================================================================================================================== 
  //                            Written by Joe Latiola - https://www.facebook.com/groups/JoesDrive/
  //
  //                            You will need libraries: i2cdevlib: https://github.com/jrowberg/i2cdevlib
  //                                                     Modified Low PowerLab: https://travis-ci.org/LowPowerLab/RFM69  
  //                                                     EEPROM Extended: https://github.com/thijse/Arduino-EEPROMEx
  //                                                     SSD1306Ascii Text Only: https://github.com/greiman/SSD1306Ascii
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
  
  #define droidName     "BB-8"
  
  
  #define enablePIN     15
  #define lJoySelectPIN 1
  #define Joy2XPIN      34
  #define Joy2YPIN      35
  #define lBut1PIN      19
  #define lBut2PIN      18
  #define lBut3PIN      17
  #define rJoySelectPIN 3
  #define Joy1XPIN      36
  #define Joy1YPIN      39
  #define rBut1PIN      16
  #define rBut2PIN      4
  #define rBut3PIN      2    //   This is the only button / pin that must not change. 
  #define Joy3XPIN      33
  #define Joy4XPIN      32
  #define dataDelay     0
  #define sendDelay     20
  #define recDelay      2

  #define serialSound   //Uncomment this if you are using Serial3 for sounds in the body


  // #define debug

  
  #include <EEPROM.h>
  #include "Arduino.h"
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
  // #include "SSD1306AsciiWire.h"
  #define I2C_ADDRESS 0x3C
  // SSD1306AsciiWire oled;



  #define SCREEN_WIDTH 128 // OLED display width, in pixels
  #define SCREEN_HEIGHT 64 // OLED display height, in pixels

  #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
  #define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
  Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  
  // #include <RFM69.h>    //get it here: https://www.github.com/lowpowerlab/rfm69
  #include <SPI.h>
  
  //*********************************************************************************************
  // *********** IMPORTANT SETTINGS - YOU MUST CHANGE/CONFIGURE TO FIT YOUR HARDWARE ************
  //*********************************************************************************************
  #define NETWORKID       100  // The same on all nodes that talk to each other
  #define REMOTE_ADDRESS  1    // The unique identifier of this node
  #define BODY_ADDRESS    2    // The recipient of packets
  #define DOME_ADDRESS    3    // The recipient of packets
  #define DRIVE_ADDRESS   4
  
  //Match frequency to the hardware version of the radio on your Feather
  #define FREQUENCY     RF69_915MHZ
  #define IS_RFM69HCW   true // set to 'true' if you are using an RFM69HCW module
  
  //*********************************************************************************************
  #define SERIAL_BAUD   115200
  
  // for Feather 32u4 Radio
  #define RFM69_CS      8
  #define RFM69_IRQ     7
  #define RFM69_IRQN    4  // Pin 7 is IRQ 4!
  #define RFM69_RST     4
  
  // RFM69 radio = RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW, RFM69_IRQN);

  #include <esp_now.h>
  #include <WiFi.h>
 
  uint8_t bodyAddress[] = {0x40, 0x22, 0xD8, 0x03, 0xE2, 0x50};;

  #ifdef serialSound
    struct SEND_DATA_STRUCTURE{
          int16_t Joy1Y=256; //main drive
          int16_t Joy1X=256; //tilt / steer
          int16_t Joy2Y=256; //head tilt
          int16_t Joy2X=256; //head spin
          int16_t Joy3X=256; //spin Flywheel
          int16_t Joy4X=256;
          int16_t ServoMode; //Select on left joystick
          int16_t lBut1=0; //left 1
          int16_t lBut2=0; //left 2
          int16_t lBut3; //left3
          int16_t Fwd; //Select on right joystick = rJoySelect
          int16_t Speed;
          int16_t rBut2; //right 2
          int16_t rBut3=0; //right 3
          int16_t motorEnable=1; //toggle on top
          int16_t CalibID;
          int16_t wireless=1;
    
    }sendToBody;
  #else
    struct SEND_DATA_STRUCTURE{
        int Joy1Y=256; //main drive
        int Joy1X=256; //tilt / steer
        int Joy2Y=256; //head tilt
        int Joy2X=256; //head spin
        int Joy3X=256; //spin Flywheel
        int Joy4X=256;
        byte ServoMode; //Select on left joystick
        byte lBut1=1; //left 1
        byte lBut2=1; //left 2
        byte lBut3; //left3
        byte Fwd; //Select on right joystick = rJoySelect
        byte Speed;
        byte rBut2; //right 2
        byte rBut3=1; //right 3
        byte motorEnable=1; //toggle on top
        byte CalibID;
        byte wireless=1;
  
    }sendToBody;
    #endif
  byte packet[sizeof(sendToBody)];
  
  
  typedef struct RECEIVE_DATA_STRUCTURE_DOME{
        
        float bodyBatt;
        float domeBatt;
        
  }recDomeData;
  recDomeData recFromDome;

  typedef struct RECEIVE_DATA_STRUCTURE_BODY{

        int psi=0;
        byte button4 = 1;
        float bodyBatt;
        
  }recBodyData;
  recBodyData recFromBody;
  
  bool SEND;
  int Joy1X, Joy1Xa, Joy1Xb;
  int Joy1Y, Joy1Ya, Joy1Yb;
  int Joy2X, Joy2Xa, Joy2Xb;
  int Joy2Y, Joy2Ya, Joy2Yb;
  int Joy3X, Joy3Xa, Joy3Xb;
  int Joy4X, Joy4Xa, Joy4Xb;
  int Joy1XCenter, Joy1YCenter, Joy2XCenter, Joy2YCenter, Joy3XCenter, Joy4XCenter;
  int Joy1XLow=512, Joy1YLow=512, Joy2XLow=512, Joy2YLow=512, Joy3XLow=512, Joy4XLow=512;
  int Joy1XHigh=512, Joy1YHigh=512, Joy2XHigh=512, Joy2YHigh=512, Joy3XHigh=512, Joy4XHigh=512;
  int joyconfigX1, joyconfigY1, joyconfigX2, joyconfigY2, joyconfigX3, joyconfigX4;
  byte enable, bodyConfigStep, ServoMode, lBut1State, rBut1State;
  byte rJoySelect, domeSend;
  byte JoySelectState, ServoJoySelectState, dome180, DomeDirection;
  byte menuConfirm, Display, cursorMove, updateScreen = 1;
  byte casenum, lastcasenum = 1;
  byte start, wireless, bodyWireless;
  byte joyConfStep = 1;
  byte But1State, But2State, But1Sound, voiceSend, But2Sound, musicSend;
  int joyConfCountdown;
  byte waitTime = 5;
  String menuItems[] = {"Reverse Dome", "Dome Config", "Body Config", "Joystick Config"};
  
  String speedDisplay[] = {"Slow", "Medium", "Fast"};
  //int rectime[20];
  //byte rectimeloc;
  const int eepromSet = 890;
  int rBut1 = 1;
  float measuredvbat;
  unsigned long buttonTimer, menuTimeout, joyConfMillis, lastScreenUpdate, domeConfigTimeout; 
  unsigned long bodyConfigMillis, domeConnectivityMillis, lastrecdata = 1000; 
  unsigned long lastReading, lastLoopMillis, lastrecDataMillis, lastSend;
  unsigned long But1Millis, But2Millis;

  byte lJoySelect, lBut1=1, lBut2=1, lBut3, Fwd; 
  byte Speed, rBut2, rBut3=1, motorEnable=1, lBut1Timer, lBut2Timer, rBut3Timer;
  unsigned long lBut1Millis, lBut2Millis, rBut3Millis;

  byte startup = 1;
  
  void setup() {
    if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        for(;;); // Don't proceed, loop forever
    }

    prepareForPrint();
  
    oled.println(F("====================="));
    oled.println(F("      Joe's Drive       "));
    oled.println(F("====================="));
    oled.display();
    Serial.begin(115200);
  
    pinMode (lJoySelectPIN, INPUT_PULLUP); 
    pinMode (rJoySelectPIN, INPUT_PULLUP); 
    pinMode (lBut1PIN, INPUT_PULLUP); 
    pinMode (lBut2PIN, INPUT_PULLUP); 
    pinMode (lBut3PIN, INPUT_PULLUP); 
    pinMode (rBut1PIN, INPUT_PULLUP); 
    pinMode (rBut2PIN, INPUT_PULLUP);
    pinMode (enablePIN, INPUT_PULLUP);
  
    // Hard Reset the RFM module

    // Выбираем режим WiFi
    WiFi.mode(WIFI_STA);

    // Запускаем протокол ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Регистрируем отправку сообщения
    esp_now_register_send_cb(OnDataSent);
    
    // Указываем получателя
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, bodyAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Failed to add peer");
        return;
    }
    EEPROM.begin(256);

  
    // if(EEPROM.read(36) == eepromSet){
    //   Joy1XCenter = EEPROM.read(0);
    //   Joy1YCenter = EEPROM.read(2);
    //   Joy2XCenter = EEPROM.read(4);
    //   Joy2YCenter = EEPROM.read(6);
    //   Joy3XCenter = EEPROM.read(8);
    //   Joy4XCenter = EEPROM.read(10);
    //   Joy1XLow = EEPROM.read(12);
    //   Joy1XHigh = EEPROM.read(14);
    //   Joy1YLow = EEPROM.read(16);
    //   Joy1YHigh = EEPROM.read(18);
    //   Joy2XLow = EEPROM.read(20);
    //   Joy2XHigh = EEPROM.read(22);
    //   Joy2YLow = EEPROM.read(24);
    //   Joy2YHigh = EEPROM.read(26);
    //   Joy3XLow = EEPROM.read(28);
    //   Joy3XHigh = EEPROM.readInt(30);
    //   Joy4XLow = EEPROM.read(32);
    //   Joy4XHigh = EEPROM.read(34);
    // }else{
      Joy1XCenter = 582;
      Joy1YCenter = 464;
      Joy2XCenter = 568;
      Joy2YCenter = 477;
      Joy3XCenter = 495;
      Joy4XCenter = 558;
      Joy1XLow = 288;
      Joy1XHigh = 871;
      Joy1YLow = 183;
      Joy1YHigh = 772;
      Joy2XLow = 262;
      Joy2XHigh = 844;
      Joy2YLow = 161;
      Joy2YHigh = 758;
      Joy3XLow = 115;
      Joy3XHigh = 885;
      Joy4XLow = 116;
      Joy4XHigh = 885;
    // }
    
    delay(2000);
    prepareForPrint();
  }

  void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
  
  void loop() {
    
    // recData();
    
    if(millis() - lastLoopMillis >= 20){
      lastLoopMillis = millis(); 
      readInputs();
      setspeed();
      measureVoltage();
      Screen();
      timeout();
    }
    
    if(millis() - lastSend >= sendDelay || SEND){
      SendData();
    }
  }
  

