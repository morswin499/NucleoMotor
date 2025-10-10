/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MotorDriver.h"
#include "motor.h"
#include "pid.h"
#include "l289n.h"
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
uint8_t RxBuffer[8];
volatile steering RxSteering;
uint16_t relRatio = 0;
volatile int32_t curr_pos;
volatile int32_t delta;
volatile motor_str motors[NUMBER_OF_MOTORS];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart == &huart3)
  {
    RxSteering.leftSpeed = (100*(RxBuffer[0]-48) + 10*(RxBuffer[1]-48)+RxBuffer[2]-48)*10;
    RxSteering.rightSpeed = (100*(RxBuffer[3]-48) + 10*(RxBuffer[4]-48)+RxBuffer[5]-48)*10;
    if(RxBuffer[6] - 48) // ujemna lewa
    {
    	RxSteering.leftSpeed *= -1;
    }
    if(RxBuffer[7] - 48) //ujemna prawa
    {
        RxSteering.rightSpeed *= -1;
    }
    motor_set_speed(&motors[0], RxSteering.leftSpeed);
    motor_set_speed(&motors[1], RxSteering.rightSpeed);


HAL_UART_Receive_IT(&huart3,RxBuffer,6);
__HAL_TIM_SET_COUNTER(&htim9, 0);



    //watchdog reset

  }
}
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

  if( huart == &huart3 ) HAL_UART_Receive_IT(&huart3,RxBuffer,6);
}
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
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_USART3_UART_Init();
  MX_TIM5_Init();
  MX_TIM9_Init();
  MX_TIM10_Init();
  MX_TIM6_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

//  HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin | M1_IN3_Pin | M1_IN4_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN2_Pin, GPIO_PIN_SET);
//  HAL_TIM_Base_Start(&htim1);
//  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
//  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
//  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
//  HAL_UART_Receive_IT(&huart3,RxBuffer,6);
//  HAL_TIM_Base_Start_IT(&htim6);
//  HAL_TIM_Base_Start_IT(&htim9);
//  HAL_TIM_Base_Start_IT(&htim10);
//  HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
//  HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
  l289n_init();
  motor_str_init(&motors[0], &htim2, A);
  motor_str_init(&motors[1], &htim3, B);
  pid_init(&motors[0].pid_controller, MOTOR_A_Kp, MOTOR_A_Ki, MOTOR_A_Kd, MOTOR_A_ANTI_WINDUP);
  pid_init(&motors[1].pid_controller, MOTOR_B_Kp, MOTOR_B_Ki, MOTOR_B_Kd, MOTOR_B_ANTI_WINDUP);
  HAL_TIM_Base_Start_IT(&htim6);
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
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
