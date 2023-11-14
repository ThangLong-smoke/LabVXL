/*
 * input_reading.h
 *
 *  Created on: Nov 9, 2023
 *      Author: USER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"
#include "main.h"

#define MAX_BUTTONS		3
#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET

int isButtonNPressed(int index);

void getKeyInput();

#endif /* INC_INPUT_READING_H_ */
