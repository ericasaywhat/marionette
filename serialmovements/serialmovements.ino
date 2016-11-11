#include<Servo.h>

Servo arm1;
Servo arm2;
Servo legs;


int pos = 0;
int pos2 = 0;
int legPos;
int legPos1;
unsigned long startTime;
unsigned long endTime;
String command;
int duration;

void setup () {
  // start serial communication.
  Serial.begin (9600);

  arm1.attach(9);
  arm2.attach(11);
  legs.attach(10);
}

void loop () {
    arm1.write(170);
    arm2.write(0);
    legs.write(135);
  while(Serial.available()>0) { 
    String input = Serial.readString();

    command = input.substring(0,input.indexOf(','));
    duration = input.substring(input.indexOf(',')+1).toInt();
    
  }
  if (command == "walk") {
    startTime = millis();
    Serial.print("wagao");
    while (millis() < startTime + duration*1000) {
        walk(arm1,arm2,legs);      
    }
    rest(arm1,arm2,legs);
    command = "";
  }
  
}

int walk(Servo servo1, Servo servo2, Servo servo3) {
  legPos = 180;
  legPos1 = 95;

  for (pos = 90; pos <= 180; pos += 1) {       // goes from 0 degrees to 180 degrees
      
      servo1.write(pos);
      servo2.write(pos-90);
      servo3.write(legPos);
      legPos -= 1;
      delay(15); 
  }
    for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      servo2.write(pos-90);
      servo3.write(legPos1);
      legPos1 += 1;
      delay(15);                       // waits 15ms for the servo to reach the position
      
  }

  
}

void rest(Servo servo1, Servo servo2, Servo servo3) {
  int servo1Pos = servo1.read();
  int servo2Pos = servo2.read();
 
    if (servo1Pos<170) {
      for (servo1Pos; servo1Pos <= 170; pos++) {
        servo1.write(pos);
        if (servo2Pos != 0) {
          servo2Pos--;
          servo2.write(servo2Pos);
        }
     }
    } else if (servo1Pos>170) {
        for (servo1Pos; servo1Pos >= 170; pos--) {
          servo1.write(pos);
          if (servo2Pos != 0) {
            servo2Pos--;
            servo2.write(servo2Pos);
          } 
        }
      } else {
          if (servo2Pos != 0) {
            servo2Pos--;
            servo2.write(servo2Pos);
          } 
      }
}

void legswalk(Servo servo) {

  for (pos = 95; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 95; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}

