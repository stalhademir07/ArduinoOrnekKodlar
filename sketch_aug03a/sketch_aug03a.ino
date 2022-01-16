const int trig = 13;
const int echo = 12;

void setup() { 
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int gecenZaman = pulseIn(echo, HIGH);
  Serial.println(gecenZaman);
}
