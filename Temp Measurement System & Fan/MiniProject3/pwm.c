/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: source file for the PWM driver
 *
 * Author: Omar Hossam El Din
 *
 *******************************************************************************/


#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "common_macros.h"
#include "pwm.h"


/*******************************************************************************
 *                               Functions Definition                          *
 *******************************************************************************/
static uint8 dutyCycle(uint8 duty_cycle)
{
	uint8 temp;
	temp = (duty_cycle*256)/100;
	return temp;
}
/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);  /* configure OC0 as an output to generate PWM on it */
	if(duty_cycle ==100)
	{
		OCR0 = 255;
	}
	else
	{

		OCR0  = dutyCycle(duty_cycle); // Set Compare Value
	}
	/*Configure the timer on fast PWM mode
	 * non-inverting mode
	 * prescaler = F_CPU/8
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}


