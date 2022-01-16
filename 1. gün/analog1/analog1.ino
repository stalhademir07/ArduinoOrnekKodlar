int ledPin = 9;     
int analogPin = 3;   
int val = 0;  
void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  analogWrite(9, 0);
  delay(1000);
  analogWrite(9, 50);
  delay(1000);
  analogWrite(9, 100);
  delay(1000);
  analogWrite(9, 150);
  delay(1000);
  analogWrite(9, 200);
  delay(1000);

}
