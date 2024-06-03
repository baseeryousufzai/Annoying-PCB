#include <Arduino.h>

long randAnnoy;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
  randomSeed(analogRead(3));
}

void loop() {
  randAnnoy = random(1800000,2400000);
  digitalWrite(1, 0); 
  digitalWrite(4, 0);
  delay(randAnnoy);

  digitalWrite(1, 1);
  digitalWrite(4, 1);
  delay(100);   
}