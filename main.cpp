#pragma once
#include "Data.h"
#include "Robot.h"




Data data;
Robot robot;


void MoveServo();


void setup()
{
  Serial.begin(9600);

  //servoAngle.write(90);
  //servo2.write(160);
  //servo3.write(30);
  //servoGrab.write (75);
}

void loop()
{
  //StartMove(Checkdata());
  while (Serial.available()) Serial.read();         // очистка ComPort
}



void StartMove()
{
  if (data.GetCheckData())
  {
    MoveServo();
    for (int i = 70; i < 90; i++)     //захват детали
    {
      //servoGrab.write (i);
      delay (150);
    }

    delay (3000);
    MoveServo();
    delay (1000);
    //servoGrab.write (70);
    delay (5000);
  }
}

void MoveServo()
{
  robot.SetAngle(data.GetAngle());        //возможно переделать ( перенести data в robot)
  
  robot.SetLine(data.GetLine());
  
}

