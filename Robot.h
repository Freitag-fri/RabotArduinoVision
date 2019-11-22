#pragma once

#include <Servo.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#include "Data.h"

class Robot
{
    private:
        //int angle;  
          

        const int delayAngle = 100; 
        const int delayLine = 100;       

        int serv0 = 130;
        int serv2 = 460;
        int serv4 = 380;
        int serv12 = 230;
        int serv5 = 150; 

        int line = 0;


        Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
        Data data;
        

    public:

        void SettingServo();
        ///вызывает GetData класса Data
        void GetData();         
        void StartMove();
        void MoveServo();

        ///преобразование значение учла в значение серво
        int ConvertFromAngle(int angle);

        //int GetAngle();
        //int GetLine();

        void SetAngle(int angle);           //метод поворота
        void SetLine(int line);             //метод для линейного перемещения
};