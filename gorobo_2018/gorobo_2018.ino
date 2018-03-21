#include <ps3btlib.h>
#include <Servo.h>
#include <Wire.h>
#include "value_def.h"
#include "define.h"
  
void setup() {
  bt_set();             // 通信開始
  i2c_set();            // Arduino間の通信
  /*-各機構セットアップ-*/
  omni_set();           
  rack_set();           
  swordAir_set();       
  plant_set();          
  Serial.begin(250000); // シリアルモニタの周波数設定
}

void loop() {
  bt_jusin();           // 通信受信
  ps3Connect();         // 接続確認
  omni();               // オムニ動作
  rack();               // ラック動作
  swordAir();
  plant();


  /*-------Serial表示について---------/
  /**** 使用したい機構を有効にする****/
   
  //omni_print();
  //rack_print();
  //swordAir_print();
  //plant_print();
  Serial.println(" ");
}
