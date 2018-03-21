
/* 苗木発射機構 */

void plant_set(){ //plant
    pinMode(PIN_plantT, OUTPUT);
    pinMode(PIN_plantF, OUTPUT);
    digitalWrite(PIN_plantT, LOW);
    digitalWrite(PIN_plantF, LOW);
}

void plant(){

     if(millis() - timesP > 400){
      
        digitalWrite(PIN_plantT, LOW);  // 戻し用エアON
        digitalWrite(PIN_plantF, HIGH); 
      
     }else{
      
        digitalWrite(PIN_plantT, HIGH); // 送り用エアON
        digitalWrite(PIN_plantF, LOW);
      
        }

     if(C_SANKAKU){ 
      timesP = millis();
      }
}

void plant_print(){
  switch(SerialPlant){
    case 2: Serial.print(" Go"); break;
    case 3: Serial.print(" return"); break;
  }
}

