/*
 * MRCC_private.h
 *
 *  Created on: Aug 2, 2025
 *      Author: elwady
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define RCC_BASE_ADRESS (0x40021000)

typedef struct{
	u32 CR;
	u32 CFGR;
	u32	CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
	u32 AHBSTR;
	u32 CFGR2;
}RCC_t;

#define RCC ((volatile RCC_t*)RCC_BASE_ADRESS)

#define HSEON	16
#define HSERD	17

#define HSION	0
#define HSIRD	1

#define SW0		0

#endif /* MRCC_PRIVATE_H_ */
