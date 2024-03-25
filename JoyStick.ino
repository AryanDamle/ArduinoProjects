int Xin = A1 , Yin = A2 , sw = 2;

void setup() 
{
  pinMode(Xin , INPUT_PULLUP);
  pinMode(Yin , INPUT_PULLUP);
  pinMode(sw , INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() 
{
  int x = analogRead(Xin);
  int y = analogRead(Yin);
  Serial.print(x);
  Serial.print(",");
  Serial.println(y);
  delay(100);

}
