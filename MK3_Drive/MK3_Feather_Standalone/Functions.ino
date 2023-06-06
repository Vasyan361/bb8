
  
  
  void recRemote(){
    SendRemote.sendData();

    lastRec = millis();
    Send = true;
    recBody();
  }
    
  
  void recBody(){
 
    //   if(Serial1.available() > 0){
    //     SendBody.receiveData();
    //   memcpy(bodybuf, &recFromBody, sizeof(recFromBody));
    //   if(recFromRemote.wireless == 1){
    //     radio.send(DOME_ADDRESS, bodybuf, sizeof(recFromBody)); 
    //   }else{
    //     radio.send(REMOTE_ADDRESS, bodybuf, sizeof(recFromBody));
    //   }
    //   delay(5);
    // }
    // lastSent = millis();
  }

