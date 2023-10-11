
#include "led.h"




const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};

void led_on(int pin) {
	  HAL_GPIO_WritePin(GPIOB, pin, RESET);
  }

void led_off(int pin) {
	  HAL_GPIO_WritePin(GPIOB, pin, SET);
  }


    void ClearLed() {
    HAL_GPIO_WritePin(GPIOA, SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN|SEG_G_PIN, GPIO_PIN_SET);
}
enum State {
	N0,N1,N2,N3,N4,N5,N6,N7,N8,N9,
};

enum State currentState=N0;
void display7SEG(int currentState){
if(currentState >= 0 && currentState < 10){

	switch (currentState) {
	      case N0:
	    	
	    	
	    	  led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN);
	    	
	    	  
	        break;
	      case N1:
	    	
	      	    	
	      	    	led_on(SEG_B_PIN|SEG_C_PIN);
	      	    	

	      	    	  
	      	        break;
	      case N2:
	    	
	      	    	  
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_G_PIN|SEG_D_PIN|SEG_E_PIN);
	      	    	
	      	    	  
	      	        break;
	      case N3:
	    	  
	      	    	
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_G_PIN);
	      	    

	      	    	  
	      	        break;
	      case N4:
	    	     	
	      	    	led_on(SEG_B_PIN|SEG_C_PIN|SEG_G_PIN|SEG_F_PIN);
	      	    

	      	    	  
	      	        break;
	      case N5:
	    	 
	      	    
	      	    	led_on(SEG_A_PIN|SEG_C_PIN|SEG_D_PIN|SEG_G_PIN|SEG_F_PIN);
	      	    
	      	    	  
	      	        break;
	      case N6:
	    	     	   
	      	    	led_on(SEG_A_PIN|SEG_G_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN);
	      	

	      	    	  
	      	        break;
	      case N7:
	 
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN);

	      	    	  
	      	        break;
	      case N8:
	   

	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN|SEG_G_PIN);


	      	    	  
	      	        break;
	      case N9:

	     	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_G_PIN|SEG_F_PIN);

	     	      	        break;
	    }
	    }
	    

}

void blinkLED()
{
  HAL_GPIO_TogglePin(GPIOB, DOT_Pin);
}

int EN_state = 0;

void changeEN()
{
  switch (EN_state) {
	case 0:
ClearLed();
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	  display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
	  EN_state = 1;
	  break;
	case 1:
	ClearLed();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	  display7SEG(led_buffer[1]);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
	  	  EN_state = 2;
	  break;
	  	case 2:
ClearLed();
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
	  display7SEG(led_buffer[2]);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
	  EN_state = 3;
	  break;
	  	case 3:
ClearLed();
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
	  display7SEG(led_buffer[3]);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
	  EN_state = 0;
	  break;
	default:
	  break;
}
}


void update7SEG ( int index ) {
 switch ( index ) {
 case 0:
 changeEN();
	  break;
break ;
 case 1:
 changeEN();
	  break;
 break ;
 case 2:
  changeEN();
	  break;
 break ;
case 3:
 changeEN();
	  break;
 break ;
 default :
break ;
}
 }

int hour = 7 , minute = 9 , second = 00;
void updateClockBuffer () {
led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}





const int MAX_LED_MATRIX = 8;
 int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {0b00111100,
		0b01000010,
		0b10000001,
		0b10000001,
		0b11111111,
		0b10000001,
		0b10000001,
		0b10000001 };




void displayLEDMtrix(uint8_t value)
{
	if (value & (1U << 0))
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_SET);

	if (value & (1U << 1))
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_SET);

	if (value & (1U << 2))
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_SET);

	if (value & (1U << 3))
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_SET);

	if (value & (1U << 4))
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_SET);

	if (value & (1U << 5))
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_SET);

	if (value & (1U << 6))
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_SET);

	if (value & (1U << 7))
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_SET);
}

void updateLEDMatrix(int index)
{
	switch (index)
	{
		case 0:
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 1:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 2:
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 3:
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 4:
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 5:
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 6:
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		case 7:
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
			displayLEDMtrix(matrix_buffer[index]);
			break;
		default:
			break;
	}
	
}
void updateMatrixBuffer()
{
	uint8_t temp = matrix_buffer[0];
	matrix_buffer[0] = matrix_buffer[1];
	matrix_buffer[1] = matrix_buffer[2];
	matrix_buffer[2] = matrix_buffer[3];
	matrix_buffer[3] = matrix_buffer[4];
	matrix_buffer[4] = matrix_buffer[5];
	matrix_buffer[5] = matrix_buffer[6];
	matrix_buffer[6] = matrix_buffer[7];
	matrix_buffer[7] = temp;
}
