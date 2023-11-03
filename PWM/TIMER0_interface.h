/*
 * TIMER0_interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: ziad osama
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);
void TIMER0_voidSetOCRValue(u8 Copy_u8Value);
void TIMER0_voidSetCallBack(void *Copy_PV_CallBack(void));

#endif /* TIMER0_INTERFACE_H_ */
