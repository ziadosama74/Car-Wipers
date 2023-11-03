/*
 * EXIT0_register.h
 *
 *  Created on: Aug 28, 2023
 *      Author: ziad osama
 */

#ifndef EXIT0_REGISTER_H_
#define EXIT0_REGISTER_H_

#define   MCUCR    *((volatile u8*)(0x55))
#define   MCUCSR   *((volatile u8*)(0x54))
#define   GICR     *((volatile u8*)(0x5B))
#define   GIFR     *((volatile u8*)(0x5A))

#endif /* EXIT0_REGISTER_H_ */
