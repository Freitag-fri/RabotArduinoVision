#include "Robot.h"

void Robot::SettingServo()
{
    servoAngle.attach(7, 560, 3500);    //основа    (0-180)
    servo2.attach(5, 1000, 2270);        //линейный  (80-170)    //высота
    servo3.attach(6, 1000, 2200);       //линейный  (40 - 140)
    servoGrab.attach(8, 1000, 1500);    //захват    (75 - 100)

  servoAngle.write(90);
  servo2.write(160);
  servo3.write(30);
  servoGrab.write (75);
}


 void Robot::GetData()
 {
   data.GetData();
 }

 void Robot::StartMove()
 {
   if (data.GetCheckData())
  {
    MoveServo();
    for (int i = 70; i < 90; i++)     //захват детали
    {
      servoGrab.write (i);
      delay (150);
    }

    delay (1000);
    MoveServo();
    delay (1000);
    servoGrab.write (70);
    delay (2000);
  }
 }

void Robot::MoveServo()
{
  SetAngle(data.GetAngle());        //возможно переделать ( перенести data в robot) 
  SetLine(data.GetLine());
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

/*
int Robot::GetAngle()
{
  return angle;
}
int Robot::GetLine()
{
    return line;
}
*/