/*
 * Motor_Cfg.c
 *
 * Created: 7/15/2021 11:12:52 PM
 *  Author: Ahmed Nabil
 */ 

#include "Motor.h"

const strMotor_Config_t str_MotorsConfig[MOTORS_USED_NUM] = 
{
	{SWPWM_CHANNEL_0_ID,DIO_IN1_CHANNEL_ID,DIO_IN2_CHANNEL_ID,MOTOR_R_OPERATING_FREQ},
	{SWPWM_CHANNEL_0_ID,DIO_IN3_CHANNEL_ID,DIO_IN4_CHANNEL_ID,MOTOR_L_OPERATING_FREQ}
};