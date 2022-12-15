/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "input_processing.h"
#include "input_reading.h"
#include "scheduler.h"
#include "display_led.h"
#include "FMS.h"
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
#define Mode_Button_Pin GPIO_PIN_1
#define Mode_Button_GPIO_Port GPIOA
#define Add_Button_Pin GPIO_PIN_4
#define Add_Button_GPIO_Port GPIOA
#define Perdes_Button_Pin GPIO_PIN_0
#define Perdes_Button_GPIO_Port GPIOB
#define Confirm_Button_Pin GPIO_PIN_0
#define Confirm_Button_GPIO_Port GPIOB
#define Led_31_Pin GPIO_PIN_10
#define Led_31_GPIO_Port GPIOB
#define Led_32_Pin GPIO_PIN_8
#define Led_32_GPIO_Port GPIOA
#define Led_11_Pin GPIO_PIN_10
#define Led_11_GPIO_Port GPIOA
#define Led_12_Pin GPIO_PIN_3
#define Led_12_GPIO_Port GPIOB
#define Led_22_Pin GPIO_PIN_4
#define Led_22_GPIO_Port GPIOB
#define Led_21_Pin GPIO_PIN_5
#define Led_21_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
extern int Led_buffer_1_timer[3];
extern int Led_buffer_2_timer[3];
extern int Led_timer[3];
extern int MODE;
extern int Led_buffer_timer[3];


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
