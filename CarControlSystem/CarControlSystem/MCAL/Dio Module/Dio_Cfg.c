/*
 * Dio_Cfg.c
 *
 * Created: 7/13/2021 7:55:09 PM
 *  Author: Ahmed Nabil
 */ 

#include "Dio_Cfg.h"
#include "Dio.h"

strDio_Config_t strDio_pins[DIO_USED_PINS_NUM]=
{
	{DioConf_LED1_PORT_NUM, DioConf_LED1_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_BUTTON1_PORT_NUM, DioConf_BUTTON1_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PDR},
	{DioConf_BUTTON2_PORT_NUM, DioConf_BUTTON2_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PDR},
	{DioConf_BUTTON3_PORT_NUM, DioConf_BUTTON3_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PDR},
	{DioConf_BUTTON4_PORT_NUM, DioConf_BUTTON4_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PDR},
	{DioConf_IN1_PORT_NUM, DioConf_IN1_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_IN2_PORT_NUM, DioConf_IN2_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_IN3_PORT_NUM, DioConf_IN3_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_IN4_PORT_NUM, DioConf_IN4_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_PWM_PORT_NUM, DioConf_PWM_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW}
};

/*
typedef struct
{
	uint8_t u8_PortNum;
	uint8_t u8_PinNum;
	enuDio_Direction_t u8_Direction;
	uint8_t u8_InitState; 
}strDio_Config_t;*/