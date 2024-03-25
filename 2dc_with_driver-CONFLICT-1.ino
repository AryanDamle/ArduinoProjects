#include <IRremote.hpp>

int in1=10 , in2 = 9 , in3 = 8 , in4 = 7 , del = 2000,inp=2;
IRrecv irrecv(inp);
decode_results sig;

enum Direction
{
FWD = 0,
RVR = 1,
};


void setup() 
{
 pinMode(in1 , OUTPUT);
 pinMode(in2 , OUTPUT);
 pinMode(in3 , OUTPUT);
 pinMode(in4 , OUTPUT);
 digitalWrite(in1 , LOW);
 digitalWrite(in2 , LOW);
 digitalWrite(in3 , LOW);
 digitalWrite(in4 , LOW);
 Serial.begin(9600);
 irrecv.enableIRIn();

}

void loop() 
{
  if(irrecv.decode(&sig))
  {
    Serial.println(sig.value , HEX);
    if(sig.value==0xFF18E7)
    {
      forward();
    }

    if(sig.value==0xFF4AB5)
    {
      backward();
    }

    if(sig.value==0xFF5AA5)
    {
      right();
    }

    if(sig.value==0xFF10EF)
    {
      left();
    }

    irrecv.resume();
   
  }
}

void MoveMtr1(int dir)
{
  if(dir == FWD)
  {
     digitalWrite(in1 , HIGH);
     digitalWrite(in2 , LOW);
     
  }
  else
  {
     digitalWrite(in1 , LOW);
     digitalWrite(in2 , HIGH);
     
  }  
}


void StopMtr1()
{
     digitalWrite(in1 , LOW);
     digitalWrite(in2 , LOW);
}


void MoveMtr2(int dir)
{
  if(dir == FWD)
  {
     digitalWrite(in3 , HIGH);
     digitalWrite(in4 , LOW);
     
  }
  else
  {
     digitalWrite(in3 , LOW);
     digitalWrite(in4 , HIGH);
     
  }  
}


void StopMtr2()
{
     digitalWrite(in3 , LOW);
     digitalWrite(in4 , LOW);
}




void forward()
{
  MoveMtr1(FWD);
  MoveMtr2(FWD);
  delay(del);
  StopMtr1();
  StopMtr2();
} 

void backward()
{
    
  MoveMtr1(RVR);
  MoveMtr2(RVR);
  delay(del);
  StopMtr1();
  StopMtr2();

}

void right()
{
  MoveMtr1(RVR);
  MoveMtr2(FWD);
  delay(del);
  StopMtr1();
  StopMtr2();
}

void left()
{
  MoveMtr1(FWD);
  MoveMtr2(RVR);
  delay(del);
  StopMtr1();
  StopMtr2();
}