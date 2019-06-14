int enableA = 6;
int pinA1 = 3;
int pinA2 = 7;

int enableB = 5;
int pinB1 = 4;
int pinB2 = 8;

int val = 0;
void setup()
{
  pinMode (enableA, OUTPUT);
  pinMode (pinA1, OUTPUT);
  pinMode (pinA2, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (pinB1, OUTPUT);
  pinMode (pinB2, OUTPUT);

  motorAon();
  motorBon();
  Serial.begin(9600);

  analogWrite (enableB, 130);
  analogWrite (enableA, 130);
}

void loop()
{
  car();
}

void car()
{
  if (Serial.available() > 0)
  {
    val = Serial.read();
    if (val == 'L')
    {
      left();
    }
    else if (val == 'R')
    {
      right();
    }

    else //(val == 'S')
    {
      coast();
    }
  }
}

void motorAforward()
{
  digitalWrite (pinA1, HIGH);
  digitalWrite (pinA2, LOW);
}

void motorBforward()
{
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, HIGH);
}

void motorAbackward()
{
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, HIGH);
}

void motorBbackward()
{
  digitalWrite (pinB1, HIGH);
  digitalWrite (pinB2, LOW);
}

void motorAstop()
{
  digitalWrite (pinA1, HIGH);
  digitalWrite (pinA2, HIGH);
}

void motorBstop()
{
  digitalWrite (pinB1, HIGH);
  digitalWrite (pinB2, HIGH);
}

void motorAcoast()
{
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, LOW);
}

void motorBcoast()
{
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, LOW);
}

void motorAon()
{
  digitalWrite (enableA, HIGH);
}

void motorBon()
{
  digitalWrite (enableB, HIGH);
}

void motorAoff()
{
  digitalWrite (enableA, LOW);
}

void motorBoff()
{
  digitalWrite (enableB, LOW);
}



void forward ()
{
  motorAforward();
  motorBforward();
}

void backward (int duration)
{
  motorAbackward();
  motorBbackward();
  delay (duration);
}

void right ()
{
  motorAbackward();
  motorBforward();
}

void left ()
{
  motorAforward();
  motorBbackward();
}

void coast ()
{
  motorAcoast();
  motorBcoast();
}

void breakRobot () //остановка
{
  motorAstop();
  motorBstop();
}

void disableMotors()
{
  motorAoff();
  motorBoff();
}

void enableMotors()
{
  motorAon();
  motorBon();
}

void avoid()
{
  //backward(500);
  //  right(360);
}
