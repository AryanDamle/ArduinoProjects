int i=0;
char abyte;
char *toke[10];
const int length = 12;

void setup()
{
  Serial.begin(9600);
  delay(500);
}

void loop()
{
  char message[length];
  for(int ctr =0;ctr<length;ctr++)
  {
    message[ctr] = '\0';
  }

  i=0;
  Serial.readBytesUntil(';',message,length);

 // Serial.print("\nValue of i is, ");
  //Serial.print(i);
  //Serial.print("--- message is ");
  //Serial.print(message);
 i=0;
 toke[i]= strtok(message, ",");
 while(toke[i] != NULL&&i<10)
 {
   i++;
   toke[i] = strtok(NULL, ",");
 } 

  //Serial.print("\nAfter tockenizing Value of i is, ");
  //Serial.print(i);
 

  for(int j =0;j<i;j++)
  {
    Serial.println(toke[j]);

  }

}

bool IsEndOfLine(char ch)
{
  return (abyte==';' || abyte =='\0' || abyte=='\r' || abyte=='\r');
}

