/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_1_RED_Pin GPIO_PIN_4
#define LED_1_RED_GPIO_Port GPIOA
#define LED_1_YELLOW_Pin GPIO_PIN_5
#define LED_1_YELLOW_GPIO_Port GPIOA
#define LED_1_GREEN_Pin GPIO_PIN_6
#define LED_1_GREEN_GPIO_Port GPIOA
#define LED_2_RED_Pin GPIO_PIN_7
#define LED_2_RED_GPIO_Port GPIOA
#define LED1_a_Pin GPIO_PIN_0
#define LED1_a_GPIO_Port GPIOB
#define LED1_b_Pin GPIO_PIN_1
#define LED1_b_GPIO_Port GPIOB
#define LED1_c_Pin GPIO_PIN_2
#define LED1_c_GPIO_Port GPIOB
#define LED2_d_Pin GPIO_PIN_10
#define LED2_d_GPIO_Port GPIOB
#define LED2_e_Pin GPIO_PIN_11
#define LED2_e_GPIO_Port GPIOB
#define LED2_f_Pin GPIO_PIN_12
#define LED2_f_GPIO_Port GPIOB
#define LED2_g_Pin GPIO_PIN_13
#define LED2_g_GPIO_Port GPIOB
#define LED_2_YELLOW_Pin GPIO_PIN_8
#define LED_2_YELLOW_GPIO_Port GPIOA
#define LED_2_GREEN_Pin GPIO_PIN_9
#define LED_2_GREEN_GPIO_Port GPIOA
#define LED1_d_Pin GPIO_PIN_3
#define LED1_d_GPIO_Port GPIOB
#define LED1_e_Pin GPIO_PIN_4
#define LED1_e_GPIO_Port GPIOB
#define LED1_f_Pin GPIO_PIN_5
#define LED1_f_GPIO_Port GPIOB
#define LED1_g_Pin GPIO_PIN_6
#define LED1_g_GPIO_Port GPIOB
#define LED2_a_Pin GPIO_PIN_7
#define LED2_a_GPIO_Port GPIOB
#define LED2_b_Pin GPIO_PIN_8
#define LED2_b_GPIO_Port GPIOB
#define LED2_c_Pin GPIO_PIN_9
#define LED2_c_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
