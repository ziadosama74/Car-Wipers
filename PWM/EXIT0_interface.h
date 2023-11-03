/*
 * EXIT0_interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: ziad osama
 */

#ifndef EXIT0_INTERFACE_H_
#define EXIT0_INTERFACE_H_

void EXIT0_voidIntit(void);
void EXIT0_voidSenseControl(u8 Copy_u8Sense);
void EXTI0_voidSetCallBack(void *Copy_PV_CallBack(void)); // PV --> pointer to void
//void EXTIO_voidClearFlag(void);
//void EXTIO_voidSetFlag(void);

#define LOW_LEVEL                 1
#define ANY_CHANGE                2
#define FALING_EDGE               3
#define RISING_EDGE               4

#endif /* EXIT0_INTERFACE_H_ */
