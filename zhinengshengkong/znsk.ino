#define PIN_sound A6

volatile int sound_count;
volatile long systick_ms_001;
volatile int next_time_001;

#define DZFW "$DKT:1,1!"//低姿复位
#define ZZFW "$DKT:2,1!"//中姿复位
#define GZFW "$DKT:3,1!"//高姿复位
void my_001_zhineng_shengkong() {
  if (millis() - systick_ms_001 > next_time_001) {
    next_time_001 = 10;
    systick_ms_001 = millis();
    if (analogRead(PIN_sound) < 100) {
      next_time_001 = 2000;
      switch (sound_count) {
       case 0:
        Serial.println(DZFW);
        break;
       case 1:
        Serial.println(ZZFW);
        break;
       case 2:
        Serial.println(GZFW);
        break;
      }
      sound_count = sound_count + 1;
      if (sound_count == 3) {
        sound_count = 0;

      }

    }

  }
}

void setup(){
  Serial.begin(115200);
  Serial.println("Init ok~");
  sound_count = 0;
  systick_ms_001 = 100;
  next_time_001 = 10;
}

void loop(){
  my_001_zhineng_shengkong();

}
