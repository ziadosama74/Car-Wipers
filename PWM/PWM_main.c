/*
 * PWM_main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: ziad osama
 */
#include  "STD_TYPE.h"
#include  "BIT_MATH.h"
#include  "PWM_interface.h"
#include  "DIO_interface.h"
#include "EXIT0_interface.h"
#include "EXIT0_confuge.h"
#include "GIE_interface.h"
#include  <util/delay.h>

void Led(void);
static u8 Check = 0 ;
int main(void)
{
	DIO_voidSetPinDirection(DIO_u8PORTD,2,DIO_u8INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD,2,DIO_u8HIGH);
	DIO_voidSetPinDirection(DIO_u8PORTD,5,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTA,0,DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORTA,1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTA,2,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTA,3,DIO_u8OUTPUT);
	PWM_voidInit();
	GIE_voidEnable();
	EXIT0_voidIntit();
	EXTI0_voidSetCallBack(Led);
	PWM_voidSetTopValue(20000);
	while(1)
	{
		DIO_voidSetPinValue(DIO_u8PORTA,2,DIO_u8LOW);
		DIO_voidSetPinValue(DIO_u8PORTA,3,DIO_u8HIGH);
		Check = 0 ;
		DIO_voidSetPinValue(DIO_u8PORTA,1,DIO_u8LOW);
		PWM_voidSetOCRValue(0);
		if ((DIO_U8_GetPinValue(DIO_u8PORTA,0)) == 1 )
		{
			while(1)
			{
				if(Check == 1)
				{
					break;
				}
				DIO_voidSetPinValue(DIO_u8PORTA,1,DIO_u8HIGH);
				DIO_voidSetPinValue(DIO_u8PORTA,2,DIO_u8HIGH);
				DIO_voidSetPinValue(DIO_u8PORTA,3,DIO_u8LOW);
				PWM_voidSetOCRValue(500);
				_delay_ms(100);
				PWM_voidSetOCRValue(0);
				_delay_ms(100);
			}
		}
	}
}

void Led(void){
	DIO_voidSetPinValue(DIO_u8PORTA,1,DIO_u8LOW);
	PWM_voidSetOCRValue(0);
	DIO_voidSetPinValue(DIO_u8PORTA,2,DIO_u8LOW);
	DIO_voidSetPinValue(DIO_u8PORTA,3,DIO_u8HIGH);
	Check = 1 ;
	EXIT0_voidSenseControl(RISING_EDGE);
}


