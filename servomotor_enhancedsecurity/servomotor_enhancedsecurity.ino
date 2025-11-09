#include<Servo.h>

Servo kofoServo;

const int trigPin = 9;
const int echoPin = 10;
const int potPin = A0;
const int buzzer = 6;
const int servoPin = 7;

float duration;
int distance;
int sensitivity;
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
  kofoServo.attach(servoPin);
  kofoServo.write(0);  
}

void loop() {
 
  int potValue = analogRead(potPin);
  sensitivity = map(potValue, 0, 1023, 5, 100); 

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Sensitivity: ");
  Serial.println(sensitivity);

  if (distance <= sensitivity) {
        digitalWrite(buzzer, HIGH);
    for (pos = 0; pos <= 90; pos += 2) { 
      kofoServo.write(pos);
      delay(15);
    }
    delay(2000); 
    for (pos = 90; pos >= 0; pos -= 2) { 
      kofoServo.write(pos);
      delay(15);
    }
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(buzzer, LOW);
    kofoServo.write(0);
  }

  delay(200);
}

