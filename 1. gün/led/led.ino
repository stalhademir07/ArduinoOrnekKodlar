const int led = 13;
const int button = 7;
int analogPin = A0;
int val = 0;
void setup() {
  pinMode (led, OUTPUT);
  pinMode (button, INPUT);
  Serial.begin(9600);


}

void loop() {
  if (digitalRead(button) == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  val = analogRead(analogPin);
  Serial.println(val);

}
