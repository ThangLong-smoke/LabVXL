/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */
void led_on(int pin) {
	  HAL_GPIO_WritePin(GPIOA, pin, RESET);
  }

void led_off(int pin) {
	  HAL_GPIO_WritePin(GPIOA, pin, SET);
  }

//---------------------------------------------------------------------------------------
//CODE EX1
/*int counter=200;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{

	        static int state = 0;

	        if (state == 0)
	        {
	        	counter--;
	            led_on(GPIO_PIN_3);
	            led_off(GPIO_PIN_4);
	        	if(counter<=0){
	            state = 1;
	            counter=200;
	        	}
	        }
	        else
	        {
	            led_off(GPIO_PIN_3);
	            led_on(GPIO_PIN_4);
	        	if(counter<=0){
	            state = 0;
	            counter=200;
	        }
	        }

}*/

//----------------------------------------------------------------------------------------------

//CODE EX2
//USE SWITCH CASE
/*enum TrafficLightState {
  RED,
  YELLOW,
  GREEN,
};
const int time_red=500;
const int time_yellow=300;
const int time_green=200;
enum TrafficLightState currentState=RED;
int all_time=1000;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	switch (currentState) {
	      case RED:
	    	  all_time--;
	    	  led_on(GPIO_PIN_3);
	    	  led_off(GPIO_PIN_4);
	    	  led_off(GPIO_PIN_5);
	    	  if(all_time<=time_red){
	  	        currentState = YELLOW;
	  	        all_time=200;
	    	  }
	        break;
	      case YELLOW:
	    	  all_time--;
	    	  	    	  led_off(GPIO_PIN_3);
	    	  	    	  led_on(GPIO_PIN_4);
	    	  	    	  led_off(GPIO_PIN_5);
	    	  	    	  if(all_time<=0){
	    	  	  	        currentState = GREEN;
	    	  	  	    all_time=300;
	    	  	    	  }
	        break;
	      case GREEN:
	    	  all_time--;
	    	  	    	  led_off(GPIO_PIN_3);
	    	  	    	  led_off(GPIO_PIN_4);
	    	  	    	  led_on(GPIO_PIN_5);
	    	  	    	  if(all_time<=time_green){
	    	  	  	        currentState = RED;
	    	  	  	        all_time=1000;
	    	  	    	  }
	        break;

	    }

}
*/




//USE IF
/*int counter=500;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	static int state = 0;

		        if (state == 0)
		        {
		        	counter--;
		            led_on(GPIO_PIN_3);
		            led_off(GPIO_PIN_4);
		            led_off(GPIO_PIN_5);
		        	if(counter<=0){
		            state = 1;
		            counter=200;
		        	}
		        }
		        if (state == 1)
		        		        {
		        		        	counter--;
		        		            led_off(GPIO_PIN_3);
		        		            led_on(GPIO_PIN_4);
		        		            led_off(GPIO_PIN_5);
		        		        	if(counter<=0){
		        		            state = 2;
		        		            counter=300;
		        		        	}
		        		        }
		        if (state == 2)
		        {
		            led_off(GPIO_PIN_3);
		            led_off(GPIO_PIN_4);
		            led_on(GPIO_PIN_5);
		        	if(counter<=0){
		            state = 0;
		            counter=500;
		        }
		        }
}*/
//----------------------------------------------------------------------------------------------


//EX3
/*enum TrafficLightState {
	RED1_GREEN2,
		RED1_YELLOW2,
		GREEN1_RED2,
		YELLOW1_RED2,
};
//Time
const int time_r1g2=800;
const int time_r1y2=500;
const int time_r2g1=300;
const int time_r2y1=0;
enum TrafficLightState currentState=RED1_GREEN2;
int all_time=1000;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	switch (currentState) {
	      case RED1_GREEN2:
	    	  all_time--;
	    	  led_on(GPIO_PIN_3);
	    	  led_off(GPIO_PIN_4);
	    	  led_off(GPIO_PIN_5);
	    	  led_off(GPIO_PIN_6);
	    	  led_off(GPIO_PIN_7);
	    	  led_on(GPIO_PIN_8);
	    	  if(all_time<=time_r1g2){
	  	        currentState = RED1_YELLOW2;
	    	  }
	        break;
	      case RED1_YELLOW2:
	    	  all_time--;
	    	  led_on(GPIO_PIN_3);
	    	  led_off(GPIO_PIN_4);
	    	  led_off(GPIO_PIN_5);
	    	  led_off(GPIO_PIN_6);
	    	  led_on(GPIO_PIN_7);
	    	  led_off(GPIO_PIN_8);
	    	  	    	  if(all_time<=time_r1y2){
	    	  	  	        currentState = GREEN1_RED2;
	    	  	    	  }
	        break;
	      case GREEN1_RED2:
	    	  all_time--;
	    	  led_off(GPIO_PIN_3);
	    	  led_off(GPIO_PIN_4);
	    	  led_on(GPIO_PIN_5);
	    	  led_on(GPIO_PIN_6);
	    	  led_off(GPIO_PIN_7);
	    	  led_off(GPIO_PIN_8);
	    	  	    	  if(all_time<=time_r2g1){
	    	  	  	        currentState = YELLOW1_RED2;
	    	  	    	  }
	        break;
	      case YELLOW1_RED2:
	      	    	  all_time--;
	      	    	  led_off(GPIO_PIN_3);
	      	    	  led_on(GPIO_PIN_4);
	      	    	  led_off(GPIO_PIN_5);
	      	    	  led_on(GPIO_PIN_6);
	      	    	  led_off(GPIO_PIN_7);
	      	    	  led_off(GPIO_PIN_8);
	      	    	  	    	  if(all_time<=time_r2y1){
	      	    	  	  	        currentState = RED1_GREEN2;
	      	    	  	  	        all_time=1000;
	      	    	  	    	  }
	      	        break;

	    }
}
*/

//---------------------------------------------------------------------------------------------

//EX4


/*#define SEG_A_PIN GPIO_PIN_9
#define SEG_B_PIN GPIO_PIN_8
#define SEG_C_PIN GPIO_PIN_7
#define SEG_D_PIN GPIO_PIN_6
#define SEG_E_PIN GPIO_PIN_5
#define SEG_F_PIN GPIO_PIN_4
#define SEG_G_PIN GPIO_PIN_3
    void ClearLed() {
    HAL_GPIO_WritePin(GPIOA, SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN|SEG_G_PIN, GPIO_PIN_SET);
}
enum State {
	N0,N1,N2,N3,N4,N5,N6,N7,N8,N9,
};

enum State currentState=N0;
int all_time=1000;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	switch (currentState) {
	      case N0:
	    	  ClearLed();
	    	  all_time--;
	    	  led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN);
	    	  if(all_time<=0){
	  	        currentState = N1;
	  	        all_time=1000;

	    	  }
	        break;
	      case N1:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_B_PIN|SEG_C_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N2;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N2:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_G_PIN|SEG_D_PIN|SEG_E_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N3;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N3:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_G_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N4;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N4:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_B_PIN|SEG_C_PIN|SEG_G_PIN|SEG_F_PIN);
	      	    	if(all_time<=0){
	      	  	        currentState = N5;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N5:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_A_PIN|SEG_C_PIN|SEG_D_PIN|SEG_G_PIN|SEG_F_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N6;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N6:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_A_PIN|SEG_G_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N7;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N7:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N8;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N8:
	    	  ClearLed();
	      	    	  all_time--;
	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_E_PIN|SEG_F_PIN|SEG_G_PIN);
	      	    	  if(all_time<=0){
	      	  	        currentState = N9;
	      	  	        all_time=1000;

	      	    	  }
	      	        break;
	      case N9:
	    	  ClearLed();
	     	      	    	  all_time--;
	     	      	    	led_on(SEG_A_PIN|SEG_B_PIN|SEG_C_PIN|SEG_D_PIN|SEG_G_PIN|SEG_F_PIN);
	     	      	    	  if(all_time<=0){
	     	      	  	        currentState = N0;
	     	      	  	        all_time=1000;

	     	      	    	  }
	     	      	        break;
	    }

}*/

//-------------------------------------------------------------------------------------------



/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_TIM_Base_Start_IT(&htim2);
    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
      /* USER CODE END WHILE */

      /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 PA4 PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
