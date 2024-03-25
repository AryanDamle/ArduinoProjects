int c[]={0,1,2,3,4,5,6,7} , r[]={8,9,10,11,12,13,A0,A1};
//i = Column , j = row
//row +ve , column -ve
int mtrx[8][8];

void setup()
{
  int a,b;
  for(a=0 ; a<8; a++)
  {
    pinMode(c[a] , OUTPUT);
    pinMode(r[a] , OUTPUT);
  }

  for(a=0 ; a<8 ; a++)
  {
    digitalWrite(c[a], HIGH);
    digitalWrite(r[a] , LOW);
  }

  for(a=0 ; a<8 ; a++ )
  {
    for (b=0; b<8; b++) 
    {
      mtrx[a][b]=0;
    }
  }
}

void loop()
{
  int a = 3 , b = 4, z=0;
  digitalWrite(c[a] , LOW);
  digitalWrite(c[b] , LOW);
  digitalWrite(r[a] , HIGH);
  digitalWrite(r[b] , HIGH);
  delay(100);
  
  for(z=1 ; z<4 ; z++)
  {
    a--;
    b++;
    digitalWrite(c[a] , LOW);
    digitalWrite(c[b] , LOW);
    digitalWrite(r[a] , HIGH);
    digitalWrite(r[b] , HIGH);
    delay(100);
  }

    for(z=1 ; z<4 ; z++)
  {

    digitalWrite(c[a] , HIGH);
    digitalWrite(c[b] ,HIGH);
    digitalWrite(r[a] , LOW);
    digitalWrite(r[b] , LOW);
    a++;
    b--;
    delay(100);
  }

}

void UpdateLed()
{
  int i,j;
  for(i=0 ; i<8 ; i++)
  {
    for(j=0 ; j<8 ; j++)
    {
      digitalWrite(c[i] , HIGH);
      digitalWrite(r[j] , LOW); 
    }
  }
  for(i=0 ; i<8 ; i++)
  {
    for(j=0 ; j<8 ; j++)
    {
      if(mtrx[i][j] == 1)
      {
        digitalWrite(c[i] , LOW);
        digitalWrite(r[j] , HIGH);
      }
    
    }
  }
  
}