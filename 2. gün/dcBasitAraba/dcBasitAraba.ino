const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;
int spd = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int joyX = A0;
  int joyY = A1;
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  int yValue = analogRead(joyY);
  yValue = map(yValue, 0, 1023, -255, 255);
  hareket(yValue);

}
void hareket(int hiz) {
  if (hiz > 20 && hiz < 256) {
    analogWrite(in1, hiz);
    digitalWrite(in2, LOW);
    analogWrite(in3, hiz);
    digitalWrite(in4, LOW);

  }
else if (hiz<-20&& hiz >-256){
  analogWrite(in2,hiz)
  }

}






void geri(int spd) {
  analogWrite(in1, spd);
  digitalWrite(in2, LOW);
  analogWrite(in3, spd);
  digitalWrite(in4, LOW);
}

void ileri(int spd) {
  analogWrite(in2, spd);
  digitalWrite(in1, LOW);
  analogWrite(in4, spd);
  digitalWrite(in3, LOW);
}

void dur (int spd) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}
void sag (int spd) {
  analogWrite(in1, spd);
  analogWrite(in4, spd);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
}

void sol (int spd) {
  digitalWrite(in1, LOW);
  digitalWrite(in4, LOW);
  analogWrite(in2, spd);
  analogWrite(in3, spd);
}
