// A Motoru
int enA = 3;
int in1 = 5;
int in2 = 6;
// B Motoru
int enB = 11;
int in3 = 9;
int in4 = 10;
void setup() {
  //Tüm motor kontrol Pinlerini çıkışlara ayarlama
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Motorları Kapatma- Başlangıç Durumu
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

  //Motorların dönüş yönünü kontrol
  void directionControl() {
    //A-B Motorlarını çevirme

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    //Farklı Yönler
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    //Motoru Kapatma
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);


  }
  void speedControl() {
    //Motorları Açma
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    //Min Hızdan Max Hıza
    for (int i = 0; i < 256; i++); {
      analogWrite(enA, i);
      analogWrite(enB, i);
      delay(20);
    }
    //Max Hızadan  Min Hıza
    for (int i = 255; i >= 0; --i) {
      analogWrite(enA, i);
      analogWrite(enB, i);
      delay(20);
    }
    //Motor Kapatma
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
