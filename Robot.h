#pragma once

//#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#include "Data.h"


class Robot
{
    private:    
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
        
        int angleNew = ConvertFromAngle(60);
        int lineNew = 150;

        int way1;
        int way4;
        int way12;

        static const int sizeRrrAction = 10;
        //const int arrAction[sizeRrrAction] = {0, 1, 2, 1, 3, 0, 1, 4, 1, 5};
        const int arrAction[sizeRrrAction] = {0, 1, 2, 1, 3, 0, 1, 4, 1, 5};
        int posAction = 0;
        
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

        void SetAngle();           //метод поворота
        void SetLine();             //метод для линейного перемещения

        void GetCoordinates();
        void CoordinatesSetting();

        void MoveLine();

        void Moveservo1();
        void Moveservo2();
        void Moveservo3();
        unsigned long startTime = millis();

        int arrLine[6] = {100, 103, 105, 40, 43, 45};       //не тестировал
        int arrAngle[6] = {90, 85, 80, 90, 85, 80};         //не тестировал
        int pos = 0;

        void Robot::AddPosAction();
};