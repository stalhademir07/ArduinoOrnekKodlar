// Servo motor
#include <Servo.h>
Servo camServo; // kamera tabanını kontrol eden servo motoru adlandırma
int currentPIRposition = 0; // servonun geçerli açısını ayarlama

// LED durum
int LEDpin[] = {9, 10, 11, 12, 13}; // LED pin numaraları
int currentLEDpin = 9; // mevcut LED pini; yukarıdaki sıradaki ilk ile başlama

// PIR sensorü
int PIRpin[] = {2, 3, 4, 5, 6}; // PIR pin numaraları
int currentPIRpin = 2; // mevcut PIR pini; yukarıdaki sıradaki ilk ile başlama
int PIRprevState[] = {1, 1, 1, 1, 1}; // PIR'nin önceki durumu (0 = DÜŞÜK, 1 = YÜKSEK)
int PIRposition[] = {157, 117.75, 78.5, 39.25, 0}; // servo motor için açıları atayın (0-157, 5 PIR sensörü arasında eşit olarak dağıtılır)
boolean PIRstatus; // PIR sensörünün durumunu true veya false olarak ayarla



void setup()  {

  Serial.begin(9600);
  camServo.attach(7); // servo pini ata

  for (int p = 0; p < 5; p++)  { // tüm PIR sensörlerini INPUT olarak ayarla
    pinMode(PIRpin[p], INPUT);
  }

  for (int l = 0; l < 5; l++)  { // tüm LED'leri ÇIKIŞ olarak ayarla
    pinMode(LEDpin[l], OUTPUT);
  }


  Serial.print("PIR Sensörlerini Kalibre Etme ");
  for (int c = 0; c < 15; c++) { // PIR sensörlerini 15 saniye kalibre edin (sensörlerinize bağlı olarak 10-60 saniye arasında değişir)
    Serial.print(".");
    delay(1000);
  }
  Serial.println("PIR Sensoru Hazır");

  camServo.write(78.5); // Başlamak için servoyu orta konuma getirin

}

void loop()  {

  for (int PIR = 0; PIR < 5; PIR++) { // her PIR sensörü için bu döngüyü başlat
    currentPIRpin = PIRpin[PIR]; // 'for' döngüsünde mevcut PIR pinini mevcut numaraya ayarla
    currentLEDpin = LEDpin[PIR]; // 'for' döngüsünde mevcut LED pinini mevcut numaraya ayarla
    PIRstatus = digitalRead(currentPIRpin);

    if (PIRstatus == HIGH) { // mevcut PIR sensöründe hareket algılanırsa
      digitalWrite(currentLEDpin, HIGH); // ilgili LED'i aç
      if (PIRprevState[PIR] == 0) { // PIR sensörünün önceki durumu LOW ise
        if (currentPIRposition != currentPIRpin && PIRprevState[PIR] == 0) { // eğer yüksek PIR, mevcut PIR konumundan farklıysa, yeni konuma taşıyın
          camServo.write(PIRposition[PIR]);
          Serial.print("Current angle : ");
          Serial.println(PIRposition[PIR]);
          delay(50);
          currentPIRposition = currentPIRpin; // mevcut PIR konumunu aktif [PIR] pinine sıfırla
          PIRprevState[PIR] = 1; // önceki PIR durumunu HIGH olarak ayarla
        }
        PIRprevState[PIR] = 1; //  mevcut konum mevcut PIR piniyle aynıysa önceki PIR durumunu YÜKSEK olarak ayarlayın
      }
    }

    else  { //
      digitalWrite(currentLEDpin, LOW);  //led, sensörlerin çıkış pin durumunu görselleştirir
      PIRprevState[PIR] = 0;   // Önceki PIR durumunu DÜŞÜK olarak ayarla
    }

  }
}
