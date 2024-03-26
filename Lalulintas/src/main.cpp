#include <Arduino.h>

int redLED = D6;
int yellowLED = D7;
int greenLED = D8;
// perteumuan 1
int myFunction(int, int);

void setup()
{

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop()
{
  digitalWrite(redLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(1000);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(5000);
  digitalWrite(greenLED, LOW);
}

int myFunction(int x, int y)
{
  return x + y;
}