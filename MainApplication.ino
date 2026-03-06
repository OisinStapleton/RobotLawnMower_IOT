#include "Ultrasonic.h"
#include "MotorFunction.h"
#include "Accelerometer.h"

void setup() {
  Serial.begin(115200);
  AccelerometerSetup();
}

void loop() {
  Ultrasonic();
  MotorFunction();
  Accelerometer();
}




