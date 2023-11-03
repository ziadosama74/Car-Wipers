/*
 * TIMER0_program.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ziad osama
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER0_confuge.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_register.h"

void (*TIMER0_CallBack)(void);

void TIMER0_voidInit(void)
{
	/* select the mode */
#if (TIMER0_MODE == CTC_MODE)
	CLEAR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#elif (TIMER0_MODE == NORMAL_MODE)
	CLEAR_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,3);
#elif(TIMER0_MODE == FAST_PWM)
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#endif
	/*Clear On Compare Match OCR0 Top */
	SET_BIT(TCCR0,5);
	CLEAR_BIT(TCCR0,4);
	/* clkI/O/8 */
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);
	/* Initial value for the OCR0 */
	OCR0 = TIMER0_OCR_VALUE;
	/* select the Enable mode interrupt */
#if(TIMER0_MODE == CTC_MODE)
	SET_BIT(TIMSK,1);
#elif(TIMER0_MODE == NORMAL_MODE)
	SET_BIT(TIMSK,0);
#endif
}
void TIMER0_voidSetOCRValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}
void TIMER0_voidSetCallBack(void *Copy_PV_CallBack(void))
{
	TIMER0_CallBack = Copy_PV_CallBack;
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	TIMER0_CallBack();
}
