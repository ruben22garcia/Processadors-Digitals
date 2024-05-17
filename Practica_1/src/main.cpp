#include <Arduino.h>

#define LED_FLASH 23

void setup() 
{
  pinMode(LED_FLASH,OUTPUT);
  Serial.begin(115200);
  delay(500);
  Serial.println("HOLA MUNDO");
}

void loop() 
{
  Serial.println("ledhigh");
  digitalWrite(LED_FLASH,HIGH);
  delay(500);
  Serial.println("ledlow");
  digitalWrite(LED_FLASH,LOW);
  delay(500);
}