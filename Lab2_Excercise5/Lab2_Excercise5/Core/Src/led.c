
#include "led.h"

#define SEG_A_PIN GPIO_PIN_9
#define SEG_B_PIN GPIO_PIN_8
#define SEG_C_PIN GPIO_PIN_7
#define SEG_D_PIN GPIO_PIN_6
#define SEG_E_PIN GPIO_PIN_5
#define SEG_F_PIN GPIO_PIN_4
#define SEG_G_PIN GPIO_PIN_3


const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};

void led_on(int pin) {
	  HAL_GPIO_WritePin(GPIOA, pin, RESET);
  }

void led_off(int pin) {
	  HAL_GPIO_WritePin(GPIOA, pin, SET);
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

int hour = 15 , minute = 8 , second = 50;
void updateClockBuffer () {
led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;


}