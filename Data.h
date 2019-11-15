#pragma once
#include <Arduino.h>
#include <Servo.h>

class Data
{
private:
    int pos = 0;                //позиция в массиве bufData
    bool checkRead = false;     //считали ли данные
    bool checkData = false;     //правильные ли данные
    char c;                     //буфер для  считывания с консоли
    char bufData[13];            //массив данных

    int angle;
    int line;
    int checkSum;

  public:
    void GetData();             //заполняем массив
    void CheckData();           //проверяем на корректные данные
    void PrintData();
    
    int GetAngle();
    int GetLine();
    int GetCheckSum();
    bool GetCheckData();
};