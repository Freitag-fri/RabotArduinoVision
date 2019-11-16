#pragma once

#include <Servo.h>
#include <Arduino.h>

#include "Data.h"

class Robot
{
    private:
        int angle;  
        int line;          

        Servo servoAngle;
        Servo servo2;
        Servo servo3;
        Servo servoGrab;

        Data data;

    public:

        void SettingServo();
        ///вызывает GetData класса Data
        void GetData();         
        void StartMove();
        void MoveServo();

        //int GetAngle();
        //int GetLine();

        void SetAngle(int angle);           //метод поворота
        void SetLine(int line);             //метод для линейного перемещения
};