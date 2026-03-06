#include <Ultrasonic.h> 
#include <MotorFunction.h> // Including all individual code from Arduino tabs.
#include <Accelerometer.h>

#include <Wire.h>
#include <Adafruit_MMA8451.h> // #includes necessary to run accelerometer
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();  

const int TRIG_PIN = 12; //Trigger
const int ECHO_PIN =14; //Echo
long duration; //used to measure time from transmission while echo returns
float cms, inches;

int E1 = 14;
int M1 = 27;
int E2 = 32;
int M2 = 33;

void setup(){
    // Serial port begin
  Serial.begin(115200);

  //define input and outputs
  //Ultrasonic config
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

// Motor config
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

// Accelerometer config
  Wire.begin(21, 22);  // SDA=21, SCL=22
}

void loop(){
  Ultrasonic();
  MotorFunction();
  Accelerometer();
}




