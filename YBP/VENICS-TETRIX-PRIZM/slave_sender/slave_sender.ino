#include <Wire.h>
#include <String.h>
#include <Servo.h>

int LEFT_INF = 38;
int RIGHT_INF = 40;
Servo MG995;
 
int hexadecimalToDecimal(String hexVal)
{
    int len = hexVal.length();
    int base = 1;
    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
            base = base * 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;
            base = base * 16;
        }
    }
    return dec_val;
}

void acommand(int x, String y, String z){
  Wire.begin();
  Wire.beginTransmission(1);
  Wire.write(hexadecimalToDecimal(y));
  if (z != "00"){
    Wire.write(hexadecimalToDecimal(z));
  }
  Serial.println(analogRead(A7));
  Wire.endTransmission();
}
void bcommand(int x, String y, String z, String d){
  Wire.begin();
  Wire.beginTransmission(1);
  Wire.write(hexadecimalToDecimal(y));
  if (z != "00"){
    Wire.write(hexadecimalToDecimal(z));
  }
  if (d != "00"){
    Wire.write(hexadecimalToDecimal(d));
  }
  Wire.endTransmission();
}
void setup() {
 
  MG995.attach(A5);
  Wire.begin();
  Wire.beginTransmission(1);
  Wire.write(0x25);
  Wire.endTransmission();
  Wire.beginTransmission(1);
  Wire.write(0x52);
  Wire.write(0x1);
  Wire.endTransmission();
  Serial.begin(9600);

  delay(10);

}

void loop() {
  int motorl = 40;
  int motorr = 41;
  int SPEED = 10;
  MG995.write(map(analogRead(A7), 0, 1024, 0, 180));

  bcommand(1, String(42), String(79), String(79));
  
  bcommand(1, String(43), String(1), String(5));
  bcommand(1, String(44), String(1), String(5));
  delay(1000);
  bcommand(1, String(42), String(79), String(79));
  acommand(1, String(43), String(0));
  acommand(1, String(44), String(0));
  delay(1000);
/*
  if (digitalRead(LEFT_INF) == 1  and digitalRead(RIGHT_INF) == 0){
    pcommand(1, String(motorr), String(SPEED));
    pcommand(1, String(51), String(1));
    pcommand(1, String(motorl), String(SPEED));
    pcommand(1, String(51), String(0));
    delay(500);
  }
  if (digitalRead(LEFT_INF) == 0 and digitalRead(RIGHT_INF) == 1){
    pcommand(1, String(motorl), String(SPEED));
    pcommand(1, String(52), String(0));
    pcommand(1, String(motorr), String(SPEED));
    pcommand(1, String(52), String(1));
    delay(500);
  }
  if (digitalRead(LEFT_INF) == 1 and digitalRead(RIGHT_INF) == 1){
    pcommand(1, String(motorl), String(SPEED));
    pcommand(1, String(motorr), String(SPEED));
  }
  else{
    pcommand(1, String(motorl), String(0));
    pcommand(1, String(motorr), String(0));    
  }
  //Wire.beginTransmission(1);
  //Wire.write(
  */
}
