int r = A0 , g = A1 , b = A2;
int i=255;
int del = 100;

void setup() 
{
    
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    analogWrite(r, i);
    
}
void loop() 
{
  rgb();
  
}

void rgb()
{
    for(i = 0; i <= 255; i++)
  {
    analogWrite(g, i);
    delay(del);
  }

  for(i = 255; i>=0 ; i--)
  {
    analogWrite(r, i);
    delay(del);
  }

  for(i = 0; i<= 255; i++)
  {
    analogWrite(b, i);
    delay(del);
  }

  for(i = 255; i >= 0 ; i--)
  {
    analogWrite(g, i);
    delay(del); 
  }

  for(i = 0; i<= 255 ; i++)
  {
    analogWrite(r , i);
    delay(del);
  }

  for(i = 255; i >=0 ; i--)
  {
    analogWrite(b, i);
    delay(del);
  }
}
