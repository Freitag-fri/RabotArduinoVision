int enableA = 6;
int pinA1 = 3;
int pinA2 = 7;

int enableB = 5;
int pinB1 = 4;
int pinB2 = 8;

#define trigPin 8
#define echoPin 9

void setup()
{
  pinMode (enableA, OUTPUT);
  pinMode (pinA1, OUTPUT);
  pinMode (pinA2, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (pinB1, OUTPUT);
  pinMode (pinB2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  car();
  avoid();
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



void forward (int duration)
{
  motorAforward();
  motorBforward();
  delay (duration);
}

void backward (int duration) 
{
  motorAbackward();
  motorBbackward();
  delay (duration);
}

void right (int duration) 
{
  motorAbackward();
  motorBforward();
  delay (duration);
}

void left (int duration) 
{
  motorAforward();
  motorBbackward();
  delay (duration);
}

void coast (int duration) 
{
  motorAcoast();
  motorBcoast();
  delay (duration);
}

void breakRobot (int duration) 
{
  motorAstop();
  motorBstop();
  delay (duration);
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

int distance() /////////////////////////////////////
{
  int duration, distance;

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(1000);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;

  return distance;

}

void car() 
{

}

void avoid()
{
  backward(500);
  right(360);
}
