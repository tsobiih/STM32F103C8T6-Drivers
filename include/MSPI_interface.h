/*
 * MSPI_interface.h
 *
 *  Created on: Aug 22, 2025
 *      Author: elwady
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

typedef enum
{
	devide_2,
	devide_4,
	devide_8,
	devide_16,
	devide_32,
	devide_64,
	devide_128,
	devide_256
}Prescaler;

void MSPI_voidMasterInit(void);
void MSPI_voidSalveInit(void);
void MSPI_voidSend(u8 msg);
u8 MSPI_u8Receive(void);

#define Bit3Musk	7


#endif /* MSPI_INTERFACE_H_ */
