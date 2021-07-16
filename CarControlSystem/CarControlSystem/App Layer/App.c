/*
 * App.c
 *
 * Created: 7/16/2021 1:22:50 PM
 *  Author: Ahmed Nabil
 */ 

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "App.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- GLOBAL STATIC VARIABLES *-*-*-*-*-*/
static enuCarGear_t enuCurrentGear = CAR_STATE_IDLE;
static enuCarAction_t enuCurrentAction = CAR_ACTION_STOP;
static enuApp_Status_t enuCurrentAppStatus = APP_STATUS_UNINITIALIZED;
static enuCarButton_t enuCurrentButton = CAR_BUTTONS_IDLE;
uint8_t gu8_buttonPressed = 0;
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*--*-*-*- FUNCTIONS IMPLEMENTATION -*-*-*-*-*-*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: CarApp_init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: enuApp_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Initialize the Application.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
enuApp_Status_t CarApp_init(void)
{
	if (enuCurrentAppStatus == APP_STATUS_INITIALIZED)
	{
		return APP_STATUS_INITIALIZED;
	}
	/* Call the initializer in service layer*/
	if(SRVC_STATUS_ERROR_OK != Service_init())
	{
		return APP_STATUS_ERROR_NOK;
	}
	/* Update enuCurrentAppStatus to initialized */
	enuCurrentAppStatus = APP_STATUS_INITIALIZED;
	return APP_STATUS_ERROR_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: CarApp_start
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: enuApp_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Start the Application.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
enuApp_Status_t CarApp_start(void)
{
	/* Initialize the Car application */
	CarApp_init();
	EnableGlbl_Interrupt();
	/* Application Super Loop */
	while (1)
	{
		/* Update the car status */
		CarApp_update();
		
		/* Delay */
	}
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: CarApp_update
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: enuApp_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Update the state of the application.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
enuApp_Status_t CarApp_update(void)
{
	/* Get Button Pressed */
	Service_ReportButton(&gu8_buttonPressed);
	
	/* Fill the enuCurrentButton according to the button pressed */
	switch (gu8_buttonPressed)
	{
	/*******************************************************************************/
	/*******************************************************************************/
	case CAR_MOVE_HOLD:
		/* Check if it's already Moving */
		if(enuCurrentButton == CAR_MOVE_HOLD)
		{
			Dio_writePin(DIO_LED1_CHANNEL_ID,PIN_LOW);
			break;
		}
		/* Fill the enuCurrentButton according to the button pressed */
		enuCurrentButton = CAR_MOVE_HOLD;
		/* Update the enuCurrentAction */
		enuCurrentAction = CAR_ACTION_MOVE;
		/* 
		* Update the Motor according to the enuCurrentAction and enuCurrentGear
		* Sent to service layer
		*/
		if (enuCurrentGear == CAR_STATE_IDLE)
		{
			break;
		}
		Service_UpdateMotors((uint8_t)enuCurrentAction, (uint8_t)enuCurrentGear);
		break;
		
	/*******************************************************************************/
	/*******************************************************************************/
	case CAR_LEFT_HOLD:
		Dio_writePin(DIO_LED1_CHANNEL_ID,PIN_HIGH);
		/* Check if it's already Moving Left */
		if(enuCurrentButton == CAR_LEFT_HOLD)
			break;
		/* Fill the enuCurrentButton according to the button pressed */
		enuCurrentButton = CAR_LEFT_HOLD;
		/* Update the enuCurrentAction */
		enuCurrentAction = CAR_ACTION_LEFT;
		/* 
		* Update the Motor according to the enuCurrentAction and enuCurrentGear
		* Sent to service layer
		*/
		Service_UpdateMotors((uint8_t)enuCurrentAction, (uint8_t)CAR_STATE_30F);
		break;
		
	/*******************************************************************************/
	/*******************************************************************************/
	case CAR_RIGHT_HOLD:
		/* Check if it's already Moving Right */
		if(enuCurrentButton == CAR_RIGHT_HOLD)
			break;
		/* Fill the enuCurrentButton according to the button pressed */
		enuCurrentButton = CAR_RIGHT_HOLD;
		/* Update the enuCurrentAction */
		enuCurrentAction = CAR_ACTION_RIGHT;
		/* 
		* Update the Motor according to the enuCurrentAction and enuCurrentGear
		* Sent to service layer
		*/
		Service_UpdateMotors((uint8_t)enuCurrentAction, (uint8_t)CAR_STATE_30F);
		break;
		
	/*******************************************************************************/
	/*******************************************************************************/
	case CAR_GEAR_PRESSED:
		/* Check if it's already Moving Right */
		if(enuCurrentButton == CAR_GEAR_PRESSED)
			break;
		/* Fill the enuCurrentButton according to the button pressed */
		enuCurrentButton = CAR_GEAR_PRESSED;
		/* Update flag indicate the hold state and ignore it */
		
		/* Update the enuCurrentGear */
		if(enuCurrentGear != CAR_STATE_30B)
			enuCurrentGear++;
		else
			enuCurrentGear = CAR_STATE_30F;
		break;
	
	/*******************************************************************************/
	/*******************************************************************************/
	case CAR_BUTTONS_IDLE:
		Dio_writePin(DIO_LED1_CHANNEL_ID,PIN_LOW);
		/* Check if it's already Moving Right */
		if(enuCurrentButton == CAR_BUTTONS_IDLE)
			break;
		/* Fill the enuCurrentButton according to the button pressed */
		enuCurrentButton = CAR_BUTTONS_IDLE;
		/* Clear flag indicate the hold state and ignore it */
		/* Update the enuCurrentAction */
		enuCurrentAction = CAR_ACTION_STOP;
		/* 
		* Update the Motor according to the enuCurrentAction and enuCurrentGear
		* Sent to service layer
		*/
		Service_UpdateMotors((uint8_t)enuCurrentAction, (uint8_t)enuCurrentGear);
		break;
	default:
		break;
	}
	/*******************************************************************************/
	/*******************************************************************************/

	return APP_STATUS_ERROR_OK;
}