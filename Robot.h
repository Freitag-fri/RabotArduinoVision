#pragma once

#include <Servo.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#include "Data.h"

class Robot
{
    private:
        ///задержка для поворота
        const int delayAngle = 100; 
        ///задержка для перемещения
        const int delayLine = 100;       

        ///( 132-525) поворот   (329 - 90градусов)
        int serv0 = 329; 
        ///( 200-460) чемь меньше, тем сильнее расскрывается (можно и меньше наверное)      
        int serv2 = 460;
        ///( 140-380) чемь меньше тем выше подымается        
        int serv4 = 380;
        ///( 95-330..) чемь меньше тем выше подымается //схват вниз вверх        
        int serv12 = 230; 
        //( 140-330..) на 120 зажат схват      
        int serv5 = 150;       

        int line = 0;


        Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

        ///обьект класса Data
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