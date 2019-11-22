#include "Robot.h"

void Robot::SettingServo()
{
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);
  pwm.setPWM(0, 0, serv0);        //( 125-527)
  pwm.setPWM(2, 0, serv2);        //4 ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
  pwm.setPWM(4, 0, serv4);        //4 ( 140-380)        //чемь меньше тем выше подымается 
  pwm.setPWM(12, 0, serv12);        //4 ( 95-330..)        //чемь меньше тем выше подымается //схват вниз вверх
  pwm.setPWM(5, 0, serv5);        //4 ( 140-330..)        //на 120 зажат //схват
}


 void Robot::GetData()
 {
   data.GetData();
 }
/*
 void Robot::StartMove()
 {
  if (data.GetCheckData())
  {
    MoveServo();                      //подезжаем к детали 

    delay (1000);
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
*/
void Robot::MoveServo()
{
  SetAngle(data.GetAngle());        //возможно переделать ( перенести data в robot) 
  SetLine(data.GetLine());
}

void Robot::SetAngle(int angleNew)      
{
  angleNew = ConvertFromAngle(angleNew);
  if (serv0 < angleNew)
  {
    for ( ; serv0 < angleNew; serv0++)
    {
      pwm.setPWM(0, 0, serv0);
      delay(delayAngle);
    }
  }

  else
  {
    for ( ; serv0 > angleNew; serv0--)
    {
      pwm.setPWM(0, 0, serv0);
      delay (delayAngle);
    }
  }

}


void Robot::SetLine(int lineNew)
{
  int way2 = serv2 - (310 - lineNew * 0.35);
  int way4 = serv4 - (380 - lineNew);
  int way12 = serv12 - (95 + lineNew * 0.5);

  double koef2 = (double)way2 / way4;
  double koef12 = (double)way12 / way4;

  if (line < lineNew)
  {
    for (int i = 0 ; i < way4; i++)
    {
      pwm.setPWM(2, 0, serv2 - i * koef2);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
      pwm.setPWM(4, 0, serv4 - i);               // ( 140-380)        //чемь меньше тем выше подымается 
      pwm.setPWM(12, 0, serv12 - i * koef12);
      delay(delayLine);
    }
  }

  else
  {
    for ( ; line > lineNew; line--)
    {
      pwm.setPWM(2, 0, serv2 - (lineNew - line) * koef2);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
      pwm.setPWM(4, 0, line);               // ( 140-380)        //чемь меньше тем выше подымается 
      //pwm.setPWM(12, 0, line * 0.5);
      delay (delayLine);
    }
  }
  serv2 = serv2 - way4 * koef2;
  serv4 = serv4 - way4;
  serv12 = serv12 - way4 * koef12;
}

int Robot::ConvertFromAngle(int angle)
{
  return map(angle, 0, 180, 125, 527);
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