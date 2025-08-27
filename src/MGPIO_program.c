#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "MGPIO_config.h"
#include "MGPIO_interface.h"
#include "MGPIO_private.h"

void MGPIO_voidSetMode(PORT_t port,PIN_t pin,MODE_t mode)
{
	switch (port) {
		case PORTA:
				if(pin < 8){
					MGPIOA->CRL &=~ (BIT2_MUSK << (pin*4));
					MGPIOA->CRL |= (mode << (pin*4));
				}
				else{
					MGPIOA->CRH &=~ (BIT2_MUSK << ((pin-8)*4));
					MGPIOA->CRH |= (mode << ((pin-8)*4));
				}
			break;
		case PORTB:
			if(pin < 8){
				MGPIOB->CRL &=~ (BIT2_MUSK << (pin*4));
				MGPIOB->CRL |= (mode << (pin*4));
			}
			else{
				MGPIOB->CRH &=~ (BIT2_MUSK << ((pin-8)*4));
				MGPIOB->CRH |= (mode << ((pin-8)*4));
			}
			break;
		case PORTC:
			if(pin < 8){
				MGPIOC->CRL &=~ (BIT2_MUSK << (pin*4));
				MGPIOC->CRL |= (mode << (pin*4));
			}
			else{
				MGPIOC->CRH &=~ (BIT2_MUSK << ((pin-8)*4));
				MGPIOC->CRH |= (mode << ((pin-8)*4));
			}
			break;
		default:
			break;
	}
}

void MGPIO_voidSetOutputType(PORT_t port,PIN_t pin,OUTPUT_t output_type)
{
	switch (port) {
		case PORTA:
				if(pin < 8){
					MGPIOA->CRL &=~ (BIT2_MUSK << ((pin*4)+2));
					MGPIOA->CRL |= (output_type << ((pin*4)+2));
				}
				else{
					MGPIOA->CRH &=~ (BIT2_MUSK << (((pin-8)*4)+2));
					MGPIOA->CRH |= (output_type << (((pin-8)*4)+2));
				}
			break;
		case PORTB:
			if(pin < 8){
				MGPIOB->CRL &=~ (BIT2_MUSK << ((pin*4)+2));
				MGPIOB->CRL |= (output_type << ((pin*4)+2));
			}
			else{
				MGPIOB->CRH &=~ (BIT2_MUSK << (((pin-8)*4)+2));
				MGPIOB->CRH |= (output_type << (((pin-8)*4)+2));
			}
			break;
		case PORTC:
			if(pin < 8){
				MGPIOC->CRL &=~ (BIT2_MUSK << ((pin*4)+2));
				MGPIOC->CRL |= (output_type << ((pin*4)+2));
			}
			else{
				MGPIOC->CRH &=~ (BIT2_MUSK << (((pin-8)*4)+2));
				MGPIOC->CRH |= (output_type << (((pin-8)*4)+2));
			}
			break;
		default:
			break;
	}
}
void MGPIO_voidSetPinValue(PORT_t port,PIN_t pin,Val_t value)
{
	switch (port) {
		case PORTA:
			MGPIOA->ODR &=~ (1 << pin);
			MGPIOA->ODR |= (value << pin);
			break;
		case PORTB:
			MGPIOB->ODR &=~ (1 << pin);
			MGPIOB->ODR |= (value << pin);
			break;
		case PORTC:
			MGPIOC->ODR &=~ (1 << pin);
			MGPIOC->ODR |= (value << pin);
			break;
		default:
			break;
	}
}
void MGPIO_voidSetAtomicPinValue(PORT_t port,PIN_t pin,Val_t value)
{
	if(value == PIN_LOW)
	{
		switch (port) {
			case PORTA:
				MGPIOA->BSRR |= (value << (pin+16));
				break;
			case PORTB:
				MGPIOB->BSRR |= (value << (pin+16));
				break;
			case PORTC:
				MGPIOC->BSRR |= (value << (pin+16));
				break;
			default:
				break;
		}
	}
	else if(value == PIN_HIGH)
	{
		switch (port) {
			case PORTA:
				MGPIOA->BSRR |= (value << pin);
				break;
			case PORTB:
				MGPIOB->BSRR |= (value << pin);
				break;
			case PORTC:
				MGPIOC->BSRR |= (value << pin);
				break;
			default:
				break;
		}
	}
}

void MGPIO_voidSetInputType(PORT_t port,PIN_t pin,INPUT_t type)
{
	switch (port) {
		case PORTA:
				if(pin < 8){
					MGPIOA->CRL &=~ (BIT2_MUSK << ((pin*4)+2));
					MGPIOA->CRL |= (type << ((pin*4)+2));
				}
				else{
					MGPIOA->CRH &=~ (BIT2_MUSK << (((pin-8)*4)+2));
					MGPIOA->CRH |= (type << (((pin-8)*4)+2));
				}
			break;
		case PORTB:
			if(pin < 8){
				MGPIOB->CRL &=~ (BIT2_MUSK << ((pin*4)+2));
				MGPIOB->CRL |= (type << ((pin*4)+2));
			}
			else{
				MGPIOB->CRH &=~ (BIT2_MUSK << (((pin-8)*4)+2));
				MGPIOB->CRH |= (type << (((pin-8)*4)+2));
			}
			break;
		case PORTC:
			if(pin < 8){
				MGPIOC->CRL &=~ (BIT2_MUSK << ((pin*4)+2));
				MGPIOC->CRL |= (type << ((pin*4)+2));
			}
			else{
				MGPIOC->CRH &=~ (BIT2_MUSK << (((pin-8)*4)+2));
				MGPIOC->CRH |= (type << (((pin-8)*4)+2));
			}
			break;
		default:
			break;
	}
}
void MGPIO_voidSetInputResistance(PORT_t port,PIN_t pin,Resistant_t r_type)
{
	switch (port) {
		case PORTA:
			MGPIOA->ODR &=~ (1 << pin);
			MGPIOA->ODR |= (r_type << pin);
			break;
		case PORTB:
			MGPIOB->ODR &=~ (1 << pin);
			MGPIOB->ODR |= (r_type << pin);
			break;
		case PORTC:
			MGPIOC->ODR &=~ (1 << pin);
			MGPIOC->ODR |= (r_type << pin);
			break;
		default:
			break;
	}
}
u8   MGPIO_u8GetPinValue(PORT_t port,PIN_t pin)
{
		if(port == PORTA)
		{
			return READ_BIT(MGPIOA->IDR,pin);
		}
		else if(port == PORTB)
		{
			return READ_BIT(MGPIOB->IDR,pin);
		}
		else if(port == PORTC)
		{
			return READ_BIT(MGPIOC->IDR,pin);
		}
		else
		{
			return 0;
		}
}

void MGPIO_voidSetAltFuncMode(PORT_t port,PIN_t pin){

	//set pin
	MAFIO->EVCR &=~ (BIT4_MUSK << 0);
	MAFIO->EVCR |= (pin << 0);

	//set port
	MAFIO->EVCR &=~ (BIT3_MUSK << 4);
	MAFIO->EVCR |= (port << 4);

	//Enable alt func
	MAFIO->EVCR |= (1 << 7);
}
