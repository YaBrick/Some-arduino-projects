#include <AFMotor.h>    

 
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);
#define L_LINE 38
#define R_LINE 39     
const int MAX_DISTANCE = 100;

const int st_velocity = 220;
const int ro_velocity = 0;
void setup() {
    Serial.begin(9600);
    motor1.setSpeed(st_velocity);
    motor1.run(RELEASE);   
    motor2.setSpeed(st_velocity);
    motor2.run(RELEASE);   
    motor3.setSpeed(st_velocity); 
    motor3.run(RELEASE);   
    motor4.setSpeed(st_velocity);
    motor4.run(RELEASE); 

}

void loop() {
    motor1.setSpeed(ro_velocity);
    motor1.run(BACKWARD);
    motor2.setSpeed(ro_velocity);
    motor2.run(BACKWARD);
    motor3.setSpeed(ro_velocity); 
    motor3.run(BACKWARD);
    motor4.setSpeed(ro_velocity);
    motor4.run(BACKWARD);
    delay(1);
    if (digitalRead(L_LINE == false) and digitalRead(R_LINE == false)){
    motor1.setSpeed(st_velocity);
    motor1.run(FORWARD);   
    motor2.setSpeed(st_velocity);
    motor2.run(FORWARD);   
    motor3.setSpeed(st_velocity); 
    motor3.run(FORWARD);   
    motor4.setSpeed(st_velocity);
    motor4.run(FORWARD); 
    }
    if (digitalRead(L_LINE)){
    motor1.setSpeed(0);
    motor1.run(RELEASE);   
    motor2.setSpeed(0);
    motor2.run(RELEASE);   
    motor3.setSpeed(st_velocity); 
    motor3.run(FORWARD);   
    motor4.setSpeed(st_velocity);
    motor4.run(FORWARD); }
    if (digitalRead(R_LINE)){
    motor1.setSpeed(st_velocity);
    motor1.run(FORWARD);   
    motor2.setSpeed(st_velocity);
    motor2.run(FORWARD);   
    motor3.setSpeed(st_velocity); 
    motor3.run(RELEASE);   
    motor4.setSpeed(st_velocity);
    motor4.run(RELEASE); }

}
