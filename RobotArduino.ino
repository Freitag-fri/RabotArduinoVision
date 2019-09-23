int val = 0;
int val2 = 0;
#include <Servo.h>
//Servo servo;
//Servo servo2;
//Servo servo3;
Servo servo4;

char buf[4];
char buf2[4];
int pos_buf = 0;
bool data_ok = false;

int sost = 0;

int test = 0;


void setup()
{
  //servo.attach(7, 560, 3500);     //основа    (0-180)
  //servo2.attach(5, 900, 2200);    //линейный  (80-170)
  //servo3.attach(6, 1000, 2200);   //линейный  (40 - 140)
  servo4.attach(8, 1000, 1500);     //схват     (75 - 100)
  Serial.begin(9600);

  // servo.write(90);
  // servo2.write(135);
  // servo3.write(45);
  servo4.write (77);

}

unsigned char c;
bool go = false;
void loop()
{
  c = Serial.read();
  if (c == '1')
  {
    go = true;
  }
  else if (c == ' ')
  {
    go = false; 
  }
  
  if (go)
  {

    for (int i = 77; i < 100; i++)
    {
      servo4.write (i);
      delay (100);
    }
  }


  /*
    unsigned char c;
    if ( Serial.available() > 0 && sost == 0)
    {
      c = Serial.read();
      if ( c == 'q') {
        buf[pos_buf] = 0;
        sost = 1;
        pos_buf = 0;
      }
      else buf[pos_buf++] = c;
    }

    else if ( Serial.available() > 0 && sost == 1)
    {
      c = Serial.read();
      if ( c == '\n') {
        buf2[pos_buf] = 0;
        data_ok = true;
      }
      else buf2[pos_buf++] = c;
    }

    if ( data_ok)
    {
      val2 = atoi(buf2); //str.toInt();
      val = atoi(buf); //str.toInt();
      Serial.print( "buf: "); Serial.println(buf);
      Serial.print( "val: "); Serial.println(val);
      Serial.print( "val2: "); Serial.println(val2);

      servo.write(90 + val2);
      servo2.write(135 + val / 2.1);
      servo3.write(45 + val * 0.7);
      data_ok = false;
      pos_buf = 0;
      sost = 0;
    }
  */

}
