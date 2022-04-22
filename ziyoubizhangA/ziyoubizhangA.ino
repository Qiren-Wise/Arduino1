#define PIN_trig A5
#define PIN_echo A4

volatile long systick_ms_005;
volatile long distance;
volatile long dis_hoid;
volatile boolean csb_state;

#define ZMSQJ"$DKT:17,0!"//中慢速前进
#define ZMSYZ"$DKT:20,5!"//中慢速右转
float checkdistance_PIN_trig_PIN_echo() {
  digitalWrite(PIN_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_trig, LOW);
  float distance = pulseIn(PIN_echo, HIGH) / 58.00;
  //delay(10);
  return distance;
}

void my_005_ziyou_bizhang() {
  if (millis() - systick_ms_005 > 100) {
    systick_ms_005 = millis();
    distance = checkdistance_PIN_trig_PIN_echo();
    Serial.println(distance);
    delay(1000);
    if (distance < dis_hoid && !csb_state) {
      Serial.println(ZMSYZ);
      csb_state = !csb_state;

    } else if (distance > dis_hoid && csb_state) {
      Serial.println(ZMSQJ);
      csb_state = !csb_state;
    }

  }
}

void setup(){
  Serial.begin(115200); //串口初始化

  Serial.println("Init ok~");
  delay(3000);
  systick_ms_005 = 100;
  distance = 100;
  dis_hoid = 30;
  csb_state = true;
  pinMode(PIN_trig, OUTPUT);
  pinMode(PIN_echo, INPUT_PULLUP);
}

void loop(){
  my_005_ziyou_bizhang();

}
