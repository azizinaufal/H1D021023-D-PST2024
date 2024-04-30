#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int myFunction(int, int);

void setup()
{

  myservo.attach(D4);
}

void loop()
{
  // myservo.write(90);
  // myservo.write(180);
  // delay(1000);
  // myservo.write(0);
  // delay(1000);
  for (int pos = 0; pos <= 180; pos += 30)
  {
    myservo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 30)
  {
    myservo.write(pos);
    delay(15);
  }
}

int myFunction(int x, int y)
{
  return x + y;
}