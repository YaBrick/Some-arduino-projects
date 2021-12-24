#include <AFMotor.h>    
#include <NewPing.h>
 
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);
//Если что-то не так - попробуй консты убрать, а это добавить:

//#define PIN_TRIG 53
//#define PIN_ECHO 52     
//#define MAX_DISTANCE 200

const int PIN_TRIG = 53;
const int PIN_ECHO = 52;

const int PIN_TRIG_L = 50;
const int PIN_ECHO_L = 51;

const int PIN_TRIG_R = 48;
const int PIN_ECHO_R = 49;

const int MAX_DISTANCE = 100;

const int st_velocity = 80;
const int ro_velocity = 120;

NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

NewPing sonarL(PIN_TRIG_L, PIN_ECHO_L, MAX_DISTANCE);
NewPing sonarR(PIN_TRIG_R, PIN_ECHO_R, MAX_DISTANCE);


void setup(){
    Serial.begin(9600);
    motor1.setSpeed(0);
    motor1.run(RELEASE);   
    motor2.setSpeed(0);
    motor2.run(RELEASE);   
    motor3.setSpeed(0); 
    motor3.run(RELEASE);   
    motor4.setSpeed(0);
    motor4.run(RELEASE); 
}
void loop(){
   
    
    int distance = sonar.ping_cm();
    delayMicroseconds(10);
    int distanceL = sonarL.ping_cm();
    delayMicroseconds(10);
    int distanceR = sonarR.ping_cm();
    delayMicroseconds(10);
    Serial.println(distanceR);
//    Serial.println("distanceR is ");
//    Serial.println(distanceR);
    
    

        if ((distance >= 40) or (distance == 0)){
    motor1.setSpeed(st_velocity);
    motor1.run(FORWARD);   
    motor2.setSpeed(st_velocity);
    motor2.run(FORWARD);   
    motor3.setSpeed(st_velocity); 
    motor3.run(FORWARD); 
    motor4.setSpeed(st_velocity);
    motor4.run(FORWARD); }
    else{
    motor1.setSpeed(st_velocity);
    motor1.run(RELEASE);   
    motor2.setSpeed(st_velocity);
    motor2.run(RELEASE);   
    motor3.setSpeed(st_velocity); 
    motor3.run(RELEASE);   
    motor4.setSpeed(st_velocity);
    motor4.run(RELEASE);
       delay(20);
       if ((distanceR <= 20) and (distanceR != 0)){
         motor1.setSpeed(ro_velocity);
         motor1.run(BACKWARD);   
         motor2.setSpeed(ro_velocity);
         motor2.run(BACKWARD);   
         motor3.setSpeed(ro_velocity); 
         motor3.run(FORWARD); 
         motor4.setSpeed(ro_velocity);
         motor4.run(FORWARD);
       } 
       else{
      if ((distanceL <= 20) and (distanceL != 0)){
         motor1.setSpeed(ro_velocity);
         motor1.run(FORWARD);   
         motor2.setSpeed(ro_velocity);
         motor2.run(FORWARD);   
         motor3.setSpeed(ro_velocity); 
         motor3.run(BACKWARD); 
         motor4.setSpeed(ro_velocity);
         motor4.run(BACKWARD);
      }

       }
    }

}
                                                 
