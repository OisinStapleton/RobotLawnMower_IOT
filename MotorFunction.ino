int E1 = 26;
int M1 = 27;
int E2 = 32;
int M2 = 33;

void MotorFunction(){

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

  for(int value = 0 ; value <= 255; value+=5)
  {
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
    analogWrite(E1, value);
    analogWrite(E2, value);
    delay(30);
  }
}
