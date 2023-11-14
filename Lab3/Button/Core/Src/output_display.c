/*
 * output_display.c
 *
 *  Created on: Nov 9, 2023
 *      Author: USER
 */
#include "output_display.h"

/* display seg 1*/
void display7SEG_1(int num)
{
	if (num == 0)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,1);
	}
	if (num == 1)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,1);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,1);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,1);
	}
	if (num == 2)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,1);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 3)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 4)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,1);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,1);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 5)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,1);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 6)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,1);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 7)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,1);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,1);
	}
	if (num == 8)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 9)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
}

/* display seg 2*/
void display7SEG_2(int num)
{
	if (num == 0)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,0);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,0);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,1);
	}
	if (num == 1)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,1);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,1);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,1);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,1);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,1);
	}
	if (num == 2)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,1);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,0);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,1);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
	if (num == 3)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,1);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,1);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
	if (num == 4)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,1);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,1);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,1);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,0);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
	if (num == 5)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,1);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,1);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,0);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
	if (num == 6)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,1);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,0);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,0);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
	if (num == 7)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,1);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,1);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,1);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,1);
	}
	if (num == 8)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,0);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,0);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
	if (num == 9)
	{
		HAL_GPIO_WritePin(A2_GPIO_Port,A2_Pin,0);
		HAL_GPIO_WritePin(B2_GPIO_Port,B2_Pin,0);
		HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,0);
		HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,0);
		HAL_GPIO_WritePin(E2_GPIO_Port,E2_Pin,1);
		HAL_GPIO_WritePin(F2_GPIO_Port,F2_Pin,0);
		HAL_GPIO_WritePin(G2_GPIO_Port,G2_Pin,0);
	}
}
