#include <NewPing.h>  // The New Ping Library for The Ultrasonic Sensors

#define ForwardTrigPin 4  // defines for all Ultrasonic Sensors Pins
#define ForwardEchoPin 3

#define BackTrigPin 6
#define BackEchoPin 5

#define RightTrigPin 11
#define RightEchoPin 10

#define LeftTrigPin 8
#define LeftEchoPin 7


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
    delay(500);
  }

  if (RightUltrasonic < 30) {
    Buzzers.Buzzer('R', true);
    delay(350); 
  }

  if (LeftUltrasonic < 30) {
    Buzzers.Buzzer('L', true);
    delay(200);
  }

  if (BackUltrasonic < 35) {
    Buzzers.Buzzer('B', true);
    delay(100);
  }
}
