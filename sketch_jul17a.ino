#include <Servo.h>

#include <Servo.h>

Servo servoLeft;          // Define left servo
Servo servoRight;   
Servo servotop;
int JoyX = 0;
int JoyY = 1;
int Joyval;// Define right servo

void setup() { 
  servoLeft.attach(5);  // Set left servo to digital pin 10
  servoRight.attach(6); 
  servotop.attach(3);// Set right servo to digital pin 9
} 

void loop() {            // Loop through motion tests
  Joyval = analogRead(JoyX);
  Joyval = map(Joyval,0,1023,0,180);
  servoLeft.write(Joyval);  // Set left servo to digital pin 10
  servoRight.write(180-Joyval);

  Joyval = analogRead(JoyY);
  Joyval = map(Joyval,0,1023,0,180);
  servotop.write(Joyval);  // Set left servo to digital pin 10
  delay(15);
}

