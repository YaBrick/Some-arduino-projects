#include <AFMotor.h>     
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);
const uint8_t analog_Pin   = 7;                          
const double  division_ADC = 0.0048828125;               
      double  inputVoltage;                             
      double  distance_OBJ;                   
               
void setup(){
    Serial.begin(9600);
    motor1.setSpeed(200);
    motor1.run(RELEASE);   
    motor2.setSpeed(200);
    motor2.run(RELEASE);   
    motor3.setSpeed(200); 
    motor3.run(RELEASE);   
    motor4.setSpeed(200);
    motor4.run(RELEASE); 
}
void loop(){
    inputVoltage = analogRead(analog_Pin)*division_ADC;  
    distance_OBJ = 27.86*pow(inputVoltage, -1.15);      
    Serial.println(distance_OBJ);                       
    if (distance_OBJ >= 20){
    motor1.setSpeed(200);
    motor1.run(FORWARD);   
    motor2.setSpeed(200);
    motor2.run(FORWARD);   
    motor3.setSpeed(200); 
    motor3.run(FORWARD); 
    motor4.setSpeed(200);
    motor4.run(FORWARD); 
    }
    else{
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
}
                                                 
