/* 変数の定義 */

Servo FR, FL, BR, BL, sv1;

float FRp, FLp, BRp, BLp; // omni
float x, y, z; // omni
unsigned long timesL,timesR,timesP;
int plant_shoot = 1; // 苗木発射機構


/* Serial関係 */
int SerialSwordAir, SerialPlant, SerialRack;


/* ピンの配置 */
#define  PIN_limitUp   16  // 上側のリミットスイッチ
#define  PIN_limitDown 19  // 下側のリミットスイッチ
#define  PIN_rack      8   // ラック機構用のモーター
#define  PIN_airL      23  // 第一電磁弁(剣)
#define  PIN_airR      25  // 第二電磁弁(剣)
#define  PIN_plantT    29  // 送り電磁弁(苗木)
#define  PIN_plantF    27  // 戻し電磁弁(苗木)
#define  PIN_RF        13  // 右前
#define  PIN_RB        10  // 右後
#define  PIN_LB        11  // 左後
#define  PIN_LF        12  // 左前
