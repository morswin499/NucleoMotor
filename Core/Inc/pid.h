/*
 * pid.h
 *
 *  Created on: Oct 3, 2025
 *      Author: morswin
 */

#ifndef INC_PID_H_
#define INC_PID_H_

typedef struct
{
	int previous_error; 		//Poprzedni błąd dla członu różniczkującego
	int total_error;		//Suma uchybów dla członu całkującego
	float Kp;			//Wzmocnienie członu proporcjonalnego
	float Ki;			//Wzmocnienie członu całkującego*/
	float Kd;			//Wzmocnienie członu różniczkującego*/
	int anti_windup_limit;		//Anti-Windup - ograniczenie członu całkującego*/
}pid_str;

void pid_init(pid_str *pid_data, float kp_init, float ki_init, float kd_init, int anti_windup_limit_init);
void pid_reset(pid_str *pid_data);
int pid_calculate(pid_str *pid_data, int setpoint, int process_variable);


#endif /* INC_PID_H_ */
