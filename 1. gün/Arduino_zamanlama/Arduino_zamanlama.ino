unsigned long suanzaman;
unsigned long eskizaman = 0;
bool durum = false;
int aralik = 1000;

void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
suanzaman = millis();
Serial.println(suanzaman);
if (suanzaman - eskizaman > aralik){
  durum = !durum;
  eskizaman = suanzaman;
  }

  if (durum){
    digitalWrite(13,HIGH);
    }else{
      digitalWrite(13,LOW);
      }
}
