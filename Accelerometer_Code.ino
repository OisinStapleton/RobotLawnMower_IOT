// Code to return X,Y and Z co-ordinates of an accelerometer.
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA=21, SCL=22

  if (!mma.begin()) {
    Serial.println("MMA8451 not found!");
    while (1);
  }
  Serial.println("MMA8451 found!");
}

void loop() {
  sensors_event_t event;
  mma.getEvent(&event);

  Serial.print("X: "); Serial.print(event.acceleration.x);
  Serial.print("  Y: "); Serial.print(event.acceleration.y);
  Serial.print("  Z: "); Serial.println(event.acceleration.z);

  delay(1000);
}

