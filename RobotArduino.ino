int val = 0;
int angle = 0;

int valBuf = 0;
int angleBuf = 0;

#include <Servo.h>
Servo servoAngle;
Servo servo2;
Servo servo3;
Servo servoGrab;

void MoveServo(int angle, int val2);

int pos_buf = 0;
bool data_ok = false;

int sost = 0;

int test = 0;
char bufNew[13];
int pos = 0;
bool check = false;

void setup()
{
  servoAngle.attach(7, 560, 3500);    //основа    (0-180)
  servo2.attach(5, 1000, 2270);        //линейный  (80-170)    //высота
  servo3.attach(6, 1000, 2200);       //линейный  (40 - 140)
  servoGrab.attach(8, 1000, 1500);    //захват    (75 - 100)
  Serial.begin(9600);

  servoAngle.write(90);
  servo2.write(160);
  servo3.write(30);
  servoGrab.write (75);
}

void loop()
{
  StartMove(Checkdata());
  while (Serial.available()) Serial.read();         // очистка ComPort
}

bool Checkdata()
{
  byte c;
  //a035b123c098
  delay(100);                               //без этого не работае :)

  while (Serial.available())
  {
    c = Serial.read();
    // Serial.println(c);
    if (c == 'a')
    {
      pos = 0;
      bufNew[pos++] = c;
      check = true;
    }
    else if (check && pos < 12)
    {
      bufNew[pos++] = c;
    }
  }
  if (check)
  {
    if (pos == 12 && bufNew[0] == 'a' && bufNew[4] == 'b' && bufNew[8] == 'c')
    {
      Serial.print( "arr data"); Serial.println(bufNew);

      bufNew[4] = 0;                                    //обнуляем ключи данный для отработки atoi(прообразование в int)
      bufNew[8] = 0;
      bufNew[12] = 0;

      int angleBuf = atoi(&bufNew[1]); //str.toInt();
      int valBuf = atoi(&bufNew[5]); //str.toInt();
      int valBuf2 = atoi(&bufNew[9]); //str.toInt();
      Serial.print( "buf3 =  "); Serial.println(angleBuf);
      Serial.print( "buf4 =  "); Serial.println(valBuf);
      Serial.print( "buf5 =  "); Serial.println(valBuf2);


      if (valBuf2 == angleBuf + valBuf)                         //проверка на корректность введенных значений
      {
        check = false;
        Serial.print("корректные даные \n");
        return true;
      }
      else
      {
        Serial.print("не корректные даные сумма не совподает  \n");
      }
    }
    else
    {
      Serial.print("не корректные даные неправильный формат  \n");
    }
    check = false;
  }
  return false;
}

void StartMove(bool checkData)
{
  if (checkData)
  {
    MoveServo(angleBuf, valBuf);
    for (int i = 70; i < 90; i++)     //захват детали
    {
      servoGrab.write (i);
      delay (150);
    }

    delay (3000);
    MoveServo(0, 0);
    delay (1000);
    servoGrab.write (70);

    delay (5000);

    data_ok = false;
    pos_buf = 0;

    sost = 0;
  }
}

void MoveServo(int angleNew, int valNew)
{
  if (angle < angleNew)
  {
    for ( ; angle < angleNew; angle++)
    {
      servoAngle.write(90 + angle);
      delay(30);
    }
  }

  else
  {
    for ( ; angle > angleNew; angle--)
    {
      servoAngle.write(90 + angle);
      delay (30);
    }
  }
  //////////////////////////////////////////////////////////////////////линейный////////////
  if (val < valNew)
  {
    for ( ; val < valNew; val++)
    {
      servo2.write(160 + val / 2.3);
      servo3.write(30 + val / 3);
      delay(50);
    }
  }

  else
  {
    for ( ; val > valNew; val--)
    {
      servo2.write(160 + val / 2.3);
      servo3.write(30 + val / 3);
      delay (50);
    }
  }
}
//
//class a
//{
//   private:
//   int ab =5;
//   int cd;
//
//};
//
//
//class b : public a
//{
//  public: int qw;
//};
