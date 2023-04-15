void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  static int serVal = 0;

  if (Serial.available() > 0) {
    Serial.println(!serVal);
    serVal = Serial.parseInt();
    if (serVal == 1) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
}
