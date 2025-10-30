/*
 * estpos.c
 *
 *  Created on: Oct 30, 2025
 *      Author: benia
 */
#include "estpos.h"
#include <math.h>

extern int posX;
extern int posY;
extern float alpha;
extern int vL;
extern int vR;
extern float walpha;

void estimate(int rpmL, int rpmR)
{
	vL= (PI * WHEEL_DIAMETER * rpmL / 60);
	vR= (PI * WHEEL_DIAMETER * rpmR / 60);
	walpha = (vR -vL)/WHEELBASE;
	alpha += DT * walpha;
	posX+=DT * vL * cos(alpha);
	posY+=DT * vL * sin(alpha);
}
