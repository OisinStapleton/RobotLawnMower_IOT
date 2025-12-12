// Motor Demo code, foward, back, left, right

// Motor 1
const int MOTOR_L_PIN = 27;
const int ENABLE_L_PIN = 14;

//Motor 2
const int MOTOR_R_PIN = 33;
const int ENABLE_R_PIN = 32;

//Setting PWM properties
const int FREQ = 30000;
const int PWM_CHANNEL = 0;
const int RESOLUTION = 8;
int dutycycle = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
//Set motor pins as outputs
pinMode(MOTOR_R_PIN,OUTPUT);
pinMode(MOTOR_L_PIN,OUTPUT);
//configure PWM channel 0 to enable pins
ledcSetup(PWM_CHANNEL, FREQE, RESOLUTION);
//Attach the PWM channel 0 to the enable pins
ledcAttachPin(ENABLE_R_PIN), PWM_CHANNEL);
ledcAttachPin(ENABLE_L_PIN), PWM_CHANNEL);
//Produce a PWM signal to both enable pins
ledcWrite(PWM_CHANNEL, dutycycle);

}

void loop() {
  // put your main code here, to run repeatedly:
dutCycle = 200;
ledcWrite(PWM_CHANNEL, dutyCycle);
sequence();
}
