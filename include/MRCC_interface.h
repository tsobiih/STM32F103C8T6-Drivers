/*
 * MRCC_interface.h
 *
 *  Created on: Aug 2, 2025
 *      Author: elwady
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

typedef enum{
	HSI_oscillator,
	HSE_oscillator,
	PLL_oscillator,
}Oscillator_t;

typedef enum{
	AHB_BUS,
	APB1_BUS,
	APB2_BUS
}SYS_BUS;

void MRCC_voidInit();
void MRCC_voidEnablePeripheralClock(SYS_BUS sys_bus,u8 periphralID);
void MRCC_voidDisablePeripheralClock(SYS_BUS sys_bus,u8 periphralID);
u8 	 MRCC_u8SystemClockSwitchStatus(void);
void MRCC_voidEnablePortA(void);
void MRCC_voidEnablePortC(void);
void MRCC_voidEnablePortB(void);
void MRCC_voidSPIEnable(void);
void MRCC_voidADC1Enable(void);
void MRCC_voidADC2Enable(void);


#define HSE_CLOCK 0
#define HSI_CLOCK 1

#define BIT4_MUSK	15
#define BIT2_MUSK	3

/*_______AHB_________*/
#define AHB_CRCEN	6
#define AHB_SRAMEN	2
#define	AHB_DMA2EN	1
#define AHB_DMA1EN	0

/*_______APB1________*/
#define APB1_DACEN	29
#define	APB1_CAN2EN	26
#define APB1_CAN1EN	25
#define	APB1_I2C2EN	22
#define	APB1_I2C1EN	21
#define APB1_UART5EN 20
#define APB1_UART4EN 19
#define APB1_UART3EN 18
#define APB1_UART2EN 17
#define APB1_SPI3EN	15
#define APB1_SPI2EN  14
#define APB1_TIM7EN  5
#define APB1_TIM6EN	4
#define APB1_TIM5EN	3
#define APB1_TIM4EN	2
#define APB1_TIM3EN	1
#define APB1_TIM2EN	0

/*_______APB2________*/
#define APB2_USART1EN	14
#define	APB2_SPI1EN		12
#define APB2_TIM1EN		11
#define APB2_ADC2EN		10
#define APB2_ADC1EN		9
#define APB2_GPIOC		4
#define APB2_GPIOB		3
#define APB2_GPIOA		2
#define APB2_AF_CLK		0

#endif /* MRCC_INTERFACE_H_ */
