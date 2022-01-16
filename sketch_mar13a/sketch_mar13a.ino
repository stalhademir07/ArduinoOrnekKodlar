#define trigPin 12
#define echoPin 13
#define ir1 7
#define ir2 6
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int duration, distance;
  int flag,val1,val2;
  val1=digitalRead(ir1);
  val2=digitalRead(ir2);
  Serial.println(val1);
  Serial.println(val2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);

if (distance >=20)
{
  delay(100);
  Serial.println("forward");
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(150);
  Serial.println("STOP");
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

if (distance<=20)
{
  if (val1==1 )
  {  
    Serial.print("turn right");
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(2000);
  }
  if (val2==1)
  {
    Serial.print("turn left");
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(500);
  }
}

if(distance<=10)
{
    Serial.print("rearrange back");
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(1000);  
    Serial.print("rearranged left");
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(100);
}

if (distance<=20)
{
   Serial.print("Algorithum");
   Serial.print("free right");
   digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);
   if(val2==0)
   {
    Serial.print("smart adjust");
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(500);
   }
 }
}
