#include <NewPing.h>  // The New Ping Library for The Ultrasonic Sensors

#define ForwardTrigPin 4  // defines for all Ultrasonic Sensors Pins
#define ForwardEchoPin 3

#define RightTrigPin 6
#define RightEchoPin 5

#define LeftTrigPin 8
#define LeftEchoPin 7

#define BackTrigPin 11
#define BackEchoPin 10


#define ForwardBuzzer A0
#define LeftBuzzer A1
#define RightBuzzer A2
#define BackBuzzer A3

const int MaxDistance = 300;  // Maximum distance for all Sensors

// Objects For all Ultrasonic Sensors

NewPing ForwardUltrasonic(ForwardTrigPin, ForwardEchoPin, MaxDistance);

NewPing RightUltrasonic(RightTrigPin, RightEchoPin, MaxDistance);

NewPing LeftUltrasonic(LeftTrigPin, LeftEchoPin, MaxDistance);

NewPing BackUltrasonic(BackTrigPin, BackEchoPin, MaxDistance);

#define DEBUG  // Undefined to Hide Serial Data

#include "classes.h"

BuzzerSounds Buzzers;
UltrasonicSensor Ultrasonic;

void setup() {

  Serial.println("Blinds Helper Project By Mutaz Lafi.");
  delay(500);

  Serial.println("Starting...");

#ifdef DEBUG
  Serial.begin(9600);
#endif

  Buzzers.begin();
}

void loop() {
  
  Buzzers.Buzzer('A', false);

  int ForwradUltrasonic = Ultrasonic.ReadForwrad();
  int RightUltrasonic = Ultrasonic.ReadRight();
  int LeftUltrasonic = Ultrasonic.ReadLeft();
  int BackUltrasonic = Ultrasonic.ReadBack();

  if (ForwradUltrasonic < 35) {
    Buzzers.Buzzer('F', true);
  }

  if (RightUltrasonic < 30) {
    Buzzers.Buzzer('R', true);
  }

  if (LeftUltrasonic < 30) {
    Buzzers.Buzzer('L', HIGH);
  }

  if (BackUltrasonic < 35) {
    Buzzers.Buzzer('B', true);
  }
}
