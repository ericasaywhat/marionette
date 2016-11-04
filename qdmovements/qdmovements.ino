#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <QueueArray.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *arms = AFMS.getMotor(1);
Adafruit_DCMotor *leg1 = AFMS.getMotor(2);
Adafruit_DCMotor *leg2 = AFMS.getMotor(3);                              //CHECK PORTS!!!


// declare an array of string commands.
String cmd[] = {"walk", "4", "wave", "2"};

// create a queue of characters.
QueueArray <String> queue;

// startup point entry (runs once).
void setup () {
  // start serial communication.
  Serial.begin (9600);
  AFMS.begin();  // create with the default frequency 1.6KHz

  arms->setSpeed(100);
//  arms->run(FORWARD);
//  // turn on motor
//  arms->run(RELEASE);

  leg1->setSpeed(100);
//  leg1->run(FORWARD);
//  // turn on motor
//  leg2->run(RELEASE);

  leg2->setSpeed(100);
//  leg2->run(FORWARD);
//  // turn on motor
//  leg2->run(RELEASE);

  // set the printer of the queue.
  queue.setPrinter (Serial);

  // enqueue all the strings to the queue.
  for (int i = 0; i < sizeof(cmd); i++) {
    queue.enqueue (cmd[i]);
    Serial.println(cmd[0]);
  }


  // dequeue all the message's characters from the queue.
  while (!queue.isEmpty ()) {
//    Serial.print (queue.dequeue ()/;
  }

  // print end of line character.
//  Serial.println ("*");/
}

// loop the main sketch.
void loop () {
  // nothing here.
}
