// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!
int incomingByte = 0;
#include <AFMotor.h>

AF_DCMotor RightMotor(3);
AF_DCMotor LeftMotor(1);
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  // turn on motor
  RightMotor.setSpeed(200);
  LeftMotor.setSpeed(200);


  RightMotor.run(RELEASE);
  LeftMotor.run(RELEASE);
}

void loop() {
  uint8_t i;
  incomingByte = Serial.read();
  if (incomingByte == 119) {
    Serial.println("FORWARD");
    //w
    RightMotor.run(FORWARD);
    LeftMotor.run(FORWARD);
  }
  if (incomingByte == 97) {
    Serial.println("LEFT");
    //a
    RightMotor.run(BACKWARD);
    LeftMotor.run(FORWARD);
  }
  if (incomingByte == 115) {
    Serial.println("BACKWARD");
    //s
    RightMotor.run(BACKWARD);
    LeftMotor.run(BACKWARD);
  }
  if (incomingByte == 100) {
    Serial.println("RIGHT");
    //s
    RightMotor.run(BACKWARD);
    LeftMotor.run(FORWARD);
  }
  if (incomingByte == 113) {
    Serial.println("STOP");
    //d
    RightMotor.run(RELEASE);
    LeftMotor.run(RELEASE);
  }
}
