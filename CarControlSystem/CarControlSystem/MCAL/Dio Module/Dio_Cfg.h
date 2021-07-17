/*
 * Dio_Cfg.h
 *
 * Created: 7/13/2021 7:54:56 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "..\ATMega32_Registers.h"

#define DIO_USED_PINS_NUM		10

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                PORT_D /* PORTD */
#define DioConf_BUTTON1_PORT_NUM			 PORT_D
#define DioConf_BUTTON2_PORT_NUM			 PORT_D
#define DioConf_BUTTON3_PORT_NUM			 PORT_D
#define DioConf_BUTTON4_PORT_NUM			 PORT_D
#define DioConf_IN1_PORT_NUM                 PORT_B /* PORTB */
#define DioConf_IN2_PORT_NUM                 PORT_B /* PORTB */
#define DioConf_IN3_PORT_NUM                 PORT_B /* PORTB */
#define DioConf_IN4_PORT_NUM                 PORT_B /* PORTB */
#define DioConf_PWM_PORT_NUM				 PORT_D

/* DIO Configured Channel ID's */
#define DioConf_LED1_PIN_NUM				 PIN_5 /* Pin 5 in PORTD */
#define DioConf_BUTTON1_PIN_NUM				 PIN_0 /* Pin 0 in PORTD */
#define DioConf_BUTTON2_PIN_NUM				 PIN_1 /* Pin 1 in PORTD */
#define DioConf_BUTTON3_PIN_NUM				 PIN_2 /* Pin 2 in PORTD */
#define DioConf_BUTTON4_PIN_NUM				 PIN_3 /* Pin 3 in PORTD */
#define DioConf_IN1_PIN_NUM			   		 PIN_4
#define DioConf_IN2_PIN_NUM			   		 PIN_5
#define DioConf_IN3_PIN_NUM			   		 PIN_6
#define DioConf_IN4_PIN_NUM			   		 PIN_7
#define DioConf_PWM_PIN_NUM			   		 PIN_6

/* Channel Index in the array of structures in Dio_Cfg.c */
#define DIO_LED1_CHANNEL_ID				0
#define DIO_BUTTON1_PD0_CHANNEL_ID		1
#define DIO_BUTTON2_PD1_CHANNEL_ID		2
#define DIO_BUTTON3_PD2_CHANNEL_ID		3
#define DIO_BUTTON4_PD3_CHANNEL_ID		4
#define DIO_IN1_CHANNEL_ID				5
#define DIO_IN2_CHANNEL_ID				6
#define DIO_IN3_CHANNEL_ID				7
#define DIO_IN4_CHANNEL_ID				8
#define DIO_PWM_CHANNEL_ID				9

#endif /* DIO_CFG_H_ */