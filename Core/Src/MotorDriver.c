//
// Created by Mateusz Moskwin on 16/05/2025.
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MotorDriver.h"

void forward(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_SET);//right side clockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_RESET);//left side counterclockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_SET);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, speed);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, speed);
}

void backward(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_RESET);//right side counterclockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_SET);//left side clockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_RESET);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, speed);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, speed);
}
void turnLeft(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_SET);//right side clockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_SET);//left side clockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_RESET);
}
void turnRight(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_RESET);//right side counterclockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_RESET);//left side counterclockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_SET);
}
void stop()
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_RESET);//all motors fast stop
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_RESET);
}
//
