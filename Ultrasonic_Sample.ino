void Ultrasonic() {

  const int TRIG_PIN = 12;
  const int ECHO_PIN = 14;

  long duration; // used to measure time from transmission while echo returns.
  float cms, inches;

  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

//convert the time into the distance
  cms = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  Serial.print(inches);
  Serial.print("in ");
  Serial.print(cms);
  Serial.println("cm");

  delay(1000);
}
