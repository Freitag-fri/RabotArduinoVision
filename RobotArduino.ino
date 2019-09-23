int val = 0;
int angle = 0;

int valBuf = 0;
int angleBuf = 0;

#include <Servo.h>
Servo servoAngle;
Servo servo2;
Servo servo3;
Servo servoGrab;

void MoveServo(int angle, int val2);

char buf[4];
char buf2[4];
int pos_buf = 0;
bool data_ok = false;

int sost = 0;

int test = 0;


void setup()
{
  servoAngle.attach(7, 560, 3500);    //основа    (0-180)
  servo2.attach(5, 900, 2200);        //линейный  (80-170)    //высота
  servo3.attach(6, 1000, 2200);       //линейный  (40 - 140)
  servoGrab.attach(8, 1000, 1500);    //захват    (75 - 100)
  Serial.begin(9600);

  servoAngle.write(90);
  servo2.write(160);
  servo3.write(45);
  servoGrab.write (75);

}

//unsigned char c;    //старт програмы по цифре
//bool go = false;

void loop()
{
  /*
    c = Serial.read();
    if (c == '1')
    {
    go = true;
    }
    else if (c == ' ')
    {
    go = false;
    }

    if (go)
    {

    for (int i = 75; i < 100; i++)
    {
      servoGrab.write (i);
      delay (100);
    }
    }
  */


  unsigned char c;
  if ( Serial.available() > 0 && sost == 0)
  {
    c = Serial.read();
    if ( c == 'q') {
      buf[pos_buf] = 0;
      sost = 1;
      pos_buf = 0;
    }
    else buf[pos_buf++] = c;
  }

  else if ( Serial.available() > 0 && sost == 1)
  {
    c = Serial.read();
    if ( c == '\n') {
      buf2[pos_buf] = 0;
      data_ok = true;
    }
    else buf2[pos_buf++] = c;
  }

  if ( data_ok)
  {
    angleBuf = atoi(buf2); //str.toInt();
    valBuf = atoi(buf); //str.toInt();
    Serial.print( "buf: "); Serial.println(buf);
    Serial.print( "angleBuf: "); Serial.println(angleBuf);
    Serial.print( "valBuf: "); Serial.println(valBuf);

    MoveServo(angleBuf, valBuf);
    for(int i = 70; i <90; i++)
    { 
      servoGrab.write (i);
      delay (150);
    }
    delay (3000);
    MoveServo(0, 0);
    delay (1000);
    servoGrab.write (70);

    data_ok = false;
    pos_buf = 0;
    sost = 0;
  }
}

void MoveServo(int angleNew, int valNew)
{
  if (angle < angleNew)
  {
    for ( ; angle < angleNew; angle++)
    {
      servoAngle.write(90 + angle);
      delay(50);
    }
  }

  else
  {
    for ( ; angle > angleNew; angle--)
    {
      servoAngle.write(90 + angle);
      delay (50);
    }
  }

  if (val < valNew)
  {
    for ( ; val < valNew; val++)
    {
      servo2.write(160 + val / 2.1);
      servo3.write(45 + val * 0.7);
      delay(50);
    }
  }

  else
  {
    for ( ; val > valNew; val--)
    {
      servo2.write(160 + val / 2.1);
      servo3.write(45 + val * 0.7);
      delay (50);
    }
  }
}
