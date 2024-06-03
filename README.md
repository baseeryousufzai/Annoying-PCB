# Annoying-PCB
Have you ever wanted to prank your friends or family in a fun and light-hearted way? Well, just plant one of these in the room and check on them in a few hours! The programmer pins allow you to program the ATTiny85 with code that lets the buzzer beep every 30-40 minutes or whichever duration you wish. I bought a few extra of this from a project course and wanted to make a board to accomadate the buzzer's large size while being as small as possible. 

This project uses an ATTiny85, a low-cost 8-bit microcontroller by Microchip and has a programming header to load code into it via ISP'ing. I used KiCad 8.0 to design this PCB and please fee free to download the attached Gerber files above. Furthermore, I've attached a quick sample code I made and will break it down below.

#include <Arduino.h>
long randAnnoy; // Note using int has a hard limit and will limit how long the duration will be. Using long lets us extend it.

void setup() {
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
  randomSeed(analogRead(3)); // If you try to generate a random number, you'll notice it is the exact same sequence! This is because when the microcontroller is turned on, it always begins at the same seed. To vary the seed and every bootup, I had the startup seed be based on the analog value on pin 3. As it isn't connected to anything, it'll spout out a 10-bit value that introduces the illusion of randomness.
}

void loop() {
  randAnnoy = random(1800000,2400000); // The duration is between every 30-40 minutes but can be set arbritarily.
  digitalWrite(1, 0); 
  digitalWrite(4, 0);
  delay(randAnnoy);

  digitalWrite(1, 1);
  digitalWrite(4, 1);
  delay(100);   
}

Note, please be responsible as this is meant to be used as a joke amongst people you know. 

![image](https://github.com/baseeryousufzai/Annoying-PCB/assets/45570998/94e9f95e-0cf6-46ed-b522-d42f7667a182)
 
![image](https://github.com/baseeryousufzai/Annoying-PCB/assets/45570998/ad4f5d04-33e4-4ece-ae66-f7480a450a9b)

