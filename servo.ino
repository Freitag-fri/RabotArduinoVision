int val = 0;
#include <Servo.h>
Servo servo;
Servo servo2;
Servo servo3;

char buf[4];
int pos_buf = 0;
bool data_ok = false;

void setup()
{
  // servo.attach(7, 700, 2500);   //основа
  servo2.attach(5, 900, 2200);   //линейный (80-170)

  servo3.attach(6, 1000, 2200);   //линейный (40 - 140)
  Serial.begin(9600);

  // servo.write(90);

  servo2.write(135);
  servo3.write(45);



  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

//  delay (2500);
//  for (int i = 0; i <= 90; i++)
//  {
//    servo2.write(135 + i/1.9 );
//    servo3.write(45 +i);
//    delay (100);
//  }
//  delay (2000);
//  servo2.write(135);
//  servo3.write(45);



    unsigned char c;
    if ( Serial.available() > 0)
    {
      c = Serial.read();
      if ( c == '\n') {
        buf[pos_buf] = 0;
        data_ok = true;
      }
      else buf[pos_buf++] = c;
    }
  
    if ( data_ok)
    {
      
      val = atoi(buf); //str.toInt();
      Serial.print( "buf: "); Serial.println(buf);
      Serial.print( "val: "); Serial.println(val);
      //servo.write(90 + val);
      servo2.write(135 + val/1.9 );
      servo3.write(45 +val);
      data_ok = false;
      pos_buf = 0;
    }
}
