/*
 * Motor.c
 *
 * Created: 7/15/2021 11:12:37 PM
 *  Author: Ahmed Nabil
 */ 

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "Motor.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- GLOBAL STATIC VARIABLES *-*-*-*-*-*/
u8_MotorState_t	gau8_MotorsState[MOTORS_USED_NUM] = {MOTOR_STOPPED};

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*--*-*-*- FUNCTIONS IMPLEMENTATION -*-*-*-*-*-*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Motor_init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: enuMotor_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Initialize the Motor module.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/* Function to initialize the motor module */
enuMotor_Status_t Motor_init(void)
{
/**************************************************************************************/
/*								Start of Error Checking								  */
/**************************************************************************************/
// /* Check if the motor index is invalid */
// 	if (BUTTONS_USED_NUM <= u8_bttnID)
// 	{
// 		return BTTN_STATUS_ERROR_ID_INVALID;
// 	}else{/*Nothing to here*/}
// 	
// 	/* Check if the input parameter is NULL */
// 	if (NULL_PTR == pu8_state)
// 	{
// 		return BTTN_STATUS_ERROR_NULL;
// 	}else{/*Nothing to here*/}
		
/**************************************************************************************/
/*								End of Error Checking								  */
/**************************************************************************************/
	SWPwm_Init();
/**************************************************************************************/
/*								Function Implementation								  */
/**************************************************************************************/
	return MOTOR_STATUS_ERROR_OK;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Motor_run
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): u8_motorID - Index for the motor in the module
*					u8_speed - Speed of the motor in %
*					u8_direction - Direction of the motor (CLOCK WISE - ANTI CLOCK WISE)
* Parameters (inout): None
* Parameters (out): None
* Return value: enuMotor_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Move the motor in the given direction.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/* Function to move the motor forward with given speed in % */
enuMotor_Status_t Motor_run(uint8_t u8_motorID, uint8_t u8_speed, uint8_t u8_direction)
{
	/**************************************************************************************/
	/*								Start of Error Checking								  */
	/**************************************************************************************/
	/* Check if the motor index is invalid */
	if (MOTORS_USED_NUM <= u8_motorID)
	{
		return MOTOR_STATUS_ERROR_ID_INVALID;
	}else{/*Nothing to here*/}
		
	/* Check if the speed is out of range */
	if (100 < u8_speed)
	{
		return MOTOR_STATUS_ERROR_SPD_INVALID;
	}else{/*Nothing to here*/}
		
	/* Check if the motor index is invalid */
	if (MOTOR_DIR_ANTI_CLK_WISE < u8_direction)
	{
		return MOTOR_STATUS_ERROR_DIR_INVALID;
	}else{/*Nothing to here*/}
	
	/* Check if the motor is already running */
	if(gau8_MotorsState[u8_motorID] == MOTOR_RUNNING)		
	{
		return MOTOR_STATUS_ERROR_RUNNING;
	}else{/*Nothing to here*/}
/**************************************************************************************/
/*								End of Error Checking								  */
/**************************************************************************************/

/**************************************************************************************/
/*								Function Implementation								  */
/**************************************************************************************/
	if(u8_direction == MOTOR_DIR_CLK_WISE)
	{
		Dio_writePin(str_MotorsConfig[u8_motorID].u8_MotorDirPin1, PIN_HIGH);
		Dio_writePin(str_MotorsConfig[u8_motorID].u8_MotorDirPin2, PIN_LOW);
	}else if(u8_direction == MOTOR_DIR_ANTI_CLK_WISE)
	{
		Dio_writePin(str_MotorsConfig[u8_motorID].u8_MotorDirPin1, PIN_LOW);
		Dio_writePin(str_MotorsConfig[u8_motorID].u8_MotorDirPin2, PIN_HIGH);
	}
	
	gau8_MotorsState[u8_motorID] = MOTOR_RUNNING;
	SWPwm_Start(str_MotorsConfig[u8_motorID].u8_MotorPwmChannel, str_MotorsConfig[u8_motorID].u16_Frequency, u8_speed);
	
	return MOTOR_STATUS_ERROR_OK;
}

/* Function to move the motor backward with given speed in % */
//enuMotor_Status_t Motor_moveBackward(uint8_t u8_motorID, uint8_t u8_speed);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Motor_stop
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): u8_motorID - Index for the motor in the module
* Parameters (inout): None
* Parameters (out): None
* Return value: enuMotor_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Stop the motor.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/* Function to stop motor */
enuMotor_Status_t Motor_stop(uint8_t u8_motorID)
{
/**************************************************************************************/
/*								Start of Error Checking								  */
/**************************************************************************************/
	/* Check if the motor index is invalid */
	if (MOTORS_USED_NUM <= u8_motorID)
	{
		return MOTOR_STATUS_ERROR_ID_INVALID;
	}else{/*Nothing to here*/}
				
/**************************************************************************************/
/*								End of Error Checking								  */
/**************************************************************************************/

/**************************************************************************************/
/*								Function Implementation								  */
/**************************************************************************************/
	Dio_writePin(str_MotorsConfig[u8_motorID].u8_MotorDirPin1, PIN_LOW);
	Dio_writePin(str_MotorsConfig[u8_motorID].u8_MotorDirPin2, PIN_LOW);
	
	uint8_t u8_loopIndex = 0;
	
	for(u8_loopIndex = 0; u8_loopIndex<MOTORS_USED_NUM; u8_loopIndex++)
	{
		if(u8_loopIndex == u8_motorID)
		{
			continue;
		}
		if(str_MotorsConfig[u8_motorID].u8_MotorPwmChannel == str_MotorsConfig[u8_loopIndex].u8_MotorPwmChannel)
		{
			break;
		}
	}
	if(u8_loopIndex == MOTORS_USED_NUM)
	{
		SWPwm_Stop(str_MotorsConfig[u8_motorID].u8_MotorPwmChannel);
	}else
	{
		if (gau8_MotorsState[u8_loopIndex] == MOTOR_STOPPED)
		{
			SWPwm_Stop(str_MotorsConfig[u8_motorID].u8_MotorPwmChannel);
		} 
	}
	gau8_MotorsState[u8_motorID] = MOTOR_STOPPED;
	return MOTOR_STATUS_ERROR_OK;
}