/*
 * l289n.h
 *
 *  Created on: Oct 3, 2025
 *      Author: morswin
 */

#ifndef INC_L289N_H_
#define INC_L289N_H_

#include <stdint.h>

typedef enum
{
	CW = 0,
	CCW = 1
}l289n_Direction;

void l289n_set_motorA_direction(l289n_Direction dir);
void l289n_set_motorB_direction(l289n_Direction dir);
void l289n_set_motorC_direction(l289n_Direction dir);
void l289n_set_motorD_direction(l289n_Direction dir);

void l289n_set_motorA_speed(uint16_t speed);
void l289n_set_motorB_speed(uint16_t speed);
void l289n_set_motorC_speed(uint16_t speed);
void l289n_set_motorD_speed(uint16_t speed);
void l289n_init();

#endif /* INC_L289N_H_ */
