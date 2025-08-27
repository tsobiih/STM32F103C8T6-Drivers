/*
 * MSTK_private.h
 *
 *  Created on: Aug 5, 2025
 *      Author: elwady
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

#define MSTK_BASE_ADDRESS (0xE000E010)

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSTK_t;

#define STK ((volatile MSTK_t*)MSTK_BASE_ADDRESS)

#define COUNTFLAG	16
#define ENABLE		0
#define TICKINT		1
#define CLKSOURCE	2


#endif /* MSTK_PRIVATE_H_ */
