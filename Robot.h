#pragma once

//#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#include "Data.h"

class Robot
{
    private:
        ///задержка для поворота
        const int delayAngle = 15; 
        ///задержка для перемещения
        const int delayLine = 40; 
        ///задержка для взятия/отпускания детали
        const int delayTake = 60;      

        ///( 132-525) поворот   (329 - 90градусов)
        int serv0 = 329; 
        ///( 200-460) чемь меньше, тем сильнее расскрывается (можно и меньше наверное)      
        int serv2 = 450;  //450
        ///( 140-380) чемь меньше тем выше подымается        
        int serv4 = 370;    //370
        ///( 95-330..) чемь меньше тем выше подымается //схват вниз вверх        
        int serv12 = 230;   //230
        //( 140-330..) на 120 зажат схват      
        int serv5 = 160;       

        

        Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

        ///обьект класса Data
        Data data;
        

    public:

        void SettingServo();
        ///вызывает GetData класса Data
        void GetData();         
        void StartMove();
        void MoveServo();
        ///взять деталь
        void TakeItem();
        ///отпустить деталь
        void ReleaseItem();
        ///преобразование значение учла в значение серво
        int ConvertFromAngle(int angle);

        ///перевод робота в контрольную позицию
        void ControlPosition();
        ///перевод робота в контрольную позицию (линейный размер)
        void SetLineControlPosition();

        void SetAngle(int angle);           //метод поворота
        void SetLine(int line);             //метод для линейного перемещения

        void MoveLine(int way2, int way4, int way12);

        int arrLine[6] = {100, 103, 105, 40, 43, 45};       //не тестировал
        int arrAngle[6] = {90, 85, 80, 90, 85, 80};         //не тестировал
        int pos = 0;
};