/*
 * Button_Cfg.h
 *
 * Created: 7/15/2021 6:36:31 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef BUTTON_CFG_H_
#define BUTTON_CFG_H_

#include "..\..\MCAL\Dio Module\Dio.h"

#define BUTTONS_USED_NUM		4U

#define BUTTON_1_M		DIO_BUTTON1_PD0_CHANNEL_ID		
#define BUTTON_2_L		DIO_BUTTON2_PD1_CHANNEL_ID		
#define BUTTON_3_R		DIO_BUTTON3_PD2_CHANNEL_ID		
#define BUTTON_4_G		DIO_BUTTON4_PD3_CHANNEL_ID		
	
#endif /* BUTTON_CFG_H_ */