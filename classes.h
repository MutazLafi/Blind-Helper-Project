class BuzzerSounds {
public:

  void begin() {
    pinMode(ForwardBuzzer, OUTPUT);
    pinMode(RightBuzzer, OUTPUT);
    pinMode(LeftBuzzer, OUTPUT);
    pinMode(BackBuzzer, OUTPUT);

    Serial.println("Buzzers is Ready");
  }

  void Buzzer(char buzzer, bool Sound) {

    switch (buzzer) {
      case 'F':
        if (Sound == true)
          tone(ForwardBuzzer, 30);
        else if (Sound == false)
          tone(ForwardBuzzer, 0);
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
        if (Sound == true)
          tone(LeftBuzzer, 30);
        else if (Sound == false)
          digitalWrite(LeftBuzzer, LOW);

        digitalWrite(BackBuzzer, Sound);
        digitalWrite(RightBuzzer, Sound);
        digitalWrite(LeftBuzzer, LOW);
    }
  }
};


class UltrasonicSensor {
private:

  int ForwardCM = 0;
  int RightCM = 0;
  int LeftCM = 0;
  int BackCM = 0;
public:
  int ReadForwrad() {
    ForwardCM = ForwardUltrasonic.ping_cm();

    if (ForwardCM == 0)
      ForwardCM = 300;

    return ForwardCM;
  }

  int ReadRight() {
    RightCM = RightUltrasonic.ping_cm();

    if (RightCM == 0)
      RightCM = 300;

    return RightCM;
  }

  int ReadLeft() {
    LeftCM = LeftUltrasonic.ping_cm();

    if (LeftCM == 0)
      LeftCM = 300;
    
    return LeftCM;
  }

  int ReadBack() {
    BackCM = BackUltrasonic.ping_cm();

    if (BackCM == 0) {
      BackCM = 300;
    }
    return BackCM;
  }
};