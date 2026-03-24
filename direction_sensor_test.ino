#define LeftIR A5
#define RightIR A2

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

bool LeftState = HIGH;
bool RightState = HIGH;

void setup() {
  pinMode(LeftIR, INPUT);
  pinMode(RightIR, INPUT);

  motor1.setSpeed(100);
  motor1.run(RELEASE);

  motor2.setSpeed(100);
  motor2.run(RELEASE);

  motor3.setSpeed(100);
  motor3.run(RELEASE);

  motor4.setSpeed(100);
  motor4.run(RELEASE);

  delay(1000);
}
void loop() {
  LeftState = digitalRead(LeftIR);
  RightState = digitalRead(RightIR);

  // Nothing in front
  if (LeftState == LOW && RightState == LOW) {
    motor1.run(BACKWARD);  // This is right btw
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } 

  // Things to the right, turn left
  else if (LeftState == LOW && RightState == HIGH) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }

  // Things to the left, turn right
  else if (LeftState == LOW && RightState == HIGH) {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  
  // Blocked both ways, move backwards
  else if (LeftState == LOW && RightState == HIGH) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }

}
