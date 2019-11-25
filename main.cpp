#pragma once
#include "Robot.h"
#include <Adafruit_PWMServoDriver.h>

void Foo();
void StartPos();

Robot robot;

void setup()
{
  Serial.begin(9600);

  delay(1000);

  robot.SettingServo();
  delay(1000);
  robot.ControlPosition();
  delay(1000);
  robot.SetLine(70);
  robot.TakeItem();

  delay(1000);
  robot.ControlPosition();
  delay(1000);
  robot.SetAngle(90);
  delay(1000);
  robot.SetLine(100);

  delay(500);
  robot.ReleaseItem();
  
  delay(500);
  robot.SetLine(70);
  robot.ControlPosition();  
}

void loop()
{
  //Foo();
  //robot.GetData();      //получение данных
  //robot.StartMove();    //если есть данные начинается движение
  //robot.GetData();

  while (Serial.available()) Serial.read();         // очистка ComPort
}

/*

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