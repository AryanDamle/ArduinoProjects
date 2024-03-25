int src1 = 4 , src2 = 8 , gnd1 = 7 , gnd2 = 12, del = 10000;

void setup() {
  pinMode(src1 , OUTPUT);
  pinMode(src2 , OUTPUT);
  pinMode(gnd1 , OUTPUT);
  pinMode(gnd2 , OUTPUT);

}

void loop() {
  digitalWrite(src1 , HIGH);
  digitalWrite(gnd2 , HIGH);
  digitalWrite(src2 , LOW);
  digitalWrite(gnd1 , LOW);

  delay(del);

   digitalWrite(src1 , LOW);
  digitalWrite(gnd2 , LOW);
  digitalWrite(src2 , HIGH);
  digitalWrite(gnd1 , HIGH);

  delay(del);
  
}
