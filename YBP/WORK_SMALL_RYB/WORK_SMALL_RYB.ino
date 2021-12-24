#include <AFMotor.h>    
#include <NewPing.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int ro_velocity = 90;
int st_velocity = 160;

const int L_LINE = 38;
const int R_LINE = 40; 

const int PIN_TRIG = 53;
const int PIN_ECHO = 52;

const int PIN_TRIG_L = 50;
const int PIN_ECHO_L = 51;

const int PIN_TRIG_R = 48;
const int PIN_ECHO_R = 49;

const int MAX_DISTANCE = 100;



NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

NewPing sonarL(PIN_TRIG_L, PIN_ECHO_L, MAX_DISTANCE);
NewPing sonarR(PIN_TRIG_R, PIN_ECHO_R, MAX_DISTANCE);



void LEFTURN(){
         motor1.setSpeed(ro_velocity);
         motor1.run(FORWARD);   
         motor2.setSpeed(ro_velocity);
         motor2.run(FORWARD);   
         motor3.setSpeed(ro_velocity); 
         motor3.run(BACKWARD); 
         motor4.setSpeed(ro_velocity);
         motor4.run(BACKWARD);
         delay(0);
}
void RIGHTURN(){
         motor1.setSpeed(ro_velocity);
         motor1.run(BACKWARD);   
         motor2.setSpeed(ro_velocity);
         motor2.run(BACKWARD);   
         motor3.setSpeed(ro_velocity); 
         motor3.run(FORWARD); 
         motor4.setSpeed(ro_velocity);
         motor4.run(FORWARD);
         delay(0);
}
void RUNFORWARD(){
    int stvl = 60;
    motor1.setSpeed(stvl);
    motor1.run(FORWARD);   
    motor2.setSpeed(stvl);
    motor2.run(FORWARD);   
    motor3.setSpeed(stvl); 
    motor3.run(FORWARD); 
    motor4.setSpeed(stvl);
    motor4.run(FORWARD);
    delay(10); 
}

void setup(){
    Serial.begin(9600);
    pinMode(A7, INPUT);
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

    st_velocity = (analogRead(A7)/4);
    int distance = sonar.ping_cm();
    int distanceL = sonarL.ping_cm();
    int distanceR = sonarR.ping_cm();
    Serial.print(distanceL);
    Serial.print("      ");
    Serial.print(distance);
    Serial.print("      ");
    Serial.print(distanceR);
    Serial.print("\n");
 //   delayMicroseconds(20);

    motor1.setSpeed(st_velocity);
    motor1.run(FORWARD);   
    motor2.setSpeed(st_velocity);
    motor2.run(FORWARD);   
    motor3.setSpeed(st_velocity); 
    motor3.run(FORWARD);   
    motor4.setSpeed(st_velocity);
    motor4.run(FORWARD); 
/*
    if ((distanceR <= 20) and (distanceR != 0)){
      RIGHTURN();
       } 
    if ((distanceL <= 20) and (distanceL != 0)){
      LEFTURN();
      }
    if ((distanceL == distanceR <= 20) and (distanceL != 0) and (distanceR != 0)){
      RIGHTURN();
      delay(500);
  
    }
*/
    if (digitalRead(L_LINE) == false and digitalRead(R_LINE)== true){
      RIGHTURN();
    }
    
    if (digitalRead(L_LINE) == true and digitalRead(R_LINE)== false){  
      LEFTURN();
    }
    

}
