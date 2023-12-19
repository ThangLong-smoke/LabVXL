/*
 * timer.h
 *
 *  Created on: Dec 14, 2023
 *      Author: USER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void setTimer0(int duration);
void timer_run0();
void setTimer1(int duration);
void timer_run1();

unsigned char isTIM2_flag0();
unsigned char isTIM2_flag1();

#endif /* INC_TIMER_H_ */
