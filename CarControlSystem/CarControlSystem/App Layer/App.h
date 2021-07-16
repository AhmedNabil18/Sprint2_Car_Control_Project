/*
 * App.h
 *
 * Created: 7/16/2021 1:22:44 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef APP_H_
#define APP_H_


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "../Srvc Layer/Service.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- CONSTANTS -*-*-*-*-*-*/

/*******************************************************************************
 *                          Module Data Types                                  *
 *******************************************************************************/
/*
 * Data Type for App return status
 */
typedef enum
{
	APP_STATUS_ERROR_NOK,
	APP_STATUS_ERROR_OK,
	APP_STATUS_ERROR_ID_INVALID,
	APP_STATUS_ERROR_NULL,
	APP_STATUS_INITIALIZED,
	APP_STATUS_UNINITIALIZED
}enuApp_Status_t;

/*
 * Data Type for Car state (Gear State)
 */
typedef enum
{
	CAR_STATE_IDLE,
	CAR_STATE_30F,
	CAR_STATE_60F,
	CAR_STATE_90F,
	CAR_STATE_30B
}enuCarGear_t;

/*
 * Data Type for Car Action state
 */
typedef enum
{
	CAR_ACTION_STOP,
	CAR_ACTION_MOVE,
	CAR_ACTION_LEFT,
	CAR_ACTION_RIGHT
}enuCarAction_t;

/*
 * Data Type for Car Button Pressed
 */
typedef enum
{
	CAR_MOVE_HOLD,
	CAR_LEFT_HOLD,
	CAR_RIGHT_HOLD,
	CAR_GEAR_PRESSED,
	CAR_BUTTONS_IDLE
}enuCarButton_t;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function to Start the application */
enuApp_Status_t CarApp_start(void);

/* Function to initialize the Application */
enuApp_Status_t CarApp_init(void);

/* Function to update the application */
enuApp_Status_t CarApp_update(void);



#endif /* APP_H_ */