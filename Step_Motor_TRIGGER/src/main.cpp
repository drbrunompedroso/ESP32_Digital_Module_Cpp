/* Stepmotor Control
   Programação para Sistemas de IoT
   Automação Industrial
   Prof. Dr. Bruno Medina Pedroso

   stateButton  directionButton | Stepmotor
        0             0         |    H-wave
        0             1         |    A-wave
        1             0         |    H-normal
        1             1         |    A-normal
*/
#include <Arduino.h>

#define B1 5
#define B2 18
#define B3 19
#define B4 21
#define S1 4
#define S2 2

int stateButton,
    directionButton,
    hold_time = 200;


void setup() 
{
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
}

void wave_mode_H()
{
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(B3, LOW);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(B3, LOW);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(B3, HIGH);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(B3, LOW);
  digitalWrite(B4, HIGH);
  delay(hold_time);
}

void wave_mode_A()
{
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(B3, LOW);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(B3, LOW);
  digitalWrite(B4, HIGH);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(B3, HIGH);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(B3, LOW);
  digitalWrite(B4, LOW);
  delay(hold_time);
}

void normal_mode_H()
{
  digitalWrite(B1, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(B3, LOW);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(B3, HIGH);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(B3, HIGH);
  digitalWrite(B4, HIGH);
  delay(hold_time);

  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(B3, LOW);
  digitalWrite(B4, HIGH);
  delay(hold_time);
}

void normal_mode_A()
{
  digitalWrite(B1, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(B3, LOW);
  digitalWrite(B4, LOW);
  delay(hold_time);

  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(B3, LOW);
  digitalWrite(B4, HIGH);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(B3, HIGH);
  digitalWrite(B4, HIGH);
  delay(hold_time);

  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(B3, HIGH);
  digitalWrite(B4, LOW);
  delay(hold_time);
}

void loop()
{
  stateButton = digitalRead(S1);
  directionButton = digitalRead(S2);

  if(stateButton == 1)
  {
    if(directionButton == 1)
    {
      normal_mode_A();
    }
    else
    {
      normal_mode_H();
    }
  }
  else if(stateButton == 0)
  {
    if (directionButton == 1)
    {
      wave_mode_A();
    }
    else
    {
      wave_mode_H();
    }
  }  
}