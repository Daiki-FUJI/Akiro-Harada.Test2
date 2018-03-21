/* I2CによりメインボードとLCD搭載のボード(Arduino間)の連携
 * ps3コントローラーの接続状態の確認
 */

void i2c_set(){

  pinMode(9, OUTPUT);
  Wire.begin(); // join i2c bus (address optional for master)  

}

void ps3Connect(){
  
  if(PS3.PS3Connected == 1){
    digitalWrite(9,HIGH);
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write("T"); 
    Wire.endTransmission();    // stop transmitting
    Serial.print(" In connection");
  }
  
  else {
    digitalWrite(9,LOW);
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write("F");    
    Wire.endTransmission();    // stop transmitting
    Serial.print(" Not connection");
  }

}

