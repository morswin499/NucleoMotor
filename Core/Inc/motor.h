/*
 * motor.h
 *
 *  Created on: Oct 3, 2025
 *      Author: morswin
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "tim.h"
#include"pid.h"
#include"l289n.h"
#include <stdint.h>

#define RESOLUTION	1200
#define TIMER_FREQ	10
#define SECOND_IN_MINUTE 60

#define MOTOR_A_Kp					0.7
#define MOTOR_A_Ki					0
#define MOTOR_A_Kd					2.7
#define MOTOR_A_ANTI_WINDUP			1000

#define MOTOR_B_Kp					0.7
#define MOTOR_B_Ki					0
#define MOTOR_B_Kd					2.7
#define MOTOR_B_ANTI_WINDUP			1000

//#define MOTOR_C_Kp					1
//#define MOTOR_C_Ki					0
//#define MOTOR_C_Kd					5
//#define MOTOR_C_ANTI_WINDUP			1000
//
//#define MOTOR_D_Kp					1
//#define MOTOR_D_Ki					0
//#define MOTOR_D_Kd					5
//#define MOTOR_D_ANTI_WINDUP			1000

#define NUMBER_OF_MOTORS			2

typedef enum
{
	A = 0,
	B = 1,
	C = 2,
	D = 3
}motor_name;

typedef struct
{
	TIM_HandleTypeDef *timer;

	uint16_t resolution;

	int pulse_count;
	int measured_speed;
	int set_speed;

	int actual_PWM;

	pid_str pid_controller;
	motor_name name;
}motor_str;

void motor_str_init(motor_str *m, TIM_HandleTypeDef *tim,motor_name Name);
void motor_calculate_speed(motor_str *m);
void motors_calculate_speed(motor_str* motors[], uint8_t number_of_motors);
void motor_update_count(motor_str *m);
void motor_set_speed(motor_str *m, int set_speed);
void motor_set_speed(motor_str *m, int set_speed);

#endif /* INC_MOTOR_H_ */
