 /*======================================
 *
 * Author: Hossam Nasr
 *
 * Module: DC Motor Driver
 *
 * File Name: DCmotor.c
 *
 *=======================================*/

#include "DCmotor.h"
#include "gpio.h"

/*
 * Description :
 * Initialize the DC Motor by:
 * 1. Setup the direction of the two motor pins as output by send the request to GPIO driver.
 * 2. Stop the motor at the beginning
 */
void DcMotor_Init(void)
{
	/* Setup the two motor pins as output pins */
	GPIO_setupPinDirection(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);

	/* Motor is stopped at the beginning */
	GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
}

/*
 * Description :
 * 1. Rotate  or Stop the motor according to the state input variable.
 */
void DcMotor_Rotate(DcMotor_State state)
{
	if(state == DC_MOTOR_CW)
	{
		/* Rotates the Motor CW */
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_HIGH);
	}
	else if(state == DC_MOTOR_ACW)
	{
		/* Rotates the Motor A-CW */
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
	}
	else if(state == DC_MOTOR_STOP)
	{
		/* Stop the Motor */
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
    }
	else
	{
		/* Invalid Input State - Do Nothing */
	}
}
