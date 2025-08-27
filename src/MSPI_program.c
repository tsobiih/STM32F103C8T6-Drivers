#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "MSPI_config.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"

void MSPI_voidMasterInit(void)
{
	// Set boud rate to 1 MHz
	SPI2->CR1 &=~ (Bit3Musk << BR);
	SPI2->CR1 |= (devide_8 << BR);

	// Enable SS output enable
	//	SPI2->CR2 |= (1 << SSOE);

	/*_______Enable Software Slave Management_______*/
	SET_BIT(SPI2->CR1, SSM);
	SET_BIT(SPI2->CR1, SSI);

	// CK 1 while idle
	SPI2->CR1 |= (1 << CPOL);

	//enable master mode
	SPI2->CR1 |= (1 << MSTR);

	//spi enable
	SPI2->CR1 |= (1 << SPE);
}
void MSPI_voidSalveInit(void)
{
	//slave by default
	SPI2->CR1 &=~ (1 << MSTR);

	//spi enable
	SPI2->CR1 |= (1 << SPE);
}

void MSPI_voidSend(u8 msg)
{
	while(!READ_BIT(SPI2->SR, TXE));  // TX buffer empty
	SPI2->DR = msg;                  // Send data
	while(SPI2->SR & (1 << BSY));     // Wait until not busy
}
u8 MSPI_u8Receive(void)
{
	SPI2->DR = 0xFF; // Dummy
	while(!READ_BIT(SPI2->SR,RXNE));
	return (u8)SPI2->DR;
}
