/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
  void led_on(int pin) {
  	 HAL_GPIO_WritePin(GPIOA, pin, SET);
  }

  void led_off(int pin) {
  	 HAL_GPIO_WritePin(GPIOA, pin, RESET);
  }

  int counter = 16;
  int led_sum = 16;
  int led_green = 5;

  void led7seg_on(int pin) {
  	 HAL_GPIO_WritePin(GPIOB, pin, RESET);
  }

	void led7seg_off(int pin) {
  	 HAL_GPIO_WritePin(GPIOB, pin, SET);
  }

  void display_led1(int counter) {
		 if(counter == 0) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_on(GPIO_PIN_4);
			 led7seg_on(GPIO_PIN_5);
			 led7seg_off(GPIO_PIN_6);
		 }
		 else if(counter == 1) {
			 led7seg_off(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_off(GPIO_PIN_3);
			 led7seg_off(GPIO_PIN_4);
			 led7seg_off(GPIO_PIN_5);
			 led7seg_off(GPIO_PIN_6);
		 }
		 else if(counter == 2) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_off(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_on(GPIO_PIN_4);
			 led7seg_off(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
		 else if(counter == 3) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_off(GPIO_PIN_4);
			 led7seg_off(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
		 else if(counter == 4) {
			 led7seg_off(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_off(GPIO_PIN_3);
			 led7seg_off(GPIO_PIN_4);
			 led7seg_on(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
		 else if(counter == 5) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_off(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_off(GPIO_PIN_4);
			 led7seg_on(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
		 else if(counter == 6) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_off(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_on(GPIO_PIN_4);
			 led7seg_on(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
		 else if(counter == 7) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_off(GPIO_PIN_3);
			 led7seg_off(GPIO_PIN_4);
			 led7seg_off(GPIO_PIN_5);
			 led7seg_off(GPIO_PIN_6);
		 }
		 else if(counter == 8) {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_on(GPIO_PIN_4);
			 led7seg_on(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
		 else {
			 led7seg_on(GPIO_PIN_0);
			 led7seg_on(GPIO_PIN_1);
			 led7seg_on(GPIO_PIN_2);
			 led7seg_on(GPIO_PIN_3);
			 led7seg_off(GPIO_PIN_4);
			 led7seg_on(GPIO_PIN_5);
			 led7seg_on(GPIO_PIN_6);
		 }
  }
  void display_led2(int counter) {
  		 if(counter == 0) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_on(GPIO_PIN_11);
  			 led7seg_on(GPIO_PIN_12);
  			 led7seg_off(GPIO_PIN_13);
  		 }
  		 else if(counter == 1) {
  			 led7seg_off(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_off(GPIO_PIN_10);
  			 led7seg_off(GPIO_PIN_11);
  			 led7seg_off(GPIO_PIN_12);
  			 led7seg_off(GPIO_PIN_13);
  		 }
  		 else if(counter == 2) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_off(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_on(GPIO_PIN_11);
  			 led7seg_off(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
  		 else if(counter == 3) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_off(GPIO_PIN_11);
  			 led7seg_off(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
  		 else if(counter == 4) {
  			 led7seg_off(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_off(GPIO_PIN_10);
  			 led7seg_off(GPIO_PIN_11);
  			 led7seg_on(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
  		 else if(counter == 5) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_off(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_off(GPIO_PIN_11);
  			 led7seg_on(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
  		 else if(counter == 6) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_off(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_on(GPIO_PIN_11);
  			 led7seg_on(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
  		 else if(counter == 7) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_off(GPIO_PIN_10);
  			 led7seg_off(GPIO_PIN_11);
  			 led7seg_off(GPIO_PIN_12);
  			 led7seg_off(GPIO_PIN_13);
  		 }
  		 else if(counter == 8) {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_on(GPIO_PIN_11);
  			 led7seg_on(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
  		 else {
  			 led7seg_on(GPIO_PIN_7);
  			 led7seg_on(GPIO_PIN_8);
  			 led7seg_on(GPIO_PIN_9);
  			 led7seg_on(GPIO_PIN_10);
  			 led7seg_off(GPIO_PIN_11);
  			 led7seg_on(GPIO_PIN_12);
  			 led7seg_on(GPIO_PIN_13);
  		 }
    }
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if(counter == 0) counter = led_sum;
	  if(counter > (led_sum - led_green)) {
		  led_on(GPIO_PIN_4);
		  led_off(GPIO_PIN_5);
		  led_off(GPIO_PIN_6);

		  led_off(GPIO_PIN_7);
		  led_off(GPIO_PIN_8);
		  led_on(GPIO_PIN_9);

		  display_led1(led_green - (led_sum - counter));
		  display_led2(counter-(led_sum / 2));
		  counter--;
	  }
	  else if(counter > led_sum / 2) {
		  led_off(GPIO_PIN_4);
		  led_on(GPIO_PIN_5);
		  led_off(GPIO_PIN_6);

		  led_off(GPIO_PIN_7);
		  led_off(GPIO_PIN_8);
		  led_on(GPIO_PIN_9);

		  display_led1(counter-(led_sum / 2));
		  display_led2(counter-(led_sum / 2));
		  counter--;
	  }
	  else if(counter > (led_sum / 2 - led_green)) {
		  led_off(GPIO_PIN_4);
		  led_off(GPIO_PIN_5);
		  led_on(GPIO_PIN_6);

		  led_on(GPIO_PIN_7);
		  led_off(GPIO_PIN_8);
		  led_off(GPIO_PIN_9);

		  display_led1(counter);
		  display_led2(led_green - (led_sum / 2 - counter));

		  counter--;
	  }
	  else {
		  led_off(GPIO_PIN_4);
		  led_off(GPIO_PIN_5);
		  led_on(GPIO_PIN_6);

		  led_off(GPIO_PIN_7);
		  led_on(GPIO_PIN_8);
		  led_off(GPIO_PIN_9);

		  display_led1(counter);
		  display_led2(counter);

		  counter--;
	  }

	  HAL_Delay(1000);
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_1_RED_Pin|LED_1_YELLOW_Pin|LED_1_GREEN_Pin|LED_2_RED_Pin
                          |LED_2_YELLOW_Pin|LED_2_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_a_Pin|LED1_b_Pin|LED1_c_Pin|LED2_d_Pin
                          |LED2_e_Pin|LED2_f_Pin|LED2_g_Pin|LED1_d_Pin
                          |LED1_e_Pin|LED1_f_Pin|LED1_g_Pin|LED2_a_Pin
                          |LED2_b_Pin|LED2_c_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_1_RED_Pin LED_1_YELLOW_Pin LED_1_GREEN_Pin LED_2_RED_Pin
                           LED_2_YELLOW_Pin LED_2_GREEN_Pin */
  GPIO_InitStruct.Pin = LED_1_RED_Pin|LED_1_YELLOW_Pin|LED_1_GREEN_Pin|LED_2_RED_Pin
                          |LED_2_YELLOW_Pin|LED_2_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_a_Pin LED1_b_Pin LED1_c_Pin LED2_d_Pin
                           LED2_e_Pin LED2_f_Pin LED2_g_Pin LED1_d_Pin
                           LED1_e_Pin LED1_f_Pin LED1_g_Pin LED2_a_Pin
                           LED2_b_Pin LED2_c_Pin */
  GPIO_InitStruct.Pin = LED1_a_Pin|LED1_b_Pin|LED1_c_Pin|LED2_d_Pin
                          |LED2_e_Pin|LED2_f_Pin|LED2_g_Pin|LED1_d_Pin
                          |LED1_e_Pin|LED1_f_Pin|LED1_g_Pin|LED2_a_Pin
                          |LED2_b_Pin|LED2_c_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
