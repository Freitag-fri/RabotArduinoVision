#pragma once
#include <Arduino.h>
#include <Servo.h>

class Data
{
private:
    ///позиция в массиве bufData
    int pos = 0; 
    ///считали ли данные               
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

  public:
    ///заполняем массив
    void GetData();             
    ///проверяем на корректные данные
    void CheckData();           
    void PrintData();
    
    int GetAngle();
    int GetLine();
    //int GetCheckSum();
    bool GetCheckData();
};