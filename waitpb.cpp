#include "waitpb.h"
// constructor with four parameters :D
waitpb::waitpb(uint8_t pushbuotton_on, uint8_t pushbutton_off, uint8_t output_pin, uint16_t time_in_ms)
{
  PUSHBUTTON_ON = pushbuotton_on;
  PUSHBUTTON_OFF = pushbutton_off;
  OUTPUT_PIN = output_pin;
  TIME_IN_MS = time_in_ms;
}
// constructor with three parameters *_*
waitpb::waitpb(uint8_t pushbuotton_on, uint8_t pushbutton_off, uint8_t output_pin)
{
  PUSHBUTTON_ON = pushbuotton_on;
  PUSHBUTTON_OFF = pushbutton_off;
  OUTPUT_PIN = output_pin;
}
//begin method for make inputs and outputs pins ^_^
void waitpb::begin()
{
  pinMode(PUSHBUTTON_ON, INPUT_PULLUP);
  pinMode(PUSHBUTTON_OFF, INPUT_PULLUP);
  pinMode(OUTPUT_PIN, OUTPUT);
}
////////////////////////////////////////////////////////////
void waitpb::waits()
{
  if(!digitalRead(PUSHBUTTON_ON))
  {
    digitalWrite(OUTPUT_PIN, HIGH);
    counter = true;
  }
  for(int i = 1;i<=(TIME_IN_MS) && counter == true;i++)
  {
    if(!digitalRead(PUSHBUTTON_OFF))
    {
      digitalWrite(OUTPUT_PIN, LOW);
      counter = false;
      break;
    }
    delay(1);
    if(i == TIME_IN_MS)digitalWrite(OUTPUT_PIN, LOW);
  }
}
void waitpb::waitms()
{
  if(!digitalRead(PUSHBUTTON_ON))
  {
    digitalWrite(OUTPUT_PIN, HIGH);
    counter = true;
  }
  for(int i = 1;i<=(TIME_IN_MS) && counter == true;i++)
  {
    if(!digitalRead(PUSHBUTTON_OFF))
    {
      digitalWrite(OUTPUT_PIN, LOW);
      counter = false;
      break;
    }
    delay(1);
    if(i == TIME_IN_MS)digitalWrite(OUTPUT_PIN, LOW);
  }
}
////////////////////////////////////////////////////////////
void waitpb::waits(uint16_t time_s)
{
  TIME_IN_MS = time_s*1000;
  if(!digitalRead(PUSHBUTTON_ON))
  {
    digitalWrite(OUTPUT_PIN, HIGH);
    counter = true;
  }
  for(int i = 1;i<=(TIME_IN_MS) && counter == true;i++)
  {
    if(!digitalRead(PUSHBUTTON_OFF))
    {
      digitalWrite(OUTPUT_PIN, LOW);
      counter = false;
      break;
    }
    delay(1);
    if(i == TIME_IN_MS)digitalWrite(OUTPUT_PIN, LOW);
  }
}
void waitpb::waitms(uint16_t time_ms)
{
  TIME_IN_MS = time_ms;
  if(!digitalRead(PUSHBUTTON_ON))
  {
    digitalWrite(OUTPUT_PIN, HIGH);
    counter = true;
  }
  for(int i = 1;i<=(TIME_IN_MS) && counter == true;i++)
  {
    if(!digitalRead(PUSHBUTTON_OFF))
    {
      digitalWrite(OUTPUT_PIN, LOW);
      counter = false;
      break;
    }
    delay(1);
    if(i == TIME_IN_MS)digitalWrite(OUTPUT_PIN, LOW);
  }
}