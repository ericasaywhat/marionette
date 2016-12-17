#include <Adafruit_MotorShield.h>



Adafruit_MotorShield AFMStop(0x60); 
Adafruit_MotorShield AFMSbot(0x61);

Adafruit_StepperMotor *curtains = AFMStop.getStepper(200,2);
void setup() {
  AFMStop.begin();
  AFMSbot.begin();

  Serial.begin(9600);
  
  curtains->setSpeed(160);
  curtains->step(6, FORWARD, DOUBLE); 
 
}  
void loop() {
    

  Serial.println("Single coil steps");
//  curtains->step(100, FORWARD, SINGLE); 
//  curtains->step(100, BACKWARD, SINGLE); 
//
//  Serial.println("Double coil steps");
//  curtains->step(100, FORWARD, DOUBLE); 
//  curtains->step(100, BACKWARD, DOUBLE);
//  
//  Serial.println("Interleave coil steps");
//  curtains->step(100, FORWARD, INTERLEAVE); 
//  curtains->step(100, BACKWARD, INTERLEAVE); 
//  
//  Serial.println("Microstep steps");
//  curtains->step(50, FORWARD, MICROSTEP); 
//  curtains->step(50, BACKWARD, MICROSTEP);
  
}
