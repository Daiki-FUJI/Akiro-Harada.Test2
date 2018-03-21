#include<ps3btlib.h>
#include<Servo.h>
Servo s1,s2,s3;
int wpPin = 14;         // OutputPinWeapon
int rPin = 15;          // OutputPinR
int lPin = 16;          // OutputPinL 
int mvPower = 500;      // movingPower
int wpPower = 500;      // weaponPower

void setup() {
  bt_set();
  s1.attach(lPin);
  s2.attach(rPin);
  s3.attach(wpPin);
}

void loop() {
  bt_jusin();
  
  
  // Calc
  float mvL = map(LY,0,255,-mvPower,mvPower);
  float mvR = map(RY,0,255,mvPower,-mvPower);
   
  // Moving
  s1.writeMicroseconds(1500 + mvL);
  s2.writeMicroseconds(1500 + mvR);

  // Weapon
  if(C_MARU){
    
      s3.writeMicroseconds(1500 + wpPower);
    
    }
  if(C_BATU){
    
      s3.writeMicroseconds(1500);
    
    }
}
