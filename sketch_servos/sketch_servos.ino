#include <Servo.h>

Servo servo1;
Servo servo2;

#define trigPin 12
#define echoPin 13

int angle = 0;
boolean isPresenceDetected = false;

long int t;

void setup() {
  Serial.begin(9600);
  servo1.attach(11);
  servo2.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  t = millis();
}

void loop() {
  //put your main code here, to run repeatedly:

  if (isPresenceDetected == false) {
    if( millis() - t > 700){
      servo1.write(angle);
      t = millis();
      if (angle == 0) {
        angle = 180;
      } else {
        angle = 0;
      }
    }
    
    //Serial.println(angle);
//    delay(700);
    
    servo2.write(0);
  } else {
    
    servo2.write(180);
    Serial.println("yo");

  }


  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);

  if (distance < 20 && distance >= 0) {
    isPresenceDetected = true;

  }
  else {
    isPresenceDetected = false;
  }


}
