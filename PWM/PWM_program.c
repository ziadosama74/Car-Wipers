/*
 * PWM_program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: ziad osama
 */
#include  "STD_TYPE.h"
#include  "BIT_MATH.h"
#include  "PWM_confuge.h"
#include  "PWM_interface.h"
#include  "PWM_private.h"
#include  "PWM_register.h"

void PWM_voidInit(void)
{
	/* Clear OC1A on compare match, set OC1A at TOP  I work on channel A Pin A*/

	SET_BIT(TCCR1A , 7);
	CLEAR_BIT(TCCR1A,6);

	/* Select Fast PWM Mode */

	CLEAR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);

	/* clkI/O/8 From PreScaler */

	CLEAR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B , 1);
	CLEAR_BIT(TCCR1B,2);

}
void PWM_voidSetTopValue(u16 Copy_u16Value)
{
	ICR1 = Copy_u16Value;
}
void PWM_voidSetOCRValue(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value;
}
