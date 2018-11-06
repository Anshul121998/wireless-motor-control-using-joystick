#include <PWMServo.h>

PWMServo myservo;
PWMServo myservol;
PWMServo myservor;// create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(SERVO_PIN_A);
  myservol.attach(SERVO_PIN_B);
  myservor.attach(SERVO_PIN_C);// attaches the servo on pin 9 to the servo object
  //myservo.attach(SERVO_PIN_A, 1000, 2000); // some motors need min/max setting
}


void loop() {
  for(pos = 0; pos < 180; pos += 1) { // goes from 0 degrees to 180 degrees, 1 degree steps
    myservo.write(pos);
    myservor.write(pos);
    myservol.write(180-pos);
    delay(15);// tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  }
  for(pos = 180; pos>=1; pos-=1) {   // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    myservor.write(pos);
    myservol.write(180-pos);  
    delay(15);// waits 15ms for the servo to reach the position
  }
}

