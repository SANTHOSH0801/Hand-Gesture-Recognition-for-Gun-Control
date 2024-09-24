#include <Servo.h>  // Include the Servo library

Servo myServo;  // Create a Servo object to control a servo
int servoPin = 9;  // Pin connected to the servo motor

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud
  myServo.attach(servoPin);  // Attach the servo on pin 9 to the Servo object
  myServo.write(0);  // Set the servo to the 0-degree position initially
}

void loop() {
  // Check if there is any data available on the serial port
  if (Serial.available() > 0) {
    // Read the incoming string from the serial buffer
    String command = Serial.readString();
    
    // Trim any extra spaces or newlines
    command.trim();

    // Check if the command is "stop"
    if (command == "stop") {
      myServo.write(0);  // Set servo to 0 degrees (stop position)
      Serial.println("Command received: stop");
    }
    // Check if the command is "shoot"
    else if (command == "shoot") {
      myServo.write(90);  // Set servo to 90 degrees (shoot position)
      Serial.println("Command received: shoot");
    }
  }
}
