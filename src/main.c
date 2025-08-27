#include "STD_TYPE.h"
#include <stdio.h>
#include <stdlib.h>
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MSPI_interface.h"
#include "TFT_interface.h"
#include "fonts.h"
#include "MADC_interface.h"
#include <stdint.h>

void float_to_string(float value, char *buffer, int decimal_points);
int main()
{
	u16 Analog_Val=0;
	char str[6];
	float volt=0.0;

	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePortA();
	MRCC_voidEnablePortB();
	MRCC_voidSPIEnable();
	MRCC_voidADC1Enable();

	MSPI_voidMasterInit();
	MADC1_voidInit();

	//	MGPIO_voidSetMode(PORTB,PIN12,OUTPUT_10MHz);
	MGPIO_voidSetMode(PORTB,PIN13,OUTPUT_10MHz);
	//	MGPIO_voidSetMode(PORTB,PIN14,INPUT);
	MGPIO_voidSetMode(PORTB,PIN15,OUTPUT_10MHz);
	//	MGPIO_voidSetOutputType(GPIOB,PIN12,AF_Pushpull);
	MGPIO_voidSetOutputType(PORTB,PIN13,AF_Pushpull);
	MGPIO_voidSetOutputType(PORTB,PIN15,AF_Pushpull);
	//	MGPIO_voidSetInputType(PORTB,PIN14,Floating);

//	MGPIO_voidSetMode(PORTA,PIN3,OUTPUT_2MHz);
//	MGPIO_voidSetOutputType(PORTA,PIN3,GP_Pushpull);
//	MGPIO_voidSetPinValue(PORTA,PIN3,PIN_HIGH);
//	MSTK_voidDelay_ms(1000);

	MGPIO_voidSetMode(PORTA,PIN0,INPUT);
	MGPIO_voidSetInputType(PORTA,PIN0,Analog);

	TFT_init();
	TFT_FillDisplay(TFT_BLACK);

	MADC1_voidCalibrate();

	while(1)
	{
		Analog_Val = MADC1_u16StartConversion_1CH(PA_CH0);

		volt = (Analog_Val * 3.3f) / 4095.0f;

		float_to_string(volt,str,2);

		MSTK_voidDelay_ms(200);

		TFT_WriteString(3,50,"Value= ",Font_11x18,TFT_BBLUE,TFT_BLACK);
		TFT_WriteString(66,70, str ,Font_11x18,TFT_BBLUE,TFT_BLACK);
		TFT_WriteString(99,70, "V" ,Font_11x18,TFT_BBLUE,TFT_BLACK);
	}

	return 0;
}



void float_to_string(float value, char *buffer, int decimal_points)
{
    int int_part = (int)value;
    float frac_part = value - int_part;
    int frac_int;

    if(frac_part < 0) frac_part = -frac_part;

    frac_part *= (decimal_points == 2) ? 100 : 10;
    frac_int = (int)(frac_part + 0.5f);

    sprintf(buffer, "%d.%0*d", int_part, decimal_points, frac_int);
}
