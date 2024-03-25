#include<IRremote.h>

int inp = 2;
IRrecv irrecv(inp);
decode_results data;
void setup() 
{
  
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() 
{
    if(irrecv.decode(&data))
    {
       Serial.println(data.value , HEX);
       irrecv.resume();
    }
     
  
  
  
}
