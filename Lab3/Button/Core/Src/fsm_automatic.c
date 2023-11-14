/*
 * fsm_automatic.c
 *
 *  Created on: 30 thg 10, 2023
 *      Author: USER
 */

#include "fsm_automatic.h"

int count1 = 5;		// count to display SEG 1
int count2 = 3;		// ----				SEG 2

int timered = 5000;		// time led RED
int timegreen = 3000;	// time led GREEN
int timeyellow = 2000;	// time led YELLOW

int index_led = 0;	// control EN0 EN1

int count [4] = {0 , 5 , 0 , 3};	// array count1 count2

int mode = 1;		// conut mode
int increaseRed = 0;
int increaseYellow = 0;
int increaseGreen = 0;

int chuc = 0;	// value 1
int dvi = 0;	// value 2

//// sub count road 1 ////
void subcount1()
{
	if(timer3_flag == 1)
	{
		setTimer3(1000);
		count1--;

		count [0] = count1 / 10;	//
		count [1] = count1 % 10;
	}
}

//// sub count road 2 ////
void subcount2()
{
	if(timer4_flag == 1)
	{
		setTimer4(1000);
		count2--;

		count [2] = count2 / 10;
		count [3] = count2 % 10;
	}
}

//// timer 5 for index_led
void update()
{
	  if (timer5_flag == 1)
	  {
		  setTimer5(500);
		  index_led++;
	  }

	  if(index_led == 2)
		  index_led = 0;
}

//// BUTTON ////////////
void controlButton()
{
	if (isButtonNPressed(0) == 1)
		mode++;

	if(mode == 5)
	{
		mode = 1;
		status_1 = INIT_1;
		status_2 = INIT_2;

		increaseRed = 0;
		increaseYellow = 0;
		increaseGreen = 0;
	}

	////// display MODE /////////
	if(index_led == 0)
	{
		display7SEG_1(0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);	// seg 1 off
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);	// seg 2 on
	}
	else
	{
		display7SEG_1(mode);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);	// seg 1 on
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);	// seg 2 off
	}

	switch(mode)
	{
	case 1:
		break;
	case 2:			// increase time duration RED
		////// // led RED BLINK //////////
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);		// yellow 1 off
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 1);		// yellow 2 off
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);		// green 1 off
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 1);		// green 2 off

		if(timer6_flag == 1)
		{
			setTimer6(500);
			HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
			HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
		}

		//// PRESS BUTTON 2 ///////
		if(isButtonNPressed(1) == 1)
		{
			increaseRed++;

			if((timered/1000 + increaseRed) > 99)
			{
				timered = 1000;
				increaseRed = 0;
			}
		}

		////// DISPLAY VALUE  /////////
		chuc = (timered/1000 + increaseRed)/10;
		dvi = (timered/1000 + increaseRed)%10;

		if(index_led == 0)
		{
			display7SEG_2(chuc);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);	// seg 1 off
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);	// seg 2 on
		}
		else
		{
			display7SEG_2(dvi);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);	// seg 1 on
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);	// seg 2 off
		}

		////// PRESS BUTTON 3 /////////
		if(isButtonNPressed(2) == 1)
		{
			timered += increaseRed*1000;
			increaseRed = 0;
		}
		break;
	case 3:			// increase time duration YELLOW
		////// // led RED BLINK //////////
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);		// RED 1 off
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);		// RED 2 off
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);		// green 1 off
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 1);		// green 2 off

		if(timer6_flag == 1)
		{
			setTimer6(500);
			HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
			HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
		}

		//// PRESS BUTTON 2 ///////
		if(isButtonNPressed(1) == 1)
		{
			increaseYellow++;

			if((timeyellow/1000 + increaseYellow) > 99)
			{
				timeyellow = 1000;
				increaseYellow = 0;
			}
		}

		////// DISPLAY VALUE  /////////
		chuc = (timeyellow/1000 + increaseYellow)/10;
		dvi = (timeyellow/1000 + increaseYellow)%10;

		if(index_led == 0)
		{
			display7SEG_2(chuc);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);	// seg 1 off
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);	// seg 2 on
		}
		else
		{
			display7SEG_2(dvi);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);	// seg 1 on
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);	// seg 2 off
		}

		////// PRESS BUTTON 3 /////////
		if(isButtonNPressed(2) == 1)
		{
			timeyellow += increaseYellow*1000;
			increaseYellow = 0;
		}
		break;
	case 4:			// increase time duration GREEN
		////// // led RED BLINK //////////
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);		// yellow 1 off
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 1);		// yellow 2 off
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);		// red 1 off
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);		// red 2 off

		if(timer6_flag == 1)
		{
			setTimer6(500);
			HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
			HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
		}

		//// PRESS BUTTON 2 ///////
		if(isButtonNPressed(1) == 1)
		{
			increaseGreen++;

			if((timegreen/1000 + increaseGreen) > 99)
			{
				timegreen = 1000;
				increaseGreen = 0;
			}
		}

		////// DISPLAY VALUE  /////////
		chuc = (timegreen/1000 + increaseGreen)/10;
		dvi = (timegreen/1000 + increaseGreen)%10;

		if(index_led == 0)
		{
			display7SEG_2(chuc);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);	// seg 1 off
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);	// seg 2 on
		}
		else
		{
			display7SEG_2(dvi);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);	// seg 1 on
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);	// seg 2 off
		}

		////// PRESS BUTTON 3 /////////
		if(isButtonNPressed(2) == 1)
		{
			timegreen += increaseGreen*1000;
			increaseGreen = 0;
		}
		break;
	default:
		break;
	}
}

void fsm_automatic_1_run()
{
	if(isButtonNPressed(0) == 1)
		mode++;

	if(mode == 1)	///// STATE NORMAL
	{
		switch(status_1)
		{
		case INIT_1:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);

			status_1 = AUTO_RED_1;
			setTimer1(timered);

			setTimer3(1000);
			count1 = timered / 1000;
			break;
		case AUTO_RED_1:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 0);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);

			if(timer1_flag == 1)
			{
				setTimer1(timegreen);
				count1 = timegreen/1000 + 1;
				status_1 = AUTO_GREEN_1;
			}
			break;
		case AUTO_GREEN_1:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 0);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 1);

			if(timer1_flag == 1)
			{
				setTimer1(timeyellow);
				count1 = timeyellow/1000 + 1;
				status_1 = AUTO_YELLOW_1;
			}
			break;
		case AUTO_YELLOW_1:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, 1);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, 0);

			if(timer1_flag == 1)
			{
				setTimer1(timered);
				count1 = timered/1000 + 1;
				status_1 = AUTO_RED_1;
			}
			break;
		default:
			break;
		}

		subcount1();
		update();

		if(index_led == 0)
		{
			display7SEG_1(count[1]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);	// seg 1 off
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);	// seg 2 on
		}
		else
		{
			display7SEG_1(count[0]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);	// seg 1 on
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);	// seg 2 off
		}
	}
	else
	{
		update();
		controlButton();
	}
}

void fsm_automatic_2_run()
{
	if(mode == 1)
	{
		switch(status_2)
		{
		case INIT_2:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 1);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 1);

			status_2 = AUTO_GREEN_2;
			setTimer2(timegreen);

			setTimer4(1000);
			count2 = timegreen/1000;

			isButtonNPressed(0);
			break;
		case AUTO_RED_2:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 0);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 1);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 1);

			if(timer2_flag == 1)
			{
				setTimer2(timegreen);
				count2 = timegreen/1000 + 1;
				status_2 = AUTO_GREEN_2;
			}
			break;
		case AUTO_GREEN_2:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 0);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 1);

			if(timer2_flag == 1)
			{
				setTimer2(timeyellow);
				count2 = timeyellow/1000 + 1;
				status_2 = AUTO_YELLOW_2;
			}
			break;
		case AUTO_YELLOW_2:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, 1);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, 0);

			if(timer2_flag == 1)
			{
				setTimer2(timered);
				count2 = timered/1000 + 1;
				status_2 = AUTO_RED_2;
			}
			break;
		default:
			break;
		}

		subcount2();
		update();

		if(index_led == 0)
		{
			display7SEG_2(count[3]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);	// seg 1 off
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);	// seg 2 on
		}
		else
		{
			display7SEG_2(count[2]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);	// seg 1 on
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);	// seg 2 off
		}
	}
}
