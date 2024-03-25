#include <SoftwareSerial.h>

SoftwareSerial bt(11,10); //tx,rx

int lastState=0;

void setup()

{
  pinMode(7,INPUT);
  Serial.begin(9600);
  bt.begin(9600);  
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}

void loop()

{
  if (bt.available())
  {
    
    Serial.write(bt.read());
    
  }
  
  if(digitalRead(7)!=lastState)

{
  lastState = digitalRead(7);
  Serial.print("state changed to ");
  Serial.println(lastState);
}
  if (Serial.available())
  {
    bt.write(Serial.read());
  }
}

