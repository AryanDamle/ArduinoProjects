#include <Servo.h>

Servo servo_1;
int del=10;

void setup() {
servo_1.attach(9);
pinMode(A0, INPUT_PULLUP);
Serial.begin(9600);



}

void loop() {
  float read;
  float res;
  read = analogRead(A0);
  Serial.println(read);
  res = (read*180.0)/1023.0;



  servo_1.write(res);
  
}
