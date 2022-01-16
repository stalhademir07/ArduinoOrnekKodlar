void setup() {
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);

}

void loop() {
  int oku = analogRead(A0);
  analogWrite(9, oku / 4);
  int yeniOku = map(oku, 0, 1023, 0, 255);
}
