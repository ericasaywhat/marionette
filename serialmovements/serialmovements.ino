#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *arm1 = AFMS.getMotor(1);
Adafruit_DCMotor *legs = AFMS.getMotor(2);
Adafruit_DCMotor *arm2 = AFMS.getMotor(3);



unsigned long lastMillis = 0;
unsigned long currentMillis = 0;

String cmd = "";

void setup () {
  // start serial communication.
  Serial.begin (9600);
  
  AFMS.begin();  // create with the default frequency 1.6KHz

//  arm1->setSpeed(50);
//  arms->run(FORWARD);
//  // turn on motor
//  arms->run(RELEASE);

  arm2->setSpeed(50);
//  leg1->run(FORWARD);
//  // turn on motor
//  leg2->run(RELEASE);

  legs->setSpeed(50);
//  leg2->run(FORWARD);
//  // turn on motor
//  leg2->run(RELEASE);

}

// loop the main sketch.
void loop () {
  
  while(Serial.available()>0) {
    char input = Serial.read();
    cmd.concat(input);
  }
//    Serial.println(cmd);

    Serial.print("Last");
    Serial.println(lastMillis);
  
    if (cmd == "walk") {
//      arm1->run(FORWARD);
      arm2->run(FORWARD);
      currentMillis = millis();
      Serial.println(currentMillis);
        
      if (currentMillis - lastMillis > 500){
//        arm1->run(RELEASE);
        arm2->run(RELEASE);
        Serial.println("rewind");
      }

      currentMillis = millis();
      if (currentMillis - lastMillis > 500) {
//        arm1->run(BACKWARD);
        arm2->run(BACKWARD);

        Serial.println("stop walk");

        lastMillis = currentMillis;
        
      }


   
    
  



    
    
  }
  
}
