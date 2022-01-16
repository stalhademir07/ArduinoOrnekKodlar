const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;



void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  int yValue = analogRead(A1); // 0,1023
  int xValue = analogRead(A0); // 80,960

  yValue = map(yValue, 0, 1023, -255, 255);
  xValue = map(xValue, 80, 960, -100, 100);
  hareket(yValue, xValue);

  Serial.print("hiz: ");
  Serial.print(yValue);
  Serial.print(" ");
  Serial.print("fark: ");
  Serial.println(xValue);
}




void hareket(int hiz , int fark) {
  if (hiz > 20 && hiz < 256 ) {
    if (fark < -10) {
      analogWrite(in1 , hiz );
      digitalWrite(in2, LOW);
      analogWrite(in3 , hiz - abs(fark));
      digitalWrite(in4, LOW);
    } else if (fark > 10) {
      analogWrite(in1 , hiz - abs(fark) );
      digitalWrite(in2, LOW);
      analogWrite(in3 , hiz );
      digitalWrite(in4, LOW);
    } else {
      analogWrite(in1 , hiz );
      digitalWrite(in2, LOW);
      analogWrite(in3 , hiz );
      digitalWrite(in4, LOW);
    }
  } else if (hiz < -20 && hiz > -256) {
    if (fark < -10) {
      analogWrite(in2 , abs(hiz));
      digitalWrite(in1, LOW);
      analogWrite(in4 , abs(hiz) - abs(fark));
      digitalWrite(in3, LOW);
    } else if (fark > 10) {
      analogWrite(in2 , abs(hiz) - abs(fark));
      digitalWrite(in1, LOW);
      analogWrite(in4 , abs(hiz));
      digitalWrite(in3, LOW);
    } else {
      analogWrite(in2 , hiz );
      digitalWrite(in1, LOW);
      analogWrite(in4 , hiz );
      digitalWrite(in3, LOW);
    }
  }
  else {
    if (fark > 10) {
      analogWrite(in1 , map(fark, 10, 100, 0, 255));
      digitalWrite(in2, LOW);
      analogWrite(in3 , LOW);
      digitalWrite(in4, map(fark, 10, 100, 0, 255));
    } else if (fark < -10) {
      analogWrite(in2 , map(fark, -10, -100, 0, 255));
      digitalWrite(in1, LOW);
      analogWrite(in4 , LOW );
      digitalWrite(in3, map(fark, -10, -100, 0, 255));
    } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

    }

  }



}
