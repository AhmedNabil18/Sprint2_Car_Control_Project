/*
 * Button_Cfg.c
 *
 * Created: 7/16/2021 9:08:21 PM
 *  Author: Ahmed Nabil
 */ 
#include "Button.h"

uint8_t gau8_buttonsUsed[BUTTONS_USED_NUM] =
{
	DIO_BUTTON1_PD0_CHANNEL_ID, 
	DIO_BUTTON2_PD1_CHANNEL_ID, 
	DIO_BUTTON3_PD2_CHANNEL_ID, 
	DIO_BUTTON4_PD3_CHANNEL_ID
};