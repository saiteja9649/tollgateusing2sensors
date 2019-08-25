#include <Servo.h>
Servo myservo;
int const trigPin = A1;
int const echoPin = A0;
int pos =0;
int i;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, INPUT);
  myservo.attach(9);
  Serial.begin(115200);
  myservo.write(0);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
   i = digitalRead(4);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if(distance < 10 && i == 1)
{
  pos = myservo.read();
  if(pos == 0)
  {
    for (pos = 0; pos <= 90; pos += 1) 
  {      
    myservo.write(pos);     
            delay(10);                        
  }     
//    delay(2000);                              
  }
 }
else 
{  
  if(i== 0 && distance >10)
  {
    delay(500);
    myservo.write(0);
  }
}
}

     
