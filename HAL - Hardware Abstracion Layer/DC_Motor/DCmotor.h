 /*======================================
 *
 * Author: Hossam Nasr
 *
 * Module: DC Motor Driver
 *
 * File Name: DCmotor.h
 *
 *=======================================*/



#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* The Ports and Pins IDs for the DC-Motor two pins */
#define DC_MOTOR_PORT1_ID   PORTB_ID
#define DC_MOTOR_PORT2_ID   PORTB_ID

#define DC_MOTOR_PIN1_ID    PIN0_ID
#define DC_MOTOR_PIN2_ID    PIN1_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	DC_MOTOR_STOP,DC_MOTOR_CW,DC_MOTOR_ACW
}DcMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC Motor by:
 * 1. Setup the direction of the two motor pins as output by send the request to GPIO driver.
 * 2. Stop the motor at the beginning
 */
void DcMotor_Init(void);

/*
 * Description :
 * 1. Rotate  or Stop the motor according to the state input variable.
 */
void DcMotor_Rotate(DcMotor_State state);


#endif /* DC_MOTOR_H_ */
