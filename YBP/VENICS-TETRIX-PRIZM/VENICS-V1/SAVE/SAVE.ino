#include <Wire.h>
#include <String.h>
#include <Servo.h>
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

void pcommand(int x, String y, String z){
  Wire.begin();
  char buffer[5];
  Wire.beginTransmission(1);
  Wire.write(hexadecimalToDecimal(y));
  if (z != "no"){
    Wire.write(map((analogRead(A7)),0, 1024, 132, 384));
  }
  Serial.println(analogRead(A7));
  Wire.endTransmission();
}
void setup() {
  Wire.begin();
  Wire.beginTransmission(1);
  Wire.write(0x25);    
  Wire.endTransmission();
  Wire.beginTransmission(2);
  Wire.write(0x25);    
  Wire.endTransmission();
  Serial.begin(9600);
  MG995.attach(A5);
  delay(10);

}

void loop() {

  int inp1 = 40;
  int inp2 = analogRead(A7)/2;
  MG995.write(map(analogRead(A7), 0, 1024, 0, 180));
  pcommand(1, String(inp1), String(inp2));
  pcommand(2, String(inp1), String(inp2));

}
