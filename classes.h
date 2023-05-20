
// classes.h file that have classes inside it //


class BuzzerSounds {  // BuzzerSounds Class (For Buzzers)
public:

  void begin() {  // The Begin function to pinMode each Buzzer (Public Function)
    pinMode(ForwardBuzzer, OUTPUT);
    pinMode(RightBuzzer, OUTPUT);
    pinMode(LeftBuzzer, OUTPUT);
    pinMode(BackBuzzer, OUTPUT);

    Serial.println("Buzzers is Ready");  // Debug statement
  }

  void Buzzer(char buzzer, bool Sound) {  //  The Buzzer Function to control The Sound To each Buzzer (Public Function)

    switch (buzzer) {
      case 'F':
        digitalWrite(ForwardBuzzer, Sound);
        break;

      case 'B':
        digitalWrite(BackBuzzer, Sound);
        break;

      case 'R':
        digitalWrite(RightBuzzer, Sound);
        break;

      case 'L':
        digitalWrite(LeftBuzzer, Sound);
        break;

      case 'A':
        digitalWrite(ForwardBuzzer, Sound);
        digitalWrite(BackBuzzer, Sound);
        digitalWrite(RightBuzzer, Sound);
        digitalWrite(LeftBuzzer, Sound);
    }
  }
};


class UltrasonicSensor {  // class UltrasonicSensor (For Ultrasonic sensors)
private:

  int ForwardCM = 0;  // Some Private intgers Variables
  int RightCM = 0;
  int LeftCM = 0;
  int BackCM = 0;
public:
  int ReadForwrad() {  // ReadForward Function to Read The Forwrad Ultrasonic (Public Function)
    ForwardCM = ForwardUltrasonic.ping_cm();

    if (ForwardCM == 0)
      ForwardCM = 300;

    return ForwardCM;
  }

  int ReadRight() {  // ReadRight Function to Read The Right Ultrasonic  (Public Function)
    RightCM = RightUltrasonic.ping_cm();

    if (RightCM == 0)
      RightCM = 300;

    Serial.println(RightCM);

    return RightCM;
  }

  int ReadLeft() {  // ReadLeft Function to read The Left Ultrasonic Sensor (Public Function)
    LeftCM = LeftUltrasonic.ping_cm();

    if (LeftCM == 0)
      LeftCM = 300;

    return LeftCM;
  }

  int ReadBack() {  // ReadBack Function to Read The Back Ultrasonic Sensor (Public Function)
    BackCM = BackUltrasonic.ping_cm();

    if (BackCM == 0) {
      BackCM = 300;
    }

    return BackCM;
  }
};

// end of classes.h File