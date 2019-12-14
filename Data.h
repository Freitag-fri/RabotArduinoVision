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
    ///состояние робота (долден работать или нет)
    bool workData = false;  
    ///збраывание позиций установки деталей 
    bool resetPos = false;
    //буфер для  считывания с com port  
    char c;  
    //массив данных                   
    char bufData[13]; 
    //массив данных для общения с пк
    char bufData2[4];             

    int angle ;
    int line;
    int checkSum;
    
    

     ///проверяем на корректные данные
    void CheckCoordinates();
    void CheckData();

  public:
    void GetData();
    ///заполняем массив
    void GetCoordinates();                     
    void PrintData();
    
    int GetAngle();
    int GetLine();
    ///правильные ли данные
    bool GetCheckData();  
    ///устанавливает значение CheckData false
    void SetCheckDataFalse();

    bool GetWorkData();
    void GetSignal();
    void SetResetPosFalse();
    bool GetResetPos();
    
};