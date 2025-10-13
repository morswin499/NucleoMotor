/*
 * l298n.c
 *
 *  Created on: Oct 3, 2025
 *      Author: morswin
 */
#include "l289n.h"
#include "gpio.h"
#include "tim.h"



void l289n_set_motorB_direction(l289n_Direction dir)
{
	switch(dir)
	{
	case CCW:
		HAL_GPIO_WritePin(MB_IN1_GPIO_Port, MB_IN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MB_IN2_GPIO_Port, MB_IN2_Pin, GPIO_PIN_RESET);
		break;
	case CW:
		HAL_GPIO_WritePin(MB_IN1_GPIO_Port, MB_IN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MB_IN2_GPIO_Port, MB_IN2_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}
void l289n_set_motorA_direction(l289n_Direction dir)
{
	switch(dir)
	{
	case CW:
		HAL_GPIO_WritePin(MA_IN1_GPIO_Port, MA_IN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MA_IN2_GPIO_Port, MA_IN2_Pin, GPIO_PIN_RESET);
		break;
	case CCW:
		HAL_GPIO_WritePin(MA_IN1_GPIO_Port, MA_IN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MA_IN2_GPIO_Port, MA_IN2_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}
void l289n_set_motorC_direction(l289n_Direction dir)
{
	switch(dir)
	{
	case CCW:
		HAL_GPIO_WritePin(MC_IN1_GPIO_Port, MC_IN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MC_IN2_GPIO_Port, MC_IN2_Pin, GPIO_PIN_RESET);
		break;
	case CW:
		HAL_GPIO_WritePin(MC_IN1_GPIO_Port, MC_IN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MC_IN2_GPIO_Port, MC_IN2_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}
void l289n_set_motorD_direction(l289n_Direction dir)
{
	switch(dir)
	{
	case CW:
		HAL_GPIO_WritePin(MD_IN1_GPIO_Port, MD_IN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(MD_IN2_GPIO_Port, MD_IN2_Pin, GPIO_PIN_RESET);
		break;
	case CCW:
		HAL_GPIO_WritePin(MD_IN1_GPIO_Port, MD_IN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MD_IN2_GPIO_Port, MD_IN2_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}

void l289n_set_motorB_speed(uint16_t speed)
{
	if (speed >= htim1.Instance->ARR)
		speed = htim1.Instance->ARR;
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, speed);
}
void l289n_set_motorA_speed(uint16_t speed)
{
	if (speed >= htim1.Instance->ARR)
		speed = htim1.Instance->ARR;
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, speed);
}
void l289n_set_motorC_speed(uint16_t speed)
{
	if (speed >= htim1.Instance->ARR)
		speed = htim1.Instance->ARR;
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, speed);
}
void l289n_set_motorD_speed(uint16_t speed)
{
	if (speed >= htim1.Instance->ARR)
		speed = htim1.Instance->ARR;
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, speed);
}
void l289n_init()
{
	l289n_set_motorA_direction(CW);
	l289n_set_motorB_direction(CW);
	l289n_set_motorC_direction(CW);
	l289n_set_motorD_direction(CW);
	l289n_set_motorA_speed(0);
	l289n_set_motorB_speed(0);
	l289n_set_motorC_speed(0);
	l289n_set_motorD_speed(0);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}
