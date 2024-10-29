#include <Servo.h>

Servo serv;
int inp = A0;
int del = 270;
int del1 = 10;
int flag=1;

void setup() {
  pinMode(inp , INPUT_PULLUP);
  serv.attach(9);
  Serial.begin(9600);                                                                                                                                                         
  serv.write(0);
}

void loop() {
   
  
  if(analogRead(inp) < 120)
  {

    if(flag == 1)
    {
      delay(del);
      Serial.println(analogRead(inp));
      serv.write(20);
      delay(200);
      flag=0;
      del = del-5;
    }
    
  }

  else
  {
    flag = 1;
  }
  serv.write(0);

}
