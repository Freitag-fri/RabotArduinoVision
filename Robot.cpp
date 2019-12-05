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

 void Robot::StartMove()
 {
  if (data.GetCheckData())
  {
    ControlPosition();
    MoveServo();                      //подезжаем к детали 
    TakeItem();
    delay(1000);
    ControlPosition();

    delay(500);
    //SetAngle(90);
    //SetLine(80);

    delay(500);
    ReleaseItem();
    //SetLine(50);
    ControlPosition();  
  }
 }

void Robot::TakeItem()
{
    if(serv5 > 132)
    {
      pwm.setPWM(5, 0, --serv5); 
    }
}

void Robot::ReleaseItem()
{
  if(serv5 < 160)
  {
    pwm.setPWM(5, 0, ++serv5); 
  }
}


void Robot::MoveServo()
{
  SetAngle();        //возможно переделать ( перенести data в robot) 
  //SetLine(data.GetLine());
}

void Robot::GetCoordinates()
{
  angleNew = ConvertFromAngle(data.GetAngle());
  lineNew = data.GetLine();
}

void Robot::SetAngle()      
{
  if (serv0 < angleNew)
  {
      pwm.setPWM(0, 0, ++serv0);
  }

  else if (serv0 > angleNew)
  {
      pwm.setPWM(0, 0, --serv0);
  }
}

void Robot::ControlPosition()  
{
  way1 =  410;
  way4 =  340;
  way12 = 190;

  angleNew = ConvertFromAngle(0);
}

void Robot::SetLine()
{
  way1 = 310 - lineNew * 0.35;
  way4 = 380 - lineNew;
  way12 = 95 + lineNew * 0.38; 
}

void Robot::MoveLine()
{
  Moveservo1();
  Moveservo2();
  Moveservo3();
}

void Robot::Moveservo1()
{
  if(serv2 < way1)
  {
    pwm.setPWM(2, 0, ++serv2);
  }
  else if(serv2 > way1)
  {
    pwm.setPWM(2, 0, --serv2);
  }
}

void Robot::Moveservo2()
{
  if(serv4 < way4)
  {
    pwm.setPWM(4, 0, ++serv4);
  }
  else if(serv4 > way4)
  {
    pwm.setPWM(4, 0, --serv4);
  }
}

void Robot::Moveservo3()
{
  if(serv12 < way12)
  {
    pwm.setPWM(12, 0, ++serv12);
  }
  else if(serv12 > way12)
  {
    pwm.setPWM(12, 0, --serv12);
  }  
}

int Robot::ConvertFromAngle(int angle)
{
  return map(angle, -90, 90, 132, 525);
}