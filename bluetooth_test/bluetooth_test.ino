#include <SoftwareSerial.h>
const int RX_PIN = 0;
const int TX_PIN = 1;
SoftwareSerial serial(RX_PIN, TX_PIN);
char commandChar;
void setup ()
{
  serial.begin (9600);
  //andomSeed(analogRead(0))
}
void loop ()
{
  if(serial.available())
  {
  commandChar = serial.read();
  serial.print(commandChar);
  }
}
