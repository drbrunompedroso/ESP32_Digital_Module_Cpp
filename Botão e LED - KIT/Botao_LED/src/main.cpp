/*********************************************
 Etec Presidente Vargas
 Automação Industrial - 4ºAIN
 Programação para Sistemas de IoT
 Prof. Dr. Bruno Medina Pedroso
 Aplicação: Toogle Button - NPN
 ********************************************/

#include <Arduino.h>

const int PinLED = 13;
const int PinButton = 4;
int StateButton = 0;
int flag = 0;

void setup()
{
  pinMode(PinLED, OUTPUT);
  pinMode(PinButton, INPUT);
}

void loop() 
{
  StateButton = digitalRead(PinButton);
  
  if (StateButton == LOW)
   {
      delay(30);
      StateButton = digitalRead(PinButton);

      if (flag == 0) 
      {
        digitalWrite(PinLED, HIGH);
        flag = 1;
      } 
      else 
      {
        digitalWrite(PinLED, LOW);
        flag = 0;
      }

      while(digitalRead(PinButton) == LOW){}  // Aguarda botão ser solto "BREAK"
    }
}
