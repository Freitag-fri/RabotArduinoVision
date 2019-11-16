#pragma once
#include "Robot.h"

Robot robot;

void setup()
{
  robot.SettingServo();
  Serial.begin(9600);
}

void loop()
{
  robot.GetData();      //получение данных
  robot.StartMove();    //если есть данные начинается движение

  while (Serial.available()) Serial.read();         // очистка ComPort
}
