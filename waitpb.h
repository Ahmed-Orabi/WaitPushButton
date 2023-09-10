#ifndef WAITPB_H
#define WAITPB_H
#include <Arduino.h>
class waitpb{
public:
waitpb(uint8_t pushbuotton_on, uint8_t pushbutton_off, uint8_t output_pin,uint16_t time_in_ms);
waitpb(uint8_t pushbuotton_on, uint8_t pushbutton_off, uint8_t output_pin);

void begin();
void waits();
void waitms();
void waits(uint16_t time_s);
void waitms(uint16_t time_ms);

private:
uint8_t PUSHBUTTON_ON;
uint8_t PUSHBUTTON_OFF;
uint8_t OUTPUT_PIN;
uint16_t TIME_IN_MS;
bool counter = false;
};
#endif