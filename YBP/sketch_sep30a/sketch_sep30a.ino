#include <AFMotor.h>     
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4); 

void setup() {
  
}

void loop() {
  motor1.run(FORWARD); // задаем движение назад
  motor2.run(FORWARD); // задаем движение назад
  motor3.run(FORWARD); // задаем движение назад
  motor4.run(FORWARD); // задаем движение назад
  motor1.setSpeed(200);   // задаем скорость движения
  motor2.setSpeed(200);   // задаем скорость движения
  motor3.setSpeed(200);   // задаем скорость движения
  motor4.setSpeed(200);   // задаем скорость движения

  delay(200);
            
  motor1.run(RELEASE);  
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  delay(400);
}
