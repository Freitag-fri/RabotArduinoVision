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
    SetAngle(90);
    SetLine(80);

    delay(500);
    ReleaseItem();
    SetLine(50);
    ControlPosition();  
  }
 }

void Robot::TakeItem()
{
  for( ; serv5 > 132; serv5 --)
  {
    pwm.setPWM(5, 0, serv5); 
    delay(delayTake);
  }
}

void Robot::ReleaseItem()
{
  for( ; serv5 < 160; serv5 ++)
  {
    pwm.setPWM(5, 0, serv5); 
    delay(delayTake);
  }
}


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

void Robot::ControlPosition()  
{
  SetLineControlPosition();
  SetAngle(0); 
}

void Robot::SetLineControlPosition()
{
  int way2 = serv2 - 410;
  int way4 = serv4 - 340;
  int way12 = serv12 - 190; 

  if(!way4 && way2)   //если 4-е звено в нужно позиции, а остальные нет
  {
    double koef12 = (double)way12 / way2;
    if(way2 > 0)
    {
      for (int i = 0 ; i < way2; i++)
      {
        pwm.setPWM(2, 0, serv2 - i);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное) 
        pwm.setPWM(12, 0, serv12 - i * koef12);
        delay(delayLine);
      }
    }

    else
    {
      for (int i = 0 ; i > way2; i--)
      {
        pwm.setPWM(2, 0, serv2 - i);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное) 
        pwm.setPWM(12, 0, serv12 - i * koef12);
        delay(delayLine);
      }
    }

    serv2 -= way2; 
    serv12 -= way2 * koef12;
  }

  else if(way4 && way2)
  {
    Serial.print(way4);
    double koef2 = (double)way2 / way4;
    double koef12 = (double)way12 / way4;

    if (way4 > 0)
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
      for (int i = 0 ; i > way4; i--)
      {
        pwm.setPWM(2, 0, serv2 - i * koef2);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
        pwm.setPWM(4, 0, serv4 - i);               // ( 140-380)        //чемь меньше тем выше подымается 
        pwm.setPWM(12, 0, serv12 - i * koef12);
        delay (delayLine);
      }
  }
    serv2 = serv2 - way4 * koef2;
    serv4 = serv4 - way4;
    serv12 = serv12 - way4 * koef12;
  }
}

void Robot::SetLine(int lineNew)
{
  int way2 = serv2 - (310 - lineNew * 0.35);
  int way4 = serv4 - (380 - lineNew);
  int way12 = serv12 - (95 + lineNew * 0.5); 

  if(!way4 && way2)   //если 4-е звено в нужно позиции, а остальные нет
  {
    Serial.print("test");
    double koef12 = (double)way12 / way2;
    if(way2 > 0)
    {
      for (int i = 0 ; i < way2; i++)
      {
        pwm.setPWM(2, 0, serv2 - i);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное) 
        pwm.setPWM(12, 0, serv12 - i * koef12);
        delay(delayLine);
      }
    }

    else
    {
      for (int i = 0 ; i > way2; i--)
      {
        pwm.setPWM(2, 0, serv2 - i);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное) 
        pwm.setPWM(12, 0, serv12 - i * koef12);
        delay(delayLine);
      }
    }

    serv2 -= way2; 
    serv12 -= way2 * koef12;
  }

  else if(way4 && way2)
  {
    Serial.print(way4);
    double koef2 = (double)way2 / way4;
    double koef12 = (double)way12 / way4;

    if (way4 > 0)
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
      for (int i = 0 ; i > way4; i--)
      {
        pwm.setPWM(2, 0, serv2 - i * koef2);        // ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
        pwm.setPWM(4, 0, serv4 - i);               // ( 140-380)        //чемь меньше тем выше подымается 
        pwm.setPWM(12, 0, serv12 - i * koef12);
        delay (delayLine);
      }
  }
  serv2 = serv2 - way4 * koef2;
  serv4 = serv4 - way4;
  serv12 = serv12 - way4 * koef12;
  }
}

int Robot::ConvertFromAngle(int angle)
{
  return map(angle, -90, 90, 132, 525);
}