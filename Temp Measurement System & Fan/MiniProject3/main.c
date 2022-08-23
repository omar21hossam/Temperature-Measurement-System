/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: main function of mini project 3
 *
 * Author: Omar Hossam El Din
 *
 *******************************************************************************/


#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "adc.h"




int main (void)
{
	uint8 temp;
	/*adc configuration structure with internal voltage =2.56
	 *prescaler F_CPU/8
	 */
	ADC_ConfigType ADC_Config ={internal_256,F_CPU_8};
	/* Initialize ADC , LCD and Dc-motor drivers */
	ADC_init(&ADC_Config);
	LCD_init();
	DcMotor_Init();
	while(1)
	{
		temp = LM35_getTemperature();
		if (temp < 30)
		{
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_displayStringRowColumn(1,3,"Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(stop, 0);
		}
		else if (temp < 60)
		{
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_displayStringRowColumn(1,3,"Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 25);
		}
		else if (temp < 90)
		{
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_displayStringRowColumn(1,3,"Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 50);

		}
		else if (temp < 120)
		{
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_displayStringRowColumn(1,3,"Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 75);
		}
		else
		{
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_displayStringRowColumn(1,3,"Temp =    C");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 100);
		}
	}
}
