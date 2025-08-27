/*
 * MADC_privte.h
 *
 *  Created on: Aug 25, 2025
 *      Author: elwady
 */

#ifndef MADC_PRIVTE_H_
#define MADC_PRIVTE_H_

#define ADC1_BASE_ADDRESS (0x40012400)
#define ADC2_BASE_ADDRESS (0x40012800)
#define ADC3_BASE_ADDRESS (0x40013C00)

typedef struct
{
	u32 SR;
	u32 CR1;
	u32 CR2;
	u32 SMPR1;
	u32 SMPR2;
	u32 JOFR1;
	u32 JOFR2;
	u32 JOFR3;
	u32 JOFR4;
	u32 HTR;
	u32 LTR;
	u32 SQR1;
	u32 SQR2;
	u32 SQR3;
	u32 JSQR;
	u32 JDR1;
	u32 JDR2;
	u32 JDR3;
	u32 JDR4;
	u32 DR;

}ADC_t;

#define ADC1	((volatile ADC_t*) ADC1_BASE_ADDRESS)
#define ADC2	((volatile ADC_t*) ADC2_BASE_ADDRESS)
#define ADC3	((volatile ADC_t*) ADC3_BASE_ADDRESS)

#define STRT	4
#define JSTRT	3
#define JEOC	2
#define EOC		1

#define SWSTART		22
#define RSTCAL		3
#define CAL			2
#define ADON		0

#define LENGTH		20

#define SQ1			0


#endif /* MADC_PRIVTE_H_ */
