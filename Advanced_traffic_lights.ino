/* program name: Advanced Traffic Lights
   Author: Aryan Damle
   Date: 5/4/2023 */


// r1 (pin 1), y1(pin2) and g1(pin3) corresponds to red yellow and green lights of signal 1
// r2(pin4), y2(pin5) and g2(pin6) corresponds to red yellow and green lights of signal 2
int r1 = 1, y1 = 2, g1 = 3, r2 = 4 , y2 = 5, g2 = 6;

// ir11(pin7), ir12(pin8), ir13(pin9) coresponds to three sensors for signal 1. ir11 corresponds to the sensor nearest to the crossing.
// ir21(pin10), ir22(pin11), ir23(pin12) coresponds to three sensors for signal 2. ir21 corresponds to the sensor nearest to the crossing.
int ir11 = 7 , ir12 = 8 , ir13 = 9 , ir21 = 10 , ir22 = 11 , ir23 = 12, sig;

// del1 (5 seconds) when no sensor active, del2(15 seconds) when only 1st sensor active, del3 (30 seconds) when first and second sensors active.
// if thirs sensor is active then it waits till it gets cleared.
long del1 = 5000;
long del2 = 15000; 
long del3 = 30000;
#define SIG1 0
#define SIG2 1

void setup() 
{

  
  pinMode(r1 , OUTPUT);
  pinMode(r2 , OUTPUT);
  pinMode(y1 , OUTPUT);
  pinMode(y2 , OUTPUT);
  pinMode(g1 , OUTPUT);
  pinMode(g2 , OUTPUT);


  pinMode(ir11 , INPUT);
  pinMode(ir12 , INPUT);
  pinMode(ir13 , INPUT);
  pinMode(ir21 , INPUT);
  pinMode(ir22 , INPUT);
  pinMode(ir23 , INPUT);
  
  // making both the signal red at start.
  digitalWrite(r1 , HIGH);
  digitalWrite(r2 , HIGH);
  delay(100);
}

void loop()
{
  default_system();
}

void default_system()
{
  
  delay(500);
  
  switchSignal(SIG1);
  if(digitalRead(ir11)==0) 
{
  delay(del1);
}
else if(digitalRead(ir12)==0)
{
  delay(del2);
}
else if(digitalRead(ir13)==0)
{
delay(del3);

}
else{
  while(digitalRead(ir13) ==1)
  {
delay(100);

  }

}




  yellow(SIG1);
  
  switchSignal(SIG2);
  if(digitalRead(ir21)==0)
{
  delay(del1);
}
else if(digitalRead(ir22)==0)
{
  delay(del2);
}
else if(digitalRead(ir23)==0)
{
delay(del3);

}
else{
  while(digitalRead(ir23) ==1)
  {
delay(100);

  }

}

  yellow(SIG2);
}


void switchSignal(int num)
{
  if(num == 0)
  {
    digitalWrite(r1 , HIGH);
    digitalWrite(g2 , HIGH);
  }
  else
  {
    digitalWrite(r2, HIGH);
    digitalWrite(g1 , HIGH);
  }

}

void yellow(int sig)
{
  digitalWrite(r1 , LOW);
  digitalWrite(r2 , LOW);
  digitalWrite(g1 , LOW);
  digitalWrite(g2 , LOW);
  if(sig ==0)
  {
  digitalWrite(y1 , HIGH);
  digitalWrite(y2 , LOW);
  }
  else
  {
   digitalWrite(y1 ,LOW);
   digitalWrite(y2 , HIGH);
  
  }
  delay(del1);
}

