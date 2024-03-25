#include<IRremote.h>
int in1=10 , in2 = 9 , in3 = 8 , in4 = 7 , del = 2,inp=2;
IRrecv irrecv(inp);
decode_results sig;

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

       if(sig.value == 0xFF10EF )
       {
          digitalWrite(in1 , HIGH);
          digitalWrite(in2 , LOW);
          digitalWrite(in3 , HIGH);
          digitalWrite(in4 , LOW);
       }

       if(sig.value == 0xFF5AA5 )
       {
          digitalWrite(in2 , HIGH);
          digitalWrite(in1 , LOW);
          digitalWrite(in4 , HIGH);
          digitalWrite(in3 , LOW);
       }
        
        irrecv.resume();
    }
    
}
