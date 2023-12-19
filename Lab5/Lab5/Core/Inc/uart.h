/*
 * uart.h
 *
 *  Created on: Dec 14, 2023
 *      Author: USER
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void uart_fsm(void);
void fsm_command(void);

#endif /* INC_UART_H_ */
