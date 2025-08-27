/*
 * MADC_interface.h
 *
 *  Created on: Aug 25, 2025
 *      Author: elwady
 */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_

typedef enum
{
	cycle1_5,
	cycle7_5,
	cycle13_5,
	cycle28_5,
	cycle41_5,
	cycle55_5,
	cycle71_5,
	cycle239_5
}Sample_Cycle;

typedef enum
{
	PA_CH0,
    PA_CH1,
    PA_CH2,
    PA_CH3,
    PA_CH4,
    PA_CH5,
    PA_CH6,
    PA_CH7,
    PB_CH8,
    PB_CH9
}channels;

void MADC1_voidInit(void);
u16 MADC1_u16StartConversion_1CH(channels _chnl);
void MADC1_voidCalibrate(void);

#define BIT3_Musk	7
#define BIT4_Musk	15
#define BIT5_Musk	31

#endif /* MADC_INTERFACE_H_ */
