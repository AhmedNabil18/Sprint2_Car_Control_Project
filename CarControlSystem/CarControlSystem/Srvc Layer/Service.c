/*
 * Service.c
 *
 * Created: 7/16/2021 2:09:18 PM
 *  Author: Ahmed Nabil
 */ 
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "Service.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- GLOBAL STATIC VARIABLES *-*-*-*-*-*/
enuSrvc_Status_t genu_SrvcStatus = SRVC_STATUS_UNINITIALIZED;
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*--*-*-*- FUNCTIONS IMPLEMENTATION -*-*-*-*-*-*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: CarApp_init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: enuSrvc_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Initialize the Service layer -- Initialize all the below layers.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
enuSrvc_Status_t Service_init(void)
{
	/* Check if the Service Layer has been already initialized */
	if(genu_SrvcStatus == SRVC_STATUS_INITIALIZED)
		return SRVC_STATUS_INITIALIZED;
		
		
	/* Call the initializer in Button and Motor*/
	if(BTTN_STATUS_ERROR_OK != Button_init())
		return SRVC_STATUS_ERROR_NOK;
	if(MOTOR_STATUS_ERROR_OK != Motor_init())
		return SRVC_STATUS_ERROR_NOK;
	
	genu_SrvcStatus = SRVC_STATUS_INITIALIZED;
	return SRVC_STATUS_ERROR_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Service_ReportButton
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): pu8_button - Pointer to variable to hold the button pressed
* Return value: enuSrvc_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Start the Application.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
enuSrvc_Status_t Service_ReportButton(uint8_t* pu8_button)
{
	uint8_t u8_ButtonsIndex=0;
	uint8_t u8_ButtonCurrState=0;
	for (u8_ButtonsIndex=1 ; u8_ButtonsIndex<=BUTTONS_USED_NUM; u8_ButtonsIndex++)
	{
		Button_updateState(u8_ButtonsIndex);
		Button_getState(u8_ButtonsIndex, &u8_ButtonCurrState);
		if(u8_ButtonCurrState == BUTTON_STATE_PRESSED)
		{
			*pu8_button = u8_ButtonsIndex;
			return SRVC_STATUS_ERROR_OK;
		}
	}
	*pu8_button = BUTTON_NULL;
	return SRVC_STATUS_ERROR_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Service_UpdateMotors
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): u8_motorAction - The action to be done on the motor 
*					u8_motorSpeed - The speed of the motor (Also holds the direction)
* Parameters (inout): None
* Parameters (out): None
* Return value: enuSrvc_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Update the state of the motor (Run the motor with the specific action
*				,direction and speed)
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
enuSrvc_Status_t Service_UpdateMotors(uint8_t u8_motorAction, uint8_t u8_motorSpeed)
{
	if(u8_motorAction == ACTION_STOP)
	{
		Motor_stop(MOTOR_LEFT);
		Motor_stop(MOTOR_RIGHT);
		return SRVC_STATUS_ERROR_OK;
	}
	uint8_t u8_speed = 0;
	uint8_t u8_leftMotorDir=MOTOR_FRWRD;
	uint8_t u8_rightMotorDir=MOTOR_FRWRD;
	
	switch (u8_motorSpeed)
	{
	case SPEED_30F:
		u8_speed = 30;
		break;
	case SPEED_60F:
		u8_speed = 60;
		break;
	case SPEED_90F:
		u8_speed = 90;
		break;
	case SPEED_30B:
		u8_speed = 30;
		u8_leftMotorDir = MOTOR_BKWRD;
		u8_rightMotorDir = MOTOR_BKWRD;
		break;
	}
	
	if (u8_motorAction == ACTION_LEFT)
	{
		u8_speed = 30;
		u8_leftMotorDir = MOTOR_FRWRD;
		u8_rightMotorDir = MOTOR_BKWRD;
	}else if (u8_motorAction == ACTION_RIGHT)
	{
		u8_speed = 30;
		u8_leftMotorDir = MOTOR_BKWRD;
		u8_rightMotorDir = MOTOR_FRWRD;
	}
	if( MOTOR_STATUS_ERROR_OK != Motor_run(MOTOR_LEFT,u8_speed,u8_leftMotorDir))
		return SRVC_STATUS_ERROR_NOK;
	if( MOTOR_STATUS_ERROR_OK != Motor_run(MOTOR_RIGHT,u8_speed,u8_rightMotorDir))
		return SRVC_STATUS_ERROR_NOK;
	Dio_writePin(DIO_LED1_CHANNEL_ID,PIN_HIGH);
	return  SRVC_STATUS_ERROR_OK;
}