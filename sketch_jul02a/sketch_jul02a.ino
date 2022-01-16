// A Motoru
int enA = 9;
int in1 = 8;
int in2 = 7;
// B Motoru
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
  // Motor Kontrol Pinleri Çıkışa Ayarlı
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Motorlar Kapalı- Başlangıç Konumu
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
}
  // Motorların Dönüş Yönü
  void directionControl(){
  //PWM için Değerler 0-255 Arasındadır
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  // A ve B Motorları Açık
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  // Motorlarrın yöleerini değiştir
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);
  // Motorları Kapat
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // Motor Hızı
  }
  void speedControl(){
  // Motorlar Açık
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // Min -> Max Hızlan
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  // Max -> Min Yavaşla
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  // Motorlar Kapalı
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
