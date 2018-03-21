 /* ラック機構のモーター制御
    ラック機構の最大高さと最小高さを決めるプログラム */
float rackSpeed;
  
void rack_set() { // rack, limitUp, limitDown
  
  pinMode(PIN_limitUp, INPUT);
  pinMode(PIN_limitDown, INPUT);
  
  sv1.attach(PIN_rack); sv1.writeMicroseconds(1500); // ラック用のモーター
  
}

void rack(){

  sv1.writeMicroseconds(1500 - rackSpeed);
  if(P_R1){
    
    if(digitalRead(PIN_limitUp)==0){
            rackSpeed = rackUp;
    }else{
      
        rackSpeed = 0;
      
    }
    
    
  }else if(P_L1){
      
      if(digitalRead(PIN_limitDown)==0){
            rackSpeed = rackDown;
    }else{
      
        rackSpeed = 0;
      
    } 
      
  }else{rackSpeed=0;}


  /*if(C_MARU &&  下のスイッチ状態 ){
    sv5.writeMicroseconds(1500+rakkuup);
  }
  else if(C_MARU &&  上のスイッチ状態 ){
    sv5.writeMicroseconds(1500+rakkudown);
  }
  else if( 下のスイッチ状態  ||  上のスイッチ状態 ){
    sv5.writeMicroseconds(1500);
  }*/
  
  
  
}

void rack_print(){
  Serial.print(digitalRead(PIN_limitDown));
  switch(SerialRack){
    case 3: Serial.print(" UP"); break;
    case 2: Serial.print(" DOWN"); break;
  }
}

