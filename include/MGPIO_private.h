/*
 * MGPIO_private.h
 *
 *  Created on: Aug 3, 2025
 *      Author: elwady
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADRESS (0x40010800)
#define GPIOB_BASE_ADRESS (0x40010C00)
#define GPIOC_BASE_ADRESS (0x40011000)
#define AF_BASE_ADRESS	(0x40010000)

typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIOs_t;

typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR1;
	u32 EXTICR2;
	u32 EXTICR3;
	u32 EXTICR4;
	u32 Reserved1;
	u32 MAPR2;
}AFIOs_t;

#define MGPIOA ((volatile GPIOs_t*)GPIOA_BASE_ADRESS)
#define MGPIOB ((volatile GPIOs_t*)GPIOB_BASE_ADRESS)
#define MGPIOC ((volatile GPIOs_t*)GPIOC_BASE_ADRESS)
#define MAFIO ((volatile AFIOs_t*)AF_BASE_ADRESS)

#endif /* MGPIO_PRIVATE_H_ */
