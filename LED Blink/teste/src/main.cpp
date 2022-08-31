#include <Arduino.h>

const int LED_ESP32 = 2;

void setup()
 {
  pinMode(LED_ESP32, OUTPUT);
 }

void loop()
 {
  digitalWrite(LED_ESP32, HIGH);
  delay(1000);
  digitalWrite(LED_ESP32, LOW);
  delay(1000);
}
  



  