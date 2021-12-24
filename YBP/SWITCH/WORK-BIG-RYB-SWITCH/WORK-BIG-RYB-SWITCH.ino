#include <PRIZM.h>
#include <AFMotor.h>    
#include <NewPing.h>


AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int ro_velocity = 100;
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
         motor1.run(BACKWARD);   
         motor2.setSpeed(ro_velocity);
         motor2.run(BACKWARD);   
         motor3.setSpeed(ro_velocity); 
         motor3.run(FORWARD); 
         motor4.setSpeed(ro_velocity);
         motor4.run(FORWARD);
         delay(0);
}
void RIGHTURN(){

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
void RUNFORWARD(){
    motor1.setSpeed(0);
    motor1.run(RELEASE);   
    motor2.setSpeed(st_velocity);
    motor2.run(FORWARD);   
    motor3.setSpeed(0); 
    motor3.run(RELEASE); 
    motor4.setSpeed(st_velocity);
    motor4.run(FORWARD);
    delay(0); 
}
void RUNBACKWARD(){
    motor1.setSpeed(0);
    motor1.run(RELEASE);   
    motor2.setSpeed(st_velocity);
    motor2.run(BACKWARD);   
    motor3.setSpeed(0); 
    motor3.run(RELEASE); 
    motor4.setSpeed(st_velocity);
    motor4.run(BACKWARD);
    delay(0); 
}
void RUNLEFT(){
    motor1.setSpeed(st_velocity);
    motor1.run(FORWARD);   
    motor2.setSpeed(0);
    motor2.run(RELEASE);   
    motor3.setSpeed(st_velocity); 
    motor3.run(FORWARD); 
    motor4.setSpeed(0);
    motor4.run(RELEASE); 
}

void RUNRIGHT(){
    motor1.setSpeed(st_velocity);
    motor1.run(BACKWARD);   
    motor2.setSpeed(0);
    motor2.run(RELEASE);   
    motor3.setSpeed(st_velocity); 
    motor3.run(BACKWARD); 
    motor4.setSpeed(0);
    motor4.run(RELEASE); 
}
void WTOR(int LL,int RR){
    if (digitalRead(LL) == false and digitalRead(RR)== true){
      RIGHTURN();
      delay(st_velocity*1.5);
    }
    if (digitalRead(LL) == true and digitalRead(RR)== false){  
      LEFTURN();
      delay(st_velocity*1.5);
}
}

void STOP(){
    motor1.setSpeed(0);
    motor1.run(RELEASE);   
    motor2.setSpeed(0);
    motor2.run(RELEASE);   
    motor3.setSpeed(0); 
    motor3.run(RELEASE); 
    motor4.setSpeed(0);
    motor4.run(RELEASE);   
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
    Serial.println(distanceL);
/*
    if ((distance <= 20) and (distance != 0)){
      while((distance <= 20) and (distance != 0)){
        STOP();
      }
    }
    if ((distanceL <= 20) and (distanceL != 0)){
      while((distanceL <= 20) and (distanceL != 0)){
        STOP();
      }
    }
    if ((distanceR <= 20) and (distanceR != 0)){
      while((distanceR <= 20) and (distanceR != 0)){
        STOP();
      }
    }
*/  

WTOR(L_LINE, R_LINE);  
RUNFORWARD();
}
