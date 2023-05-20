#include <NewPing.h>  // The New Ping Library for The Ultrasonic Sensors

#define ForwardTrigPin 4  // defines for all Ultrasonic Sensors Pins
#define ForwardEchoPin 3

#define BackTrigPin 6
#define BackEchoPin 5

#define RightTrigPin 11
#define RightEchoPin 10

#define LeftTrigPin 8
#define LeftEchoPin 7


#define ForwardBuzzer A0  // define the pins for the Buzzers
#define LeftBuzzer A1
#define RightBuzzer A2
#define BackBuzzer A3

const int MaxDistance = 300;  // Maximum distance for all Ultrasonic Sensors

// Objects For all Ultrasonic Sensors

NewPing ForwardUltrasonic(ForwardTrigPin, ForwardEchoPin, MaxDistance);

NewPing RightUltrasonic(RightTrigPin, RightEchoPin, MaxDistance);

NewPing LeftUltrasonic(LeftTrigPin, LeftEchoPin, MaxDistance);

NewPing BackUltrasonic(BackTrigPin, BackEchoPin, MaxDistance);

#define DEBUG  // Debug Define For Ddebug Serial Statments (Un define it to Hide Serial Debug)

#include "classes.h"  // include The The File classes.h That Contain classes

BuzzerSounds Buzzers;  //  Objects For classes
UltrasonicSensor Ultrasonic;

void setup() {  // Setup

  Serial.println("Blinds Helper Project By Mutaz Lafi.");
  delay(500);

  Serial.println("Starting...");

#ifdef DEBUG  // if Debug defined enable Serial Debugging
  Serial.begin(9600);
#endif

  Buzzers.begin();  // start the Buzzers

  
}

void loop() {  // void Loop

  Buzzers.Buzzer('A', false);  // turn all Buzzers off

  Serial.println("All Buzzers off");  // Debug Statement


  Serial.println("Getting Data From Ultrasonics Sensors.....");  // Debug statement

  int ForwradUltrasonic = Ultrasonic.ReadForwrad();  // Put All Ultrasonics Read Functions into intgers Variables
  int RightUltrasonic = Ultrasonic.ReadRight();
  int LeftUltrasonic = Ultrasonic.ReadLeft();
  int BackUltrasonic = Ultrasonic.ReadBack();

  Serial.println("Done.");  // Debug statement

  Serial.println("Checking Ultrasonic Data");  // Debug statement

  if (ForwradUltrasonic < 35) {  // Check every ultrasonic if it is less than the distance given to each ultrasonic
    Buzzers.Buzzer('F', true);

    Serial.println("Forwrad Buzzer : True");  // Debug statement

    delay(500);
  }

  if (RightUltrasonic < 35) {
    Buzzers.Buzzer('R', true);

    Serial.println("Right Buzzer : True");  // Debug statement

    delay(350);
  }

  if (LeftUltrasonic < 30) {
    Buzzers.Buzzer('L', true);

    Serial.println("Left Buzzer : True");  // Debug statement

    delay(200);
  }

  if (BackUltrasonic < 35) {
    Buzzers.Buzzer('B', true);

    Serial.println("Back Buzzer : True");  // Debug statement

    delay(100);
  }
}

// end of  Blind_Helper_Project.ino File //