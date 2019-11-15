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

    public:
        Robot();
        
        int GetAngle();
        int GetLine();

        void SetAngle(int angle);           //метод поворота
        void SetLine(int line);             //метод для линейного перемещения
};