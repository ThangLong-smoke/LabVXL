#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

extern int EN_state;

void ClearLed();
void display7SEG(int currentState);
void blinkLED();
void changeEN();

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];
void update7SEG(int index);


#endif