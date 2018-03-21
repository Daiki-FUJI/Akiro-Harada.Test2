 /* オムニタイヤのプログラム */

void omni_set(){  // (右前. 右後, 左前, 左後)でpinの指定 RF, RB, LF, LB

	FR.attach(PIN_RF);  FR.writeMicroseconds(1500);
  BR.attach(PIN_RB);  BR.writeMicroseconds(1500);
  BL.attach(PIN_LF);  BL.writeMicroseconds(1500);
	FL.attach(PIN_LB);  FL.writeMicroseconds(1500);
	
  /* セットアップの記述場所 */
  
}

void omni(){

	x = map(LX,0,255,-moveSpeed, moveSpeed);   // speedxyの値を #define で指定
	y = map(LY,0,255,-moveSpeed, moveSpeed);
	z = map(RX,0,255,-rotateSpeed, rotateSpeed); // rotateSpeedの値を #dedine で指定
  
  if(-20 < x && x < 20){
    x = 0;
    }
  if(-23 < y && y < 23){
    y = 0;
    }
  if(-25 < z && z < 25){
    z = 0;
    }
  
	FRp = - x - y - z;
	FLp = + x + y - z;
	BRp = + x - y - z;
	BLp = - x + y - z;
  
  if(P_HIDARI){
    
      FRp = +slowSpeed - z;
      FLp = -slowSpeed - z;
      BRp = -slowSpeed - z;
      BLp = +slowSpeed - z;
    
    }
  if(P_MIGI){
    
      FRp = -slowSpeed - z;
      FLp = +slowSpeed - z;
      BRp = +slowSpeed - z;
      BLp = -slowSpeed - z;
    
    }
  if(P_UE){
    
      FRp = +slowSpeed - z;
      FLp = -slowSpeed - z;
      BRp = +slowSpeed - z;
      BLp = -slowSpeed - z;
    
    }
  if(P_SITA){
    
      FRp = -slowSpeed - z;
      FLp = +slowSpeed - z;
      BRp = -slowSpeed - z;
      BLp = +slowSpeed - z;
    
    }
	FR.writeMicroseconds(1500 + FRp);
	FL.writeMicroseconds(1500 + FLp);
	BR.writeMicroseconds(1500 + BRp);
	BL.writeMicroseconds(1500 + BLp);

  
  /* メインの処理の記述場所 */
  
}

void omniprint(){
  Serial.print(" x:");
  Serial.print(x);
  Serial.print(" y:");
  Serial.print(y);
  Serial.print(" z:");
  Serial.print(z);
}

