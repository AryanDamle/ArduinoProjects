float  distance , speed = 0.034;
double time;

#define Trig 4
#define Echo 2

void setup() {
  pinMode(Trig , OUTPUT);
  pinMode(Echo , INPUT);
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  digitalWrite(Trig , LOW);
  delayMicroseconds(2);
  digitalWrite(Trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  time = pulseIn(Echo , HIGH);

  distance = (speed * time )/2.0;
  //distance = distance / 10000.0;

  Serial.println(distance);
  delay(1000);
    

}
