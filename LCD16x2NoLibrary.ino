#include<Wire.h>



enum commands
 {
   lcd_on = 0x0F,
   clrscr = 0x01,
   cur_left = 0x04,
   cur_right = 0x06,
   returnHome = 0x02,
   disp_right = 0x05,
   disp_left = 0x07,
   disp_on_cur_off = 0x0C,
   disp_on_cur_blnk = 0x0E,
   lcd_off = 0x08,
   bit4 = 0x02
 };

 enum ascaii
 {
    num0 = 0x30,
    num1 = 0x31,
    num2 = 0x31,
    num3 = 0x33,
    num4 = 0x34,
    num5 = 0x35,
    num6 = 0x36,
    num7 = 0x37,
    num8 = 0x38,
    num9 = 0x39,
    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44,
    E = 0x45,
    F = 0x46,
    G = 0x47,
    H = 0x48,
    I = 0x49,
    J = 0x4A,
    K = 0x4B,
    L = 0x4C,
    M = 0x4D,
    N = 0x4E,
    O = 0x4F,
    P = 0x50,
    Q = 0x51,
    R = 0x52,
    S = 0x53,
    T = 0x54,
    U = 0x55,
    V = 0x56,
    W = 0x57,
    X = 0x58,
    Y = 0x59,
    Z = 0x5A,
    a = 0x61,
    b = 0x62,
    c = 0x63,
    d = 0x64,
    e = 0x65,
    f = 0x66,
    g = 0x67,
    h = 0x68,
    i = 0x69,
    j = 0x6A,
    k = 0x6B,
    l = 0x6C,
    m = 0x6D,
    n = 0x6E,
    o = 0x6F,
    p = 0x70,
    q = 0x71,
    r = 0x72,
    s = 0x73,
    t = 0x74,
    u = 0x75,
    v = 0x76,
    w = 0x77,
    x = 0x78,
    y = 0x79,
    z = 0x7A,
    plus = 0x2B,
    minus = 0x2D,

 };
 enum lctr
 {
  wr = 0,
  re = 2,
  cmd = 0,
  data = 1,
  en = 4,
 };
int del = 5, scl = 8 , sda = 7,del2 = 0.5;
void setup() 
{
// pinMode(scl, OUTPUT);
// pinMode(sda, OUTPUT);
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);
  //sendlcdcmd(bit4);
  //delay(del);
 
  //sendlcdcmd(0x0f);
  //delay(del);
 sendlcdcmd(0x30);
  delay(4);
  sendlcdcmd(0x30);
  delay(4);
  sendlcdcmd(0x30);
  delay(4);
  
  
  sendlcdcmd(0x20);
  delay(del);
  sendlcdcmd(0x28);
  delay(del);
  sendlcdcmd(0x08);
  delay(del);
  sendlcdcmd(0x01);
  delay(del);
  sendlcdcmd(0x04);
  delay(del);
  
  sendlcdcmd(0x0F);
  delay(del);
  
 }

void loop() 
{
/*  sendlcdcmd(bit4);
  delay(del);
 // sendlcdcmd(lcd_on);
 sendlcdcmd(0x0f);
  delay(del);
//  sendlcdcmd(clrscr);
  delay(del);
sendlcdcmd(clrscr);
delay(del2);*/
  
  sendlcddata(A);
  delay(del2);
  sendlcddata(B);
  delay(del2);
  sendlcddata(C);
  delay(del2);
  sendlcddata(D);
  delay(del2);
  sendlcddata(E);
  delay(del2);
  sendlcddata(F);
  delay(del2);
  


 // delay(10000);
 /* sendlcdcmd(cur_right);
  delay(del2);
  sendlcddata(r);
  delay(del2);
  sendlcdcmd(cur_right);
  delay(del2);
  sendlcddata(y);
  delay(del2);
  sendlcdcmd(cur_right);
  delay(del2);
  sendlcddata(a);
  delay(del2);
  sendlcdcmd(cur_right);
  delay(del2);
  sendlcddata(n);
  delay(del2); */
  delay(2000);
  
}
  


void sendlcdcmd(int cmand)
{

  
  int datalow, datahigh;

  datalow = (cmand << 4) & 0xF0;
  datahigh = cmand & 0xF0;

Wire.beginTransmission(0x27);

 Wire.write(datahigh | cmd | wr);
  delay(del);
  Wire.write(datahigh | cmd | wr | en);
  delay(del);
  Wire.write(datahigh | cmd | wr);
  delay(del);

  Wire.write(datalow | cmd | wr);
  delay(del);
  Wire.write(datalow | cmd | wr | en);
  delay(del);
  Wire.write(datalow | cmd | wr);
  delay(del);


 

   Wire.endTransmission(); 
}

void sendlcddata(int dta)
{
  int datalow, datahigh;

  datalow = (dta << 4) & 0xF0;
  datahigh = dta & 0xF0;

Wire.beginTransmission(0x27);



 

  
  Wire.write(datalow | data | wr);
  delay(del);
  Wire.write(datalow | data | wr | en);
  delay(del);
  Wire.write(datalow | data | wr);
  delay(del);

 Wire.write(datahigh | data | wr);
  delay(del);
  Wire.write(datahigh | data | wr | en);
  delay(del);
  Wire.write(datahigh | data | wr);
  delay(del);

  

   Wire.endTransmission(); 
}

/*
void writei2c(int address , int dta_wr)
{
    
    int i1,i2;
    unsigned char j1,j2,k1,k2,andmask1,andmask2;
    digitalWrite(sda , HIGH);
    delay(del);
    digitalWrite(scl , HIGH);
    delay(del);
    digitalWrite(sda , LOW);
    delay(del);
    digitalWrite(scl , LOW);
    delay(del);
    for (i1 = 7 ; i1 >=0 ; i1--)
    {
        j1 = i1;
        andmask1 = 1 << j1;
        k1 = address & andmask1;

        if (k1 == 0)
        {
           digitalWrite(sda , LOW);
           delay(del);
           digitalWrite(scl , HIGH);
           delay(del);
           digitalWrite(scl , LOW);
           delay(del);
           digitalWrite(sda , LOW);
           delay(del);
        }

        else
        {
          digitalWrite(sda , HIGH);
          delay(del);
          digitalWrite(scl , HIGH);
          delay(del);
          digitalWrite(scl , LOW);
          delay(del);
          digitalWrite(sda , LOW);
          delay(del);
        }
    }
    

    digitalWrite(scl , HIGH);
    delay(del);
    digitalWrite(scl , LOW);
    delay(del);

    for (i2 = 7 ; i2 >=0 ; i2--)
    {
        j2 = i2;
        andmask2 = 1 << j2;
        k2 = dta_wr & andmask2;

        if (k2 == 0)
        {
           digitalWrite(sda , LOW);
           delay(del);
           digitalWrite(scl , HIGH);
           delay(del);
           digitalWrite(scl , LOW);
           delay(del);
           digitalWrite(sda , LOW);
           delay(del);
        }

        else
        {
          digitalWrite(sda , HIGH);
          delay(del);
          digitalWrite(scl , HIGH);
          delay(del);
          digitalWrite(scl , LOW);
          delay(del);
          digitalWrite(sda , LOW);
          delay(del);
        }
    }

    digitalWrite(sda ,LOW);
    delay(del);
    digitalWrite(scl , HIGH);
    delay(del);
    digitalWrite(sda , HIGH);
    delay(del);
    digitalWrite(scl , LOW);
    delay(del);
    digitalWrite(sda , LOW);
    delay(del);
}*/
