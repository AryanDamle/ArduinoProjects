void setup() {
pinMode(30 , OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(30, HIGH);
delay(50);
digitalWrite(30 , LOW);
delay(500);
Serial.println("One cycle complete");
}
