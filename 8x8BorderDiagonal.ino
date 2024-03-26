int c[]={0,1,2,3,4,5,6,7} , r[]={8,9,10,11,12,13,A0,A1} , del=250;
//i = Column , j = row
//row +ve , column -ve
int x=0 , y=0;
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

}

void loop()
{
  vertical(1);

  horizontal(1);

  vertical(2);

  horizontal(2);

  diagonal(1);

  vertical(2);

  diagonal(2);

  horizontal(2);

}

void vertical(int dir)
{
  int i;
  if(dir == 1)
  {
    digitalWrite(c[x], LOW);
    digitalWrite(c[x+1], LOW);
    while(y<7)
    {
      digitalWrite(r[y], HIGH);
      digitalWrite(r[y+1], HIGH);
      delay(del);
      digitalWrite(r[y], LOW);
      y++;
    }

  }
  
  if (dir == 2) 
  {
    digitalWrite(c[x], LOW);
    digitalWrite(c[x-1], LOW);
    while(y>0)
    {
      digitalWrite(r[y], HIGH);
      digitalWrite(r[y-1], HIGH);
      delay(del);
      digitalWrite(r[y], LOW);
      y--;
    }
  }

}

void horizontal(int dir)
{
  int i;
  if(dir == 1)
  {
    digitalWrite(r[y], HIGH);
    digitalWrite(r[y-1], HIGH);
    while(x<7)
    {
      digitalWrite(c[x], LOW);
      digitalWrite(c[x+1], LOW);
      delay(del);
      digitalWrite(c[x], HIGH);
      x++;
    }

  }
  if (dir == 2) 
  {
    digitalWrite(r[y], HIGH);
    digitalWrite(r[y+1], HIGH);
    while(x>0)
    {
      digitalWrite(c[x], LOW);
      digitalWrite(c[x-1], LOW);
      delay(del);
      digitalWrite(c[x], HIGH);
      x--;
    }
  }
}

void diagonal(int dir)
{
  int i;
  if(dir == 1)
  {

    while(y<7 && x<7)
    {
      digitalWrite(r[y], HIGH);
      digitalWrite(r[y+1], HIGH);
      digitalWrite(c[x], LOW);
      digitalWrite(c[x+1], LOW);
      delay(del);
      digitalWrite(r[y], LOW);
      digitalWrite(c[x], HIGH);
      y++;
      x++;
    }

  }
  
  if (dir == 2) 
  {
    while(y<7 && x>0)
    {
      digitalWrite(r[y], HIGH);
      digitalWrite(r[y+1], HIGH);
      digitalWrite(c[x], LOW);
      digitalWrite(c[x-1], LOW);
      delay(del);
      digitalWrite(r[y], LOW);
      digitalWrite(c[x], HIGH);
      y++;
      x--;
    }
  }
}