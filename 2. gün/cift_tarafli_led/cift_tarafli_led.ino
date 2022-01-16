const int button = 12;
const int led = 2;
int buttonState = 0;


void setup() {
  pinMode (button, INPUT_PULLUP);
  pinMode (led, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  buttonState = digitalRead(button);
  Serial.println(digitalRead(button));


  if (buttonState == LOW) {
    for (int i = 2; i < 10; i++) {
      digitalWrite(i, HIGH);
      digitalWrite(11 - i, HIGH);
      delay(20);
      digitalWrite(i, LOW);
      digitalWrite(11 - i, LOW);
      delay(20);
    }
  } else {
    for (int i = 2; i < 10; i++) {
      digitalWrite(i, LOW);
    }
  }
}
