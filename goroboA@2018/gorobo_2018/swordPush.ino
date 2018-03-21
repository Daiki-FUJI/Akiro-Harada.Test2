/* 剣をエアシリンダで押す */

void swordAir_set(){ // 電磁弁の初期設定(剣用) air, kenair

   pinMode(PIN_airL, OUTPUT);
   pinMode(PIN_airR, OUTPUT);
   digitalWrite(PIN_airL, LOW);    // 主の剣用エアOFF
   digitalWrite(PIN_airR, LOW); 

}

void swordAir(){

   if(C_SIKAKU){  // 左の水鉄砲ポン
      digitalWrite(PIN_airL, HIGH); // 主の剣用エアON
      timesL = millis();
      SerialSwordAir = 2;
   }
      
   if(C_MARU){  // 右の水鉄砲ポン
      digitalWrite(PIN_airR, HIGH);// 主の剣用エアON
      timesR = millis();
      SerialSwordAir = 3;
   }

     if(millis() - timesL > swordAirStop) digitalWrite(PIN_airL, LOW); // 主の剣用エアOFF
     if(millis() - timesR > swordAirStop) digitalWrite(PIN_airR, LOW); // 主の剣用エアOFF

}

void swordAir_print(){
  switch(SerialSwordAir){
    case 2: Serial.print(" left"); break;
    case 3: Serial.print(" right"); break;
  }
}

