#include <Servo.h>

Servo kofoservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  kofoservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
int servo_value;
int value_pont = analogRead(A0);
servo_value = map(value_pont, 0, 1023, 0, 180);
Serial.println(servo_value);
kofoservo.write(servo_value);
}
