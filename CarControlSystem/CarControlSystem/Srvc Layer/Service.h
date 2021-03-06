/*
 * Service.h
 *
 * Created: 7/16/2021 2:09:25 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef SERVICE_H_
#define SERVICE_H_

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "../ECUAL/Motor Module/Motor.h"
#include "../ECUAL/Button Module/Button.h"
#include "Service_Cfg.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- CONSTANTS -*-*-*-*-*-*/

#define ACTION_STOP		0U
#define ACTION_MOVE		1U
#define ACTION_LEFT		2U
#define ACTION_RIGHT	3U

#define SPEED_IDLE		0U
#define SPEED_30F		1U
#define SPEED_60F		2U
#define SPEED_90F		3U
#define SPEED_30B		4U
/*******************************************************************************
 *                          Module Data Types                                  *
 *******************************************************************************/
/*
 * Data Type for App return status
 */
typedef enum
{
	SRVC_STATUS_ERROR_NOK,
	SRVC_STATUS_ERROR_OK,
	SRVC_STATUS_ERROR_ID_INVALID,
	SRVC_STATUS_ERROR_NULL,
	SRVC_STATUS_INITIALIZED,
	SRVC_STATUS_UNINITIALIZED
}enuSrvc_Status_t;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function to initialize the Service Layer */
enuSrvc_Status_t Service_init(void);

/* Function to report back the button pressed */
enuSrvc_Status_t Service_ReportButton(uint8_t* pu8_button);

/* Function to update the motors Action */
enuSrvc_Status_t Service_UpdateMotors(uint8_t u8_motorAction, uint8_t u8_motorSpeed);

#endif /* SERVICE_H_ */