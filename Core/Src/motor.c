/*
 * motor.c
 *
 *  Created on: Oct 3, 2025
 *      Author: morswin
 */
#include "motor.h"


void motor_str_init(motor_str *m, TIM_HandleTypeDef *tim, motor_name Name)
{
	m->timer = tim;
	m->resolution = RESOLUTION;

	m->pulse_count = 0;
	m->set_speed = 0;
	m->measured_speed = 0;
	m->actual_PWM = 0;
	m->name = Name;
}

void motor_calculate_speed(motor_str *m)
{
	motor_update_count(m);
	m->measured_speed = (m->pulse_count * TIMER_FREQ * SECOND_IN_MINUTE)/m->resolution;


	int output = pid_calculate(&(m->pid_controller), m->set_speed, m->measured_speed);

	m->actual_PWM += output;

	if(m->actual_PWM >= 0)
	{
		l289n_set_motorB_direction(CW);
		l289n_set_motorB_speed(m->actual_PWM);
	}
	else
	{
		l289n_set_motorB_direction(CCW);
		l289n_set_motorB_speed(-m->actual_PWM);
	}
}

void motor_update_count(motor_str *m)
{
	m->pulse_count = (int16_t)__HAL_TIM_GET_COUNTER(m->timer);
	__HAL_TIM_SET_COUNTER(m->timer, 0);
}
void motor_set_speed(motor_str *m, int set_speed)
{
	if(set_speed != m->set_speed)
		pid_reset(&(m->pid_controller));

	m->set_speed = set_speed;
}
