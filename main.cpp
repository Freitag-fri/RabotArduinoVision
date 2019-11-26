#pragma once
#include "Robot.h"
#include <Adafruit_PWMServoDriver.h>

void Foo();
void StartPos();

Robot robot;

void setup()
{
  Serial.begin(9600);
  while (Serial.available()) Serial.read();         // очистка ComPort
  delay(1000);

  robot.SettingServo();
  delay(1000);
}

void loop()
{
  robot.GetData();      //получение данных
  robot.StartMove();    //если есть данные начинается движение

  while (Serial.available()) Serial.read();         // очистка ComPort
}