#include <Servo.h>
#include <SoftwareSerial.h>
//0 - fwd , 1 - rwd
SoftwareSerial bt(11,10); //tx,rx

Servo servo_1;
Servo servo_2;
int del = 1000 , ctr=0;
float x , y;

void setup() 
{
servo_2.attach(2);
servo_1.attach(4);
Serial.begin(9600);
bt.begin(9600);
pinMode(7, OUTPUT);
}

void loop() {
 if(bt.available())
 {
  char data[100] ;
  int len =ReadFromBT(data) ;
  if(len > 0)
  {
    data[len] = '\0';
Serial.println(data);
  int deg = atoi(data);
  Serial.println(deg);
  servo_1.write(90);
  
 }

 delay(del);
}
}

int ReadFromBT(char * data)
{
  int ctr =0;
 char c = bt.read();

 while(c!='\0' && c!='\r' && c!='\n' && c != -1)
 {
    data[ctr] = c;
ctr++;
//Serial.println(c);
c = bt.read();


 }

return ctr;

}