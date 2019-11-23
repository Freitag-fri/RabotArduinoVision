#pragma once
#include "Robot.h"

void Foo();
void StartPos();

Robot robot;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#include <Adafruit_PWMServoDriver.h>

int serv0 = 130;
int serv2 = 460;
int serv4 = 380;
int serv12 = 230;
int serv5 = 150;

void setup()
{
  Serial.begin(9600);

  delay(1000);

  robot.SettingServo();

/*
  delay(2000);
  robot.SetLine(180);

  
  delay(2000);
  robot.SetLine(100);

  delay(2000);
  robot.SetLine(180);
  */
  /*

  delay(2000);
  robot.SetLine(100);
  delay(2000);
  robot.SetLine(150);
*/


/*
 Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);
  pwm.setPWM(0, 0, 130);    //( 120-470)
  pwm.setPWM(2, 0, 460);        //4 ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
  pwm.setPWM(4, 0, 380);        //4 ( 140-380)        //чемь меньше тем выше подымается 
  pwm.setPWM(12, 0, 230);        //4 ( 95-330..)        //чемь меньше тем выше подымается //схват вниз вверх
  pwm.setPWM(5, 0, 150);        //4 ( 140-330..)        //на 120 зажат //схват 

  delay(2000);

  StartPos();
  */
}

void loop()
{
  //Foo();
  //robot.GetData();      //получение данных
  //robot.StartMove();    //если есть данные начинается движение
  //robot.GetData();

  //while (Serial.available()) Serial.read();         // очистка ComPort
}

/*
void StartPos()
{
    for(; serv12 > 95; serv12--)
    {
       pwm.setPWM(12, 0, serv12);
       delay(20);
    }

    for(; serv2 > 310; serv2--)
    {
       pwm.setPWM(2, 0, serv2);
       delay(30);
    }
    
}

void Foo()
{
  for(int i = 0; i < 100; i++)
  {
    pwm.setPWM(2, 0, serv2-i * 0.35);        //4 ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
    pwm.setPWM(4, 0, serv4-i);        //4 ( 140-380)        //чемь меньше тем выше подымается 
    pwm.setPWM(12, 0, serv12+i * 0.5);      
    delay(50);
  }
  delay(2000);

  for(int i = 100; i > 0; i--)
  {
    pwm.setPWM(2, 0, serv2-i * 0.35);        //4 ( 200-460)        //чемь меньше, тем сильнее расскрывается (можно и меньше наверное)
    pwm.setPWM(4, 0, serv4-i);        //4 ( 140-380)        //чемь меньше тем выше подымается 
    pwm.setPWM(12, 0, serv12+i * 0.5);        
    delay(50);
  }
  delay(2000);
  
}
*/