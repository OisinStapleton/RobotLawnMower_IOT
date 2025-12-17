// Code to test Motors by stepping through from low to high speed, then high to low speed.

#define E1 14
#define M1 27
#define E2 32
#define M2 33

#define PWM_FREQ 5000
#define PWM_RES 8

void setup()
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

  ledcAttach(E1, PWM_FREQ, PWM_RES);
  ledcAttach(E2, PWM_FREQ, PWM_RES);

  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
}

void loop()
{
  for(int value = 0; value <= 255; value += 5)
  {
    ledcWrite(E1, value);
    ledcWrite(E2, value);
    delay(30);
  }

  delay(1000);

  for(int value = 255; value >= 0; value -= 5)
  {
    ledcWrite(E1, value);
    ledcWrite(E2, value);
    delay(30);
  }

  delay(1000);
}
