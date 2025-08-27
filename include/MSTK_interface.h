/*
 * MSTK_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: elwady
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

void MSTK_voidInit(void);
void MSTK_voidDelay_us(u32 value);
void MSTK_voidDelay_ms(u16 value);
u32  MSTK_u32GetElapsedTime(void);
void MSTK_voidDisableSystickINT(void);
void MSTK_voidEnableSystickINT(void);

//is the maximum load value thar the register can carry
// max delay with us is 16777215
// max delay with ms is 16777.215
// max delay with s is 16.777215
#define MAX_LOAD	16777215

#endif /* MSTK_INTERFACE_H_ */
