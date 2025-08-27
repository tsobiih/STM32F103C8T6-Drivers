#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "MADC_config.h"
#include "MADC_interface.h"
#include "MADC_privte.h"

void MADC1_voidInit(void)
{
	// turn on ADC
	ADC1->CR2 |= (1 << ADON);

	for (volatile int i = 0; i < 1000; i++); // small delay for wake up

    // Enable ADC again (actual enable)
    ADC1->CR2 |= (1 << ADON);

	// set sample time
	for (int i = 0 ; i < 10 ; i++)
	{
		ADC1->SMPR2 &=~ (BIT3_Musk << i*3);
		ADC1->SMPR2 |= (Sample_Time << i*3);
	}
}

u16 MADC1_u16StartConversion_1CH(channels _chnl)
{
    // awake ADC
    ADC1->CR2 |= (1 << ADON);

	//make the length bits of ADC to start one conversion
	ADC1->SQR1 &=~ (BIT4_Musk << LENGTH);
//	ADC1->SQR1 |= ( 0 << LENGTH);			// 1 is the number of conversions

	// put the desired channel in SQ1 bits to convert it
	ADC1->SQR3 &=~ (BIT5_Musk << SQ1);
	ADC1->SQR3 |= ( (_chnl&BIT5_Musk) << SQ1);

	//Start conversion
	ADC1->CR2 |= (1 << SWSTART);

	while(!READ_BIT(ADC1->SR,EOC));

	return  (u16)ADC1->DR;
}


void MADC1_voidCalibrate(void)
{
    // awake ADC
    ADC1->CR2 |= (1 << ADON);

	// reset calibration
	ADC1->CR2 |= (1 << RSTCAL);
	while(READ_BIT(ADC1->CR2,RSTCAL));

	// start calibration
	ADC1->CR2 |= (1 << CAL);
	while(READ_BIT(ADC1->CR2,CAL));
}
