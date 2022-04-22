void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  Serial.println(digitalRead(A0));
  if (digitalRead(A0) == true) {
    digitalWrite(3,HIGH);

  } else {
    digitalWrite(3,LOW);

  }
  if (digitalRead(A1) == true) {
    digitalWrite(9,HIGH);

  } else {
    digitalWrite(9,LOW);

  }

}
