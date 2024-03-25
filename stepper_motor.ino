int in1=8,in2=7,in3=4,in4=2,del = 8,i=1;

void setup() 
{ 
 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  while(i<=512)
  {
    digitalWrite(in1 , HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
      delay(del);
    digitalWrite(in2 , HIGH);
    digitalWrite(in3 , LOW);
    digitalWrite(in4, LOW);
      delay(del);
    digitalWrite(in2, HIGH);
    digitalWrite(in3 , HIGH);
    digitalWrite(in1 , LOW);
      delay(del);
    digitalWrite(in3 , HIGH);
    digitalWrite(in4 , HIGH);
    digitalWrite(in2 , LOW);
     delay(del);
    i++;
     
   
  }

}

void loop() 
{
/*digitalWrite(in1 , HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
  delay(del);
digitalWrite(in2 , HIGH);
digitalWrite(in3 , LOW);
digitalWrite(in4, LOW);
  delay(del);
digitalWrite(in2, HIGH);
digitalWrite(in3 , HIGH);
digitalWrite(in1 , LOW);
  delay(del);
digitalWrite(in3 , HIGH);
digitalWrite(in4 , HIGH);
digitalWrite(in2 , LOW);
  delay(del);*/



}
