
#include <Wire.h>
#include <Adafruit_TCS34725.h>
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_4X);

volatile long systick_ms_009;

#define DZFW "$DKT:1,1!"//低姿复位
#define ZZFW "$DKT:2,1!"//中姿复位
#define GZFW "$DKT:3,1!"//高姿复位
void my_009_yanse_shibie() {
  if (millis() - systick_ms_009 > 500) {
      tcs.setInterrupt(false);
    if (tcs.getC() < 500) {
        tcs.setInterrupt(true);
      delay(800);
      if (tcs.getR() > tcs.getG() && tcs.getR() > tcs.getB()) {
        Serial.println(DZFW);

      } else if (tcs.getG() > tcs.getR() && tcs.getG() > tcs.getB()) {
        Serial.println(ZZFW);
      } else if (tcs.getB() > tcs.getR() && tcs.getB() > tcs.getG()) {
        Serial.println(GZFW);
      }

    }

  }
}

void setup(){
  Serial.begin(115200); //串口初始化

  tcs.begin();
  systick_ms_009 = millis();
}

void loop(){
  my_009_yanse_shibie();

}
