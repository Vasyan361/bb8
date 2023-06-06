 
  void setspeed(){ 
    
    if(Display <2){
      if(rBut1 == 0 && rBut1State == 0){
        rBut1State = 1;
      }else if(rBut1 == 1 && rBut1State == 1){
        rBut1State = 0;
        if(Speed == 0){
          Speed = 1;
        }else if(Speed == 1){
          Speed = 2;
        }else if(Speed == 2){
          Speed = 0;
        }
        updateScreen = 1;
      }   
    }
  }
  
  void measureVoltage(){
  
    if(millis() - lastReading >= 10000){
      lastReading = millis();
      measuredvbat = 42;
    }
  }
  
  void readInputs(){

    #ifdef serialSound
      
      lBut1 = digitalRead(lBut1PIN);
      lBut2 = digitalRead(lBut2PIN);
      rBut3 = digitalRead(lBut3PIN);
      
      if(analogRead(rBut3PIN) > 1){
        rBut3 = 1;
      }else{
        rBut3 = 0;
      }
      
            
      if((lBut1 == 0 || rBut3 == 0) && But1State == 0){
        But1State = 1;
        But1Millis = millis();
        
      }else if(lBut1 == 1 && rBut3 == 1 && But1State == 1){
        But1State = 0;
        But1Sound ++;
        
          if(But1Sound > 6){
            But1Sound -= 6;
            
          }
      }
      if(But1Sound > 0 && millis() - But1Millis >= 800){
        voiceSend = 0;
        But1Sound = 0;
        sendToBody.lBut1 = But1Sound;
        
      }else if(But1Sound > 0 && millis() - But1Millis >= 400){
        sendToBody.lBut1 = But1Sound;
      }  
      
        
      if(lBut2 == 0 && But2State == 0){
        But2State = 1;
        But2Millis = millis();
      }else if(lBut2 == 1 && But2State == 1){
        But2State = 0;
        But2Sound ++;
        
          if(But2Sound > 6){
            But2Sound -= 6;
            
          }
      }
      
      if(But2Sound > 0 && millis() - But2Millis >= 800){
        musicSend = 0;
        But2Sound = 0;
        sendToBody.lBut2 = But2Sound;
        
      }else if(But2Sound > 0 && millis() - But2Millis >= 400){
        sendToBody.lBut2 = But2Sound;
      }
      
      if(sendToBody.rBut3 != 0){
        sendToBody.rBut3 = 0;
      }
      
      
      
     #else
    
      lBut1Timer = digitalRead(lBut1PIN);
      lBut2Timer = digitalRead(lBut2PIN);
      
      
      if(analogRead(rBut3PIN) > 1){
        rBut3Timer = 1;
      }else{
        rBut3Timer = 0;
      }
  
  
      if(lBut1Timer == 0 && lBut1 == 1){
        lBut1 = 0;
        lBut1Millis = millis();
      }else if(lBut1Timer == 1 && lBut1 == 0){
        if(millis() - lBut1Millis >= 300){
          lBut1 = 1;
        }
      }
  
      if(lBut2Timer == 0 && lBut2 == 1){
        lBut2 = 0;
        lBut2Millis = millis();
      }else if(lBut2Timer == 1 && lBut2 == 0){
        if(millis() - lBut2Millis >= 300){
          lBut2 = 1;
        }
      }
  
      if(rBut3Timer == 0 && rBut3 == 1){
        rBut3 = 0;
        rBut3Millis = millis();
      }else if(rBut3Timer == 1 && rBut3 == 0){
        if(millis() - rBut3Millis >= 300){
          rBut3 = 1;
        }
      }

    #endif

    lBut3 = digitalRead(lBut3PIN);
    rBut1 = digitalRead(rBut1PIN);
    rBut2 = digitalRead(rBut2PIN);
    
    Joy1Xa = constrain(map(analogRead(Joy1XPIN), 4065, 0, 0, 1023), 0, 1023);
    Joy1Ya = constrain(map(analogRead(Joy1YPIN), 0, 4065, 0, 1023), 0, 1023);
    Joy2Xa = constrain(map(analogRead(Joy2XPIN), 4065, 0, 0, 1023), 0, 1023);
    Joy2Ya = constrain(map(analogRead(Joy2YPIN), 0, 4065, 0, 1023), 0, 1023);
    Joy3Xa = constrain(map(analogRead(Joy3XPIN), 0, 4065, 0, 1023), 0, 1023);
    Joy4Xa = constrain(map(analogRead(Joy4XPIN), 0, 4065, 0, 1023), 0, 1023);
    lJoySelect = digitalRead(lJoySelectPIN);
    rJoySelect = digitalRead(rJoySelectPIN);
    motorEnable = digitalRead(enablePIN);
    centerChannels();
    setServoMode();
  
  
  }
  
  void centerChannels(){
       int centerRadius = 100;
    // if (Joy1Xa == Joy1XCenter){
    if (Joy1Xa > (Joy1XCenter - centerRadius) && Joy1Xa < (Joy1XCenter + centerRadius)){
      Joy1Xb = 256;
    }else if (Joy1Xa > Joy1XCenter){
      Joy1Xb = map(Joy1Xa, Joy1XCenter, Joy1XHigh, 255, 0);
    }else if (Joy1Xa < Joy1XCenter){
      Joy1Xb = map(Joy1Xa, Joy1XLow, Joy1XCenter, 512, 257);
    }
    
    // if (Joy1Ya == Joy1YCenter){
    if (Joy1Ya > (Joy1YCenter - centerRadius) && Joy1Ya < (Joy1YCenter + centerRadius)){
      Joy1Yb = 256;
    }else if (Joy1Ya > Joy1YCenter){
      Joy1Yb = map(Joy1Ya, Joy1YCenter, Joy1YHigh, 255, 0);
    }else if (Joy1Ya < Joy1YCenter){
      Joy1Yb = map(Joy1Ya, Joy1YLow, Joy1YCenter, 512, 257);
    }
  
    // if (Joy2Xa == Joy2XCenter){
    if (Joy2Xa > (Joy2XCenter - centerRadius) && Joy2Xa < (Joy2XCenter + centerRadius)){
      Joy2Xb = 256;
    }else if (Joy2Xa > Joy2XCenter){
      Joy2Xb = map(Joy2Xa, Joy2XCenter, Joy2XHigh, 255, 0);
    }else if (Joy2Xa < Joy2XCenter){
      Joy2Xb = map(Joy2Xa, Joy2XLow, Joy2XCenter, 512, 257);
    }
  
    // if (Joy2Ya == Joy2YCenter){
    if (Joy2Ya > (Joy2YCenter - centerRadius) && Joy2Ya < (Joy2YCenter + centerRadius)){
      Joy2Yb = 256;
    }else if (Joy2Ya > Joy2YCenter){
      Joy2Yb = map(Joy2Ya, Joy2YCenter, Joy2YHigh, 255, 0);
    }else if (Joy2Ya < Joy2YCenter){
      Joy2Yb = map(Joy2Ya, Joy2YLow, Joy2YCenter, 512, 257);
    }
  
    // if (Joy3Xa == Joy3XCenter){
    if (Joy3Xa > (Joy3XCenter - centerRadius) && Joy3Xa < (Joy3XCenter + centerRadius)){
      Joy3Xb = 256;
    }else if (Joy3Xa > Joy3XCenter){
      Joy3Xb = map(Joy3Xa, Joy3XCenter, Joy3XHigh, 255, 0);
    }else if (Joy3Xa < Joy3XCenter){
      Joy3Xb = map(Joy3Xa, Joy3XLow, Joy3XCenter, 512, 257);
    }
  
    // if (Joy4Xa == Joy4XCenter){
    if (Joy4Xa > (Joy4XCenter - centerRadius) && Joy4Xa < (Joy3XCenter + Joy4XCenter)){
      Joy4Xb = 256;
    }else if (Joy4Xa > Joy4XCenter){
      Joy4Xb = map(Joy4Xa, Joy4XCenter, Joy4XHigh, 255, 0);
    }else if (Joy4Xa < Joy4XCenter){
      Joy4Xb = map(Joy4Xa, Joy4XLow, Joy4XCenter, 512, 257);
    }
  
    Joy1X = constrain(Joy1Xb,0,512);
    Joy1Y = constrain(Joy1Yb,0,512);
    Joy2X = constrain(Joy2Xb,0,512);
    Joy2Y = constrain(Joy2Yb,0,512);
    Joy3X = constrain(Joy3Xb,0,512);
    Joy4X = constrain(Joy4Xb,0,512);


    Serial.print(Joy1Xa); Serial.print(", ");
    Serial.print(Joy2X); Serial.print(", ");
    Serial.print(Joy2Y); Serial.print(", ");
    Serial.print(Joy3Xb); Serial.print(", ");
    Serial.print(Joy4Xb); Serial.print(", ");
    Serial.println(Joy2Y);
  
    if(Display < 2){
      reverseControls();
    }
  }
  
  
  void reverseControls(){
    
    if(Display == 0){
      if(rJoySelect == 0 && JoySelectState == 0){
        JoySelectState = 1;
      }else if (rJoySelect == 1 && JoySelectState != 0){
        JoySelectState = 0;
          if(Fwd == 0){
            Fwd = 1;
            updateScreen = 1;
          }else if(Fwd == 1){
            Fwd = 0;
            updateScreen = 1;
          }
      }
    }  
  }
  
  void setDomeDirection(){
  
    switch (dome180) {
      case 0:
       if (Fwd == 0){
        DomeDirection = 0;
       }else{
        DomeDirection = 1;
       }
      break;
    
      case 1:
       if (Fwd == 0){
        DomeDirection = 1;
       }else{
        DomeDirection = 0;
       }
      break;
    }
  }
  
  void SendData(){
    if(millis() > 2000){
      if(millis() - lastSend >= sendDelay){
  
        #ifndef serialSound
          sendToBody.lBut1 = lBut1; //left 1
          sendToBody.lBut2 = lBut2; //left 2
          sendToBody.rBut3 = rBut3; //right 3
        #endif
  
        // sendToBody.Joy1X = constrain(map(analogRead(Joy1XPIN), 4065, 0, 0, 1023), 0, 1023);
        // sendToBody.Joy1Y = constrain(map(analogRead(Joy1YPIN), 0, 4065, 0, 1023), 0, 1023);
        // sendToBody.Joy2X = constrain(map(analogRead(Joy2XPIN), 4065, 0, 0, 1023), 0, 1023);
        // sendToBody.Joy2Y = constrain(map(analogRead(Joy2YPIN), 0, 4065, 0, 1023), 0, 1023);
        // sendToBody.Joy3X = constrain(map(analogRead(Joy3XPIN), 0, 4065, 0, 1023), 0, 1023);
        // sendToBody.Joy4X = constrain(map(analogRead(Joy4XPIN), 0, 4065, 0, 1023), 0, 1023);


        sendToBody.Joy1Y = Joy1Y; //main drive
        sendToBody.Joy1X = Joy1X; //tilt / steer
        sendToBody.Joy2Y = Joy2Y; //head tilt
        sendToBody.Joy2X = Joy2X; //head spin
        sendToBody.Joy3X = Joy3X; //spin Flywheel
        sendToBody.Joy4X = Joy4X;
        sendToBody.ServoMode = ServoMode; //Select on left joystick
        sendToBody.lBut3 = lBut3; //left3
        sendToBody.Fwd = Fwd; //Select on right joystick = rJoySelect
        sendToBody.Speed = Speed;
        sendToBody.rBut2 = rBut2; //right 2
        sendToBody.motorEnable = motorEnable; //toggle on top
        sendToBody.wireless = bodyWireless;

        lastSend = millis();
        // Serial.print(Joy2X); Serial.println(Joy2Y);
        esp_err_t result = esp_now_send(bodyAddress, (uint8_t *) &sendToBody, sizeof(sendToBody));
   
        if (result == ESP_OK) {
            Serial.println("Sent with success");
        }
        else {
            Serial.println("Error sending the data");
        }
        // #ifdef debug
          debugRoutine(); 
        // #endif
      }
    }
  }
 
    void recData(){
      // if(millis() - lastrecDataMillis >= recDelay){
      //   if (radio.receiveDone()) {
      //     if(radio.SENDERID == uint8_t(DOME_ADDRESS)){ //********** This needs to be fixed for new lib
      //       if(radio.DATALEN != sizeof(recFromDome)){
      //         Serial.print("Invalid DOME payload received, not matching Payload struct! Should Be:");
      //         Serial.print(sizeof(recFromDome)); Serial.print(" received:"); Serial.println(radio.DATALEN);
      //       }else{
      //           recFromDome = *(recDomeData*)radio.DATA;
      //           //Serial.println(millis() - lastrecdata);
      //           lastrecdata = millis();
      //           lastrecDataMillis = millis();
      //           if(bodyWireless == 0){
      //             bodyWireless = 1;
      //           }
      //         }
      //       SEND = true;
      //     }else if(radio.SENDERID == uint8_t(BODY_ADDRESS)){ //********** This needs to be fixed for new lib
      //       if(radio.DATALEN != sizeof(recFromBody)){
      //         Serial.print("Invalid BODY payload received, not matching Payload struct! Should Be:");
      //         Serial.print(sizeof(recFromBody)); Serial.print(" received:"); Serial.println(radio.DATALEN);
      //       }else{
      //           recFromBody = *(recBodyData*)radio.DATA; 
      //           recFromDome.bodyBatt = recFromBody.bodyBatt;               
      //           Serial.println("rec body");
      //           lastrecdata = millis();
      //           lastrecDataMillis = millis();
      //           if(recFromDome.domeBatt != 99.99){
      //             recFromDome.domeBatt = 99.99;
      //           }
      //           if(bodyWireless == 1){
      //             bodyWireless = 0;
      //           }
      //         }
      //       SEND = true;
      //     }
      //   }
      // }
    }
  
   void Screen(){
    
    if(Display < 2){
        infoScreen();
        menuTimer();
    }else if(Display == 2){
      if(ServoMode != 0){
        ServoMode = 0;
      }
      menuScreen();
      MenuTimeout();
      enable = 1;
      Joy1Xa = Joy1XCenter;
      Joy1Ya = Joy1YCenter;
      Joy2Xa = Joy2XCenter;
      Joy2Ya = Joy1YCenter;
      Joy3Xa = Joy3XCenter;
      Joy4Xa = Joy4XCenter;
      lJoySelect = 1;
      rJoySelect = 1;
    }else if(Display == 3){
      domeReverseScreen();
    }else if(Display == 4){
      domeConfig();     
    }else if(Display == 5){
      bodyConfig();
    }else if(Display == 6){
      joystickConfig();
      enable = 1;
      Joy1Xa = Joy1XCenter;
      Joy1Ya = Joy1YCenter;
      Joy2Xa = Joy2XCenter;
      Joy2Ya = Joy1YCenter;
      Joy3Xa = Joy3XCenter;
      Joy4Xa = Joy4XCenter;
      lJoySelect = 1;
      rJoySelect = 1;
    }
  }
  
  void menuTimer(){
    
    if(rBut2 == 0 && rBut3 == 0 && Display == 0){
      buttonTimer = millis();
      Display = 1;
    }else if(rBut2 == 0 && rBut3 == 0 && Display == 1 && millis() - buttonTimer >= 1500){
      prepareForPrint();
      Display = 2;
      menuTimeout = millis();
    }else if(rBut2 == 1 || rBut3 == 1 && Display == 1){
      Display = 0; 
    }
  }
  
  void MenuTimeout(){
    
    if(millis() - menuTimeout >= 15000){
      resetMenu();
    }
  }
  
  void menuScreen(){
    menuCursor();
    if(casenum != lastcasenum){
      prepareForPrint();
      lastcasenum = casenum;
      switch (casenum){
        case 0:
          oled.setCursor(0,0);
          oled.print(">");
          oled.setCursor(15,0);
          oled.println(menuItems[0]);
          oled.print("   ");
          oled.setCursor(15,8);
          oled.println(menuItems[1]);
          oled.print("   ");
          oled.setCursor(15,16);
          oled.println(menuItems[2]);
          oled.print("   ");
          oled.setCursor(15,24);
          oled.println(menuItems[3]);
        break;
        case 1:
          oled.setCursor(0,0);
          oled.print("   ");
          oled.setCursor(15,0);
          oled.println(menuItems[0]);
          oled.print(">");
          oled.setCursor(15,8);
          oled.println(menuItems[1]);
          oled.print("   ");
          oled.setCursor(15,16);
          oled.println(menuItems[2]);
          oled.print("   ");
          oled.setCursor(15,24);
          oled.println(menuItems[3]);
        break;
      
        case 2:
          oled.setCursor(0,0);
          oled.print("   ");
          oled.setCursor(15,0);
          oled.println(menuItems[0]);
          oled.print("   ");
          oled.setCursor(15,8);
          oled.println(menuItems[1]);
          oled.print(">");
          oled.setCursor(15,16);
          oled.println(menuItems[2]);
          oled.print("   ");
          oled.setCursor(15,24);
          oled.println(menuItems[3]);
        break;
      
        case 3:
          oled.setCursor(0,0);
          oled.print("   ");
          oled.setCursor(15,0);
          oled.println(menuItems[0]);
          oled.print("   ");
          oled.setCursor(15,8);
          oled.println(menuItems[1]);
          oled.print("   ");
          oled.setCursor(15,16);
          oled.println(menuItems[2]);
          oled.print(">");
          oled.setCursor(15,24);
          oled.println(menuItems[3]);
        break;
      }
      oled.display();
    }
    
    if(digitalRead(rJoySelectPIN) == 0){
      switch(casenum){
        case 0:
          Display = 3;
          subMenuDome180();
            //Do This to reverse the dome
        break;
        
        case 1:
          JoySelectState = 1;
          Display = 4;
          prepareForPrint();
          oled.println("1. Face dome forward");
          oled.println("2. Press 'select'");
          domeConfigTimeout = millis();
          oled.display();
            //Do This for Dome Config
        break;
    
        case 2:
          Display = 5;
          prepareForPrint();
            //Do This for Body Config
        break;
        
        case 3:
          Display = 6;
        break;
      }
    }
  }
   
  void menuCursor(){
  
    // if((analogRead(Joy1YPIN) < 1000 && cursorMove == 0) || (analogRead(Joy2YPIN) < 1000 && cursorMove == 0)){
    if((analogRead(Joy2YPIN) < 1000 && cursorMove == 0)){
      menuTimeout = millis();
      casenum--;
      cursorMove = 1;
      if(casenum < 0){
        casenum = 3;
      }
    // }else if((analogRead(Joy1YPIN) > 3000 || analogRead(Joy2YPIN) > 3000) && cursorMove == 0){
    }else if(analogRead(Joy2YPIN) > 3000 && cursorMove == 0){
      menuTimeout = millis();
      casenum++;
      cursorMove = 1;
      if(casenum > 3){
        casenum = 0;
      }
    // }else if(analogRead(Joy1YPIN) < 2548 && analogRead(Joy1YPIN) > 1548 && analogRead(Joy2YPIN) < 2548 && analogRead(Joy2YPIN) > 1548){
    }else if(analogRead(Joy2YPIN) < 2548 && analogRead(Joy2YPIN) > 1548){
      cursorMove = 0;
    }
  }
  
  void infoScreen(){
    
    if(millis() - lastScreenUpdate >= 10000 || updateScreen == 1){
      prepareForPrint();
      updateScreen = 0;
      oled.setCursor(0,0);
      oled.print(speedDisplay[Speed]);oled.print(F("        "));
      oled.setCursor(100,0);
      if(Fwd == 0 || Fwd == 2){
        oled.println(F("Fwd     "));
      }else{
        oled.println(F("Rev     "));
      }
      oled.print(F("Body: ")); 
        if(wireless == 1 && recFromDome.bodyBatt != 99.99){
          oled.print(recFromDome.bodyBatt); oled.println(F("v                 "));
        }else{
          oled.println(F("Disconnected              ")); 
        }
      oled.print(F("Dome: ")); 
        if(wireless == 1 && recFromDome.domeBatt != 99.99){
          oled.print(recFromDome.domeBatt); oled.println("v                 ");
        }else{
          oled.println(F("Disconnected              ")); 
        }
      oled.print("Remote: "); oled.print(measuredvbat); oled.println(F("v               "));
      oled.display();
      lastScreenUpdate = millis();
    }
  }
  
  void subMenuDome180(){
    
    if(dome180 == 0){
      dome180 = 2;
     }else{
      dome180 = 0;
     }
    menuTimeout = millis();
    prepareForPrint();
    oled.print(F("Dome Reversed!"));
    oled.display();
  }
  
  void domeConfig(){
    
    if(JoySelectState == 1 && sendToBody.CalibID == 0){
      if(lJoySelect == 1 && rJoySelect == 1){
        JoySelectState = 0;
      }
    }
    if((lJoySelect == 0 || rJoySelect == 0) && JoySelectState != 1){
      prepareForPrint();
      JoySelectState = 1;
      sendToBody.CalibID = 1;
      prepareForPrint();
      oled.print(F(" Dome Configured! "));
      domeConfigTimeout = millis() - 8500 ;
      oled.display();
      
    }
  
    if(millis() - domeConfigTimeout >= 10000){
      JoySelectState = 0;
      resetMenu();
    }
    
  }
  
  void bodyConfig(){
  
    if(bodyConfigStep == 0){
      prepareForPrint();
      oled.print(F(" Body Configuration "));
      bodyConfigStep = 1;
      bodyConfigMillis = millis();
      sendToBody.CalibID = 2;
      oled.display();
    }else if(bodyConfigStep == 1 && millis() - bodyConfigMillis >= 1500){
      prepareForPrint();
      oled.setCursor(0,0);
      oled.println(F(" Adjust dome tilt        "));
      oled.println(F(" until the dome is        "));
      oled.println(F(" centered front to back.        "));
      oled.println(F(" Then press 'Select'        "));
      bodyConfigStep = 2;
      oled.display();
    }else if(bodyConfigStep == 2){
      if((digitalRead(lJoySelectPIN) == 0 || digitalRead(rJoySelectPIN) == 0) && JoySelectState == 0){
        JoySelectState = 1;
      }else if((digitalRead(lJoySelectPIN) == 1 && digitalRead(rJoySelectPIN) == 1) && JoySelectState == 1){
        prepareForPrint();
        JoySelectState = 0;
        sendToBody.CalibID = 3;
        bodyConfigStep = 3;
        bodyConfigMillis = millis();
        prepareForPrint();
        oled.println(F(" Dome tilt offset "));
        oled.println(F(" and pitch offset "));
        oled.println(F(" saved to eeprom "));
        oled.display();
      }
    }else if(bodyConfigStep == 3 && millis() - bodyConfigMillis >= 2500){
      prepareForPrint();
      oled.println(F(" Adjust Side to Side "));
      oled.print(F(" until ")); oled.print(F(droidName)); oled.println(F(" is straight."));
      oled.println(F(" Then press 'Select'        "));
      bodyConfigStep = 4;
      oled.display();
    }else if(bodyConfigStep == 4){
      if((digitalRead(lJoySelectPIN) == 0 || digitalRead(rJoySelectPIN) == 0) && JoySelectState == 0){
        JoySelectState = 1;
      }else if((digitalRead(lJoySelectPIN) == 1 && digitalRead(rJoySelectPIN) == 1) && JoySelectState == 1){
        prepareForPrint();
        JoySelectState = 0;
        sendToBody.CalibID = 4;
        bodyConfigStep = 5;
        bodyConfigMillis = millis();
        prepareForPrint();
        oled.println(F(" Body Calibration ")); oled.println(F(" Complete! "));
        oled.display();
      }
    }else if(bodyConfigStep == 5 && millis() - bodyConfigMillis >= 2500){
      resetMenu();
    }
  }
  
  void joystickConfig(){
    
    if(joyConfStep == 1){     
      joyConfMillis = millis();
      joyConfStep = 2;
      prepareForPrint();
    }else if(joyConfStep == 2 && millis() - joyConfMillis >= joyConfCountdown && waitTime > 0 ){;
      prepareForPrint();
      oled.setCursor(0,0);
      oled.println(F("Release Joysticks"));
      oled.print(F("Wait: ")); oled.print(waitTime);
      joyConfCountdown += 1000;
      waitTime--;
      oled.display();
    }else if(joyConfStep == 2 && waitTime == 0 && millis() - joyConfMillis >= joyConfCountdown){
      prepareForPrint();
      joyConfStep = 3;
      joyConfCountdown += 2000;
      oled.setCursor(0,0);
      oled.println(F("Storing Center values"));
      oled.print(F("                    "));
      setJoystickCenter();
      waitTime = 15;
      oled.display();
    }else if(joyConfStep == 3 && millis() - joyConfMillis >= joyConfCountdown && waitTime > 0){
      prepareForPrint();
      oled.setCursor(0,0);
      oled.println(F("Continuously rotate      ")); oled.println(F("all joysticks"));
      oled.print(waitTime);oled.print("                  ");
      joyConfCountdown += 1000;
      waitTime--;
      oled.display();
    }else if(joyConfStep == 3 && waitTime != 0){
      readJoystickHighAndLow();
    }else if(joyConfStep == 3 && waitTime == 0){
      prepareForPrint();
      joyConfStep = 4;
      joyConfCountdown += 2500;
      oled.setCursor(0,0);
      oled.println(F("Calibration Complete!              "));
      oled.println(F("                                   "));
      oled.println(F("                                   "));
      setJoystickHighAndLow();
      oled.display();
    }else if(joyConfStep == 4 && millis() - joyConfMillis >= joyConfCountdown){
      resetMenu();
    }

   
  }
  
  void resetMenu(){
    
    prepareForPrint();
    joyConfStep = 1;
    casenum = 0;
    lastcasenum = 1;
    menuConfirm = 0;
    joyConfCountdown = 0;
    waitTime = 5;
    Display = 0;
    sendToBody.CalibID = 0;
    bodyConfigStep = 0;
    
  }
  
  void readJoystickHighAndLow(){
  
    if(start == 0){
      start = 1;
      Joy1XLow = 512;
      Joy1XHigh = 512;
      Joy1YLow = 512;
      Joy1YHigh = 512;
      Joy2XLow = 512;
      Joy2XHigh = 512;
      Joy2YLow = 512;
      Joy2YHigh = 512;
      Joy3XLow = 512;
      Joy3XHigh = 512;
      Joy4XLow = 512;
      Joy4XHigh = 512;
    }else if(start == 1){

      joyconfigX1 = constrain(map(analogRead(Joy1XPIN), 4065, 0, 0, 1023), 0, 1023);
      joyconfigY1 = constrain(map(analogRead(Joy1YPIN), 4065, 0, 0, 1023), 0, 1023);
      joyconfigX2 = constrain(map(analogRead(Joy2XPIN), 4065, 0, 0, 1023), 0, 1023);
      joyconfigY2 = constrain(map(analogRead(Joy2YPIN), 4065, 0, 0, 1023), 0, 1023);
      joyconfigX3 = constrain(map(analogRead(Joy3XPIN), 0, 4065, 0, 1023), 0, 1023);
      joyconfigX4 = constrain(map(analogRead(Joy4XPIN), 0, 4065, 0, 1023), 0, 1023);
  
      if (joyconfigX1 < Joy1XLow){
        Joy1XLow = joyconfigX1;
      }
      if (joyconfigY1 < Joy1YLow){
        Joy1YLow = joyconfigY1;
      }
      if (joyconfigX2 < Joy2XLow){
        Joy2XLow = joyconfigX2;
      }
      if (joyconfigY2 < Joy2YLow){
        Joy2YLow = joyconfigY2;
      }
      if (joyconfigX3 < Joy3XLow){
        Joy3XLow = joyconfigX3;
      }
      if (joyconfigX4 < Joy4XLow){
        Joy4XLow = joyconfigX4;
      }
      if (joyconfigX1 > Joy1XHigh){
        Joy1XHigh = joyconfigX1;
      }
      if (joyconfigY1 > Joy1YHigh){
        Joy1YHigh = joyconfigY1;
      }
      if (joyconfigX2 > Joy2XHigh){
        Joy2XHigh = joyconfigX2;
      }
      if (joyconfigY2 > Joy2YHigh){
        Joy2YHigh = joyconfigY2;
      }
      if (joyconfigX3 > Joy3XHigh){
        Joy3XHigh = joyconfigX3;
      }
      if (joyconfigX4 > Joy4XHigh){
        Joy4XHigh = joyconfigX4;
      }
    }
  }
  
   void setJoystickCenter(){
    EEPROM.put(0,constrain(map(analogRead(Joy1XPIN), 4065, 0, 0, 1023), 0, 1023));
    EEPROM.put(2,constrain(map(analogRead(Joy1YPIN), 4065, 0, 0, 1023), 0, 1023));
    EEPROM.put(4,constrain(map(analogRead(Joy2XPIN), 4065, 0, 0, 1023), 0, 1023));
    EEPROM.put(6,constrain(map(analogRead(Joy2YPIN), 4065, 0, 0, 1023), 0, 1023));
    EEPROM.put(8,constrain(map(analogRead(Joy3XPIN), 0, 4065, 0, 1023), 0, 1023));
    EEPROM.put(10,constrain(map(analogRead(Joy4XPIN), 0, 4065, 0, 1023), 0, 1023));

    EEPROM.commit();
  }
  
  void setJoystickHighAndLow(){

    EEPROM.put(12,Joy1XLow);
    EEPROM.put(14,Joy1XHigh);
    EEPROM.put(16,Joy1YLow);
    EEPROM.put(18,Joy1YHigh);
    EEPROM.put(20,Joy2XLow);
    EEPROM.put(22,Joy2XHigh);
    EEPROM.put(24,Joy2YLow);
    EEPROM.put(26,Joy2YHigh);
    EEPROM.put(28,Joy3XLow);
    EEPROM.put(30,Joy3XHigh);
    EEPROM.put(32,Joy4XLow);
    EEPROM.put(34,Joy4XHigh);
    EEPROM.put(36,eepromSet);

    EEPROM.commit();
  }
  
  void domeReverseScreen(){
    
    if(millis() - menuTimeout >= 1500){
     resetMenu();
    }
  }
  
  void timeout(){
    
    if(millis() - lastrecdata >= 2500){
      if(wireless == 1){
        wireless = 0;
        updateScreen = 1;
      }
    }else if(millis() - lastrecdata <= 1000 && wireless == 0){
      wireless = 1;
      updateScreen = 1;
    }
  
  }
  
  void setServoMode(){
    
    if(Display == 0){
      if(lJoySelect == 0 && ServoJoySelectState == 0){
        ServoJoySelectState = 1;
      }else if(lJoySelect == 1 && ServoJoySelectState == 1){
        ServoJoySelectState = 0;
        if(ServoMode == 0){
          ServoMode = 1;
        }else{
          ServoMode = 0;
        }
      }
    }
  }

void  prepareForPrint()
{
    oled.clearDisplay();
    oled.setCursor(0,0); 

    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
}

  void debugRoutine(){
        Serial.print(sendToBody.Joy1Y); Serial.print(", ");
        Serial.print(sendToBody.Joy1X); Serial.print(", ");
        Serial.print(sendToBody.Joy2Y); Serial.print(", ");
        Serial.print(sendToBody.Joy2X); Serial.print(", ");
        Serial.print(sendToBody.Joy3X); Serial.print(", ");
        Serial.print(sendToBody.Joy4X); Serial.print(", ");
        // Serial.print(sendToBody.ServoMode); Serial.print(", ");
        // Serial.print(sendToBody.lBut1); Serial.print(", ");
        // Serial.print(sendToBody.lBut2); Serial.print(", ");
        // Serial.print(sendToBody.lBut3); Serial.print(", ");
        // Serial.print(sendToBody.Fwd); Serial.print(", ");
        // Serial.print(sendToBody.Speed); Serial.print(", ");
        // Serial.print(sendToBody.rBut2); Serial.print(", ");
        // Serial.print(sendToBody.rBut3); Serial.print(", ");
        // Serial.print(sendToBody.motorEnable); Serial.print(", ")
        // Serial.print(sendToBody.CalibID); Serial.print(", ");
        // Serial.println(sendToBody.wireless);
         Serial.print("ServoMode: "); Serial.println(sendToBody.ServoMode);
         Serial.print("lBut1: "); Serial.println(sendToBody.lBut1);
         Serial.print("lBut2: "); Serial.println(sendToBody.lBut2);
         Serial.print("lBut3: "); Serial.println(sendToBody.lBut3);
         Serial.print("Fwd: "); Serial.println(sendToBody.Fwd);
         Serial.print("Speed: "); Serial.println(sendToBody.Speed);
         Serial.print("rBut2: "); Serial.println(sendToBody.rBut2);
         Serial.print("rBut3: "); Serial.println(sendToBody.rBut3);
         Serial.print("motorEnable: "); Serial.println(sendToBody.motorEnable);
         Serial.print("CalibID: "); Serial.println(sendToBody.CalibID);
         Serial.print("wireless: "); Serial.println(sendToBody.wireless);
         Serial.println("");
  }

