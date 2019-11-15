#include "Robot.h"

Robot::Robot()
{
    servoAngle.attach(7, 560, 3500);    //основа    (0-180)
    servo2.attach(5, 1000, 2270);        //линейный  (80-170)    //высота
    servo3.attach(6, 1000, 2200);       //линейный  (40 - 140)
    servoGrab.attach(8, 1000, 1500);    //захват    (75 - 100)
}


int Robot::GetAngle()
{
    return angle;
}
int Robot::GetLine()
{
    return line;
}

void Robot::SetAngle(int angleNew)      
{
  if (angle < angleNew)
  {
    for ( ; angle < angleNew; angle++)
    {
      servoAngle.write(90 + angle);
      delay(30);
    }
  }

  else
  {
    for ( ; angle > angleNew; angle--)
    {
      servoAngle.write(90 + angle);
      delay (30);
    }
  }

}
void Robot::SetLine(int lineNew)
{
  if (line < lineNew)
  {
    for ( ; line < lineNew; line++)
    {
      servo2.write(160 + line / 2.3);
      servo3.write(30 + line / 3);
      delay(50);
    }
  }

  else
  {
    for ( ; line > lineNew; line--)
    {
      servo2.write(160 + line / 2.3);
      servo3.write(30 + line / 3);
      delay (50);
    }
  }

}