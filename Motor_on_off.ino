int del = 3;
void setup() {
pinMode(8, OUTPUT);

}

void loop() {
 digitalWrite(8, HIGH);
 delay(del);
 digitalWrite(8, LOW);
 delay(del*4);
}
