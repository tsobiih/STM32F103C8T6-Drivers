#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "MRCC_config.h"
#include "MRCC_interface.h"
#include "MRCC_private.h"

void MRCC_voidInit()
{
#if(SYS_CLOCK == HSE_CLOCK)
	//Enable HSE
	RCC->CR |= (1<<HSEON);
	//Wait until it be ready
	while(!READ_BIT(RCC->CR,HSERD));

	//erase 2 bits
	RCC->CFGR &=~ (BIT2_MUSK << SW0);
	//Switch to HSE
	RCC->CFGR |= (HSE_oscillator << SW0);
	//Disable HSI Clock
	RCC->CR &=~ (1<<HSION);

#elif(SYS_CLOCK == HSI_CLOCK)
	//Enable HSI
	RCC->CR |= (1<<HSION);
	//Wait until it be ready
	while(!READ_BIT(RCC->CR,HSIRD));
	//erase 2 bits
	RCC->CFGR &=~ (BIT2_MUSK << SW0);
	//Switch to HSE
	RCC->CFGR |= (HSI_oscillator << SW0);
#endif
}
void MRCC_voidEnablePeripheralClock(SYS_BUS sys_bus,u8 periphralID)
{
	switch (sys_bus) {
	case AHB_BUS:
		RCC->AHBENR |= (1<<periphralID);
		break;
	case APB2_BUS:
		RCC->APB2ENR |= (1<<periphralID);
		break;
	case APB1_BUS:
		RCC->APB1ENR |= (1<<periphralID);
		break;
	default:
		break;
	}
}
void MRCC_voidDisablePeripheralClock(SYS_BUS sys_bus,u8 periphralID)
{
	switch (sys_bus) {
	case AHB_BUS:
		RCC->AHBENR &=~ (1<<periphralID);
		break;
	case APB2_BUS:
		RCC->APB2ENR &=~ (1<<periphralID);
		break;
	case APB1_BUS:
		RCC->APB1ENR &=~ (1<<periphralID);
		break;
	default:
		break;
	}
}
u8 	 MRCC_u8SystemClockSwitchStatus(void)
{
	u8 State = (READ_BIT(RCC->CFGR,3)<<1)|(READ_BIT(RCC->CFGR,2));
	return State;
}

void MRCC_voidEnablePortA(void)
{
	MRCC_voidEnablePeripheralClock(APB2_BUS,APB2_GPIOA);
}

void MRCC_voidEnablePortB(void)
{
	MRCC_voidEnablePeripheralClock(APB2_BUS,APB2_GPIOB);
}

void MRCC_voidEnablePortC(void)
{
	MRCC_voidEnablePeripheralClock(APB2_BUS,APB2_GPIOC);
}

void MRCC_voidSPIEnable(void)
{
	MRCC_voidEnablePeripheralClock(APB1_BUS,APB1_SPI2EN);
}

void MRCC_voidADC1Enable(void)
{
	MRCC_voidEnablePeripheralClock(APB2_BUS,APB2_ADC1EN);
}

void MRCC_voidADC2Enable(void)
{
	MRCC_voidEnablePeripheralClock(APB2_BUS,APB2_ADC2EN);
}
