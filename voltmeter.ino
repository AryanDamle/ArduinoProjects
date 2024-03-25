#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int inp = A0;
float inpvolt,avolt;
char prnt[40];
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);

  pinMode(inp , INPUT);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Loading......");
}

void loop()
{
  
  inpvolt = analogRead(inp);
  Serial.println(inpvolt);
  String str = "Voltage = ";
  avolt = (5 * inpvolt)/1024;
  str.concat(avolt); 
  
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  
  lcd.print(str);
 Serial.println(str);
  delay(1000);
}
