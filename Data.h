#pragma once
#include <Arduino.h>
#include <Servo.h>

class Data
{
private:
    ///позиция в массиве bufData
    int pos = 0; 
    ///закончили ли считывать  данные              
    bool checkRead = false; 
    //правильные ли данные    
    bool checkData = false;  
    //буфер для  считывания с консоли  
    char c;  
    //массив данных                   
    char bufData[13];            

    int angle;
    int line;
    int checkSum;

     ///проверяем на корректные данные
    void CheckData();

  public:
    ///заполняем массив
    void GetData();                     
    void PrintData();
    
    int GetAngle();
    int GetLine();
    ///правильные ли данные
    bool GetCheckData();   
};