int rdng;
void setup() {

  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
rdng = analogRead(A0);

Serial.println(rdng);
  
}
