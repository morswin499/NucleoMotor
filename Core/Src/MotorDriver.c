/*
//
// Created by Mateusz Moskwin on 16/05/2025.
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MotorDriver.h"
extern uint16_t relRatio;
extern volatile steering RxSteering;
uint16_t currPWM_L = 0;
uint16_t currPWM_R = 0;
uint16_t sPWM_L;
uint16_t sPWM_R;
void forward(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_SET);//right side clockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_RESET);//left side counterclockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_RESET);
	 setPWM(RxSteering.speed,RxSteering.speed);
}

void backward(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_RESET);//right side counterclockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_SET);//left side clockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_SET);
	setPWM(RxSteering.speed,RxSteering.speed);
}
void turnLeft(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_SET);//right side clockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_SET);//left side clockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_SET);
	setPWM(relRatio,RxSteering.speed);
}
void turnRight(uint8_t speed)
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_RESET);//right side counterclockwise
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_RESET);//left side counterclockwise
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_RESET);
	setPWM(RxSteering.speed,relRatio);

}
void stop()
{
	HAL_GPIO_WritePin(M1_IN1_GPIO_Port, M1_IN1_Pin, GPIO_PIN_SET);//all motors soft stop
	HAL_GPIO_WritePin(M1_IN2_GPIO_Port, M1_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN3_GPIO_Port, M1_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_IN4_GPIO_Port, M1_IN4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN1_GPIO_Port, M2_IN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN2_GPIO_Port, M2_IN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN3_GPIO_Port, M2_IN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_IN4_GPIO_Port, M2_IN4_Pin, GPIO_PIN_SET);
}
void setPWM(uint16_t L,uint16_t R)
{
	sPWM_L = L;
	sPWM_R = R;

}
//
*/
