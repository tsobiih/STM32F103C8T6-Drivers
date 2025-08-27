/*
 * MSPI_private.h
 *
 *  Created on: Aug 22, 2025
 *      Author: elwady
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

#define SPI2_BASE_ADRESS (0x40003800)

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 CFGR;
	u32	PR;
}MSPI_t;

#define SPI2 ((volatile MSPI_t*) SPI2_BASE_ADRESS)

#define DFF			11
#define LSBFIRST	7
#define SPE			6
#define BR			3
#define MSTR		2
#define CPOL		1
#define CPHA		0
#define BSY			7
#define TXE			1
#define RXNE		0
#define SSOE		2
#define SSM			9
#define SSI			8

#endif /* MSPI_PRIVATE_H_ */
