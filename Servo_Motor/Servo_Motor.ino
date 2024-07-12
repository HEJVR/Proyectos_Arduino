#include <Servo.h>

Servo servo1;

int PinServo = 14;
int PulsorMin = 500;
int PulsorMax = 2600;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(PinServo, PulsorMin, PulsorMax);

}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(190); //open
  delay(2000);
  servo1.write(30);  //close
  delay(2000);
}
