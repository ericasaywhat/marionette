#include<Servo.h>

Servo arm1;
Servo arm2;
Servo leg1;
Servo leg2;


String cmd = "";
int pos = 0;
int pos2 = 0;

void setup () {
  // start serial communication.
  Serial.begin (9600);

  arm1.attach(9);
  arm2.attach(10);


}

void loop () {
  arm1.write(0);
  arm2.write(0);
  
  while(Serial.available()>0) { 
    char input = Serial.read();
    cmd.concat(input);
  }
  
    if (cmd == "walk") {
      armswing(arm1,arm2);
    } 
}

void armswing(Servo servo1, Servo servo2) {
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          servo1.write(pos);
          servo2.write(pos);
          delay(15); 
       
      }
}

