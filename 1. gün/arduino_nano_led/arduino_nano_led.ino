const int BUTTON = 12;
const int led = 2;
int BUTTONstate = 0;
void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  BUTTONstate = digitalRead(BUTTON);
  Serial.println(digitalRead(BUTTON));
  if (BUTTONstate == LOW)
  {
    for (int i = 2; i < 10; i++) {
      digitalWrite(i, HIGH);
      delay(10);
    }
  }
  else {
    for (int i = 2 ; i < 10; i++ ) {
      digitalWrite(i, LOW);
      delay(50);
    }
  }
//  digitalWrite(3, HIGH);
//
//  digitalWrite(4, HIGH);
//
//  digitalWrite(5, HIGH);
//
//  digitalWrite(6, HIGH);
//
//  digitalWrite(7, HIGH);
//
//  digitalWrite(8, HIGH);
//
//  digitalWrite(9, HIGH);

}
