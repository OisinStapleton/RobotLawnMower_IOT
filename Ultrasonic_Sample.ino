// Code to measure distance from Ultrasonic sensor, returns value in inches and cm.

const int TRIG_PIN = 12; //Trigger
const int ECHO_PIN =14; //Echo
long duration; //used to measure time from transmission while echo returns
float cms, inches;


void setup() {
  // Serial port begin
  Serial.begin(115200);
  //define input and outputs
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

}

void loop() {
  // the sensor is triggered by a HIGH pulse of 10 or more microseconds
  // Give a short LOW pulse to ensure a clean high pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  //duration is the time in microseconds from the sending
  // of the ping to the reception of its echo off an object
  duration = pulseIn(ECHO_PIN, HIGH);

  //convert the time into the distance
  cms = (duration/2) / 29.1; // divide by 29.1 or multiply by 0.0343
  inches = (duration/2) /74; // divide by 74 or multiply by 0.0135

  Serial.print(inches);
  Serial.print("in,\n ");
  Serial.print(cms);
  Serial.print("cm,\n ");

delay(1000);

}
