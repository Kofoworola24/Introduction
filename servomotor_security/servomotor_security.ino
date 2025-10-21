#include <Servo.h>

Servo myServo;          // Create servo object
String inputName = "default_name";  // To store input from Serial Monitor

// Replace with your actual names
String name1 = "Kofo";     
String name2 = "Dubem";  // Change this to your teacher’s name

// Servo positions
int lockedPos = 0;       // Starting locked position
int unlockedPos = 90;    // Unlocked (open) position

void setup() {
  Serial.begin(9600);
  myServo.attach(9);     // Attach servo to digital pin 9
  myServo.write(lockedPos);
  Serial.println("=== SECURITY SYSTEM ACTIVE ===");
  Serial.println("Enter your name to unlock:");
}

void loop() {
  if (Serial.available() > 0) {
    inputName = Serial.readStringUntil('\n');
    inputName.trim();  // Remove extra spaces/newlines

    if (inputName == name1 || inputName == name2) {
      Serial.println("Access Granted");
      unlockDoor();
    } 
    else {
      Serial.println("Access Denied");
    }
  }
}

void unlockDoor() {
  // Move servo to unlocked position
  myServo.write(unlockedPos);
  Serial.println("Servo unlocked...");

  // Keep door open for 3 seconds
  delay(5000);

  // Return to locked position
  myServo.write(lockedPos);
  Serial.println("Servo locked again.");
}




