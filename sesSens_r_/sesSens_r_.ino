int soundSensor = 2;
int led = 4;
boolean ledStatus = false;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  int SensorData = digitalRead(soundSensor);
  if (SensorData == 1) {

    if (ledStatus == false) {
      ledStatus = true;
      digitalWrite(led, HIGH);
    }
    else {
      ledStatus = false;
      digitalWrite(led, LOW);
    }
  }

}
