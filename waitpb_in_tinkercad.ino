/*
This code make for simulate in Tinkercad by using (waitpb) Class
and Two constructors and Five methods ;) 
 */
class waitpb{
  uint8_t PUSHBUTTON_ON;
  uint8_t PUSHBUTTON_OFF;
  uint8_t OUTPUT_PIN;
  uint16_t TIME_IN_MS;
  bool counter = false;

public:
// constructor with four parameters :D
waitpb(uint8_t pushbuotton_on, uint8_t pushbutton_off, uint8_t output_pin, uint16_t time_in_ms)
{
  PUSHBUTTON_ON = pushbuotton_on;
  PUSHBUTTON_OFF = pushbutton_off;
  OUTPUT_PIN = output_pin;
  TIME_IN_MS = time_in_ms;
}
// constructor with three parameters *_*
waitpb(uint8_t pushbuotton_on, uint8_t pushbutton_off, uint8_t output_pin)
{
  PUSHBUTTON_ON = pushbuotton_on;
  PUSHBUTTON_OFF = pushbutton_off;
  OUTPUT_PIN = output_pin;
}
//end of define two constructors </>
/*****************************************************/
//begin method for define inputs and outputs pins ^_^
void begin()
{
  pinMode(PUSHBUTTON_ON, INPUT_PULLUP);
  pinMode(PUSHBUTTON_OFF, INPUT_PULLUP);
  pinMode(OUTPUT_PIN, OUTPUT);
}
///////////////////////////////////////////////////////
void waits()
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
void waitms()
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
///////////////////////////////////////////////////////
void waits(uint16_t time_s)
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
void waitms(uint16_t time_ms)
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
}; // end of waitpb class :D

/****************Simulate the Code****************/

//#include "waitpb.h"
waitpb w(5,6,7,2000);
//waitpb w1(5,6,7);
void setup() {
  // put your setup code here, to run once:
w.begin();
//w1.begin():
}
void loop() {
  // put your main code here, to run repeatedly:
w.waitms();
//w1.waits(4);
}
