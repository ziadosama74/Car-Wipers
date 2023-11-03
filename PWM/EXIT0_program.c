/*
 * EXIT0_program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: ziad osama
 */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXIT0_interface.h"
#include "EXIT0_register.h"
#include "EXIT0_confuge.h"
#include "EXIT0_private.h"

void (*EXIT0_CallBack)(void);
void EXIT0_voidIntit(void)
{
	switch(SENSE)
	{
	case LOW_LEVEL :
		CLEAR_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
		break;
	case ANY_CHANGE :
		SET_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
		break;
	case FALING_EDGE :
		CLEAR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	}

	SET_BIT(GICR,6);

}

void EXIT0_voidSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL :
		CLEAR_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
		break;
	case ANY_CHANGE :
		SET_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
		break;
	case FALING_EDGE :
		CLEAR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	}
}

void EXTI0_voidSetCallBack(void *Copy_PV_CallBack(void))
{
	EXIT0_CallBack = Copy_PV_CallBack;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXIT0_CallBack();
}
//void EXTIO_voidClearFlag(void)
//{
//	SET_BIT(GIFR,6);
//}
//void EXTIO_voidSetFlag(void)
//{
//	CLEAR_BIT(GIFR,6);
//}
