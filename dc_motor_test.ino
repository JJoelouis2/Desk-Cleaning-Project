
#include <AFMotor.h>


AF_DCMotor motor2(2);


void setup() {


  motor2.setSpeed(255);


  motor2.run(RELEASE);

  
}

void loop() {
  
  
  
  motor2.run(FORWARD);

  delay(4000);

  motor2.run(RELEASE);

  delay(200);

  motor2.run(BACKWARD);


  delay(4000);

  motor2.run(RELEASE);

  delay(200);
 
 
}
