/*
 * MGPIO_interface.h
 *
 *  Created on: Aug 3, 2025
 *      Author: elwady
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

typedef enum
{
	PORTA,
	PORTB,
	PORTC
}PORT_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;

typedef enum
{
	INPUT,
	OUTPUT_10MHz,
	OUTPUT_2MHz,
	OUTPUT_50MHz
}MODE_t;

typedef enum
{
	GP_Pushpull,
	GP_Opendrain,
	AF_Pushpull,
	AF_Opendrain
}OUTPUT_t;

typedef enum
{
	Analog,
	Floating,
	Input_up_down
}INPUT_t;

typedef enum
{
	PIN_LOW,
	PIN_HIGH
}Val_t;

typedef enum
{
	Pull_Down,
	Pull_Up
}Resistant_t;

void MGPIO_voidSetMode(PORT_t port,PIN_t pin,MODE_t mode);

//___________________OUTPUT FUNC_____________________________________
void MGPIO_voidSetOutputType(PORT_t port,PIN_t pin,OUTPUT_t output_type);
void MGPIO_voidSetPinValue(PORT_t port,PIN_t pin,Val_t value);
void MGPIO_voidSetAtomicPinValue(PORT_t port,PIN_t pin,Val_t value);

//___________________INPUT FUNC______________________________________
void MGPIO_voidSetInputType(PORT_t port,PIN_t pin,INPUT_t type);
void MGPIO_voidSetInputResistance(PORT_t port,PIN_t pin,Resistant_t r_type);
u8   MGPIO_u8GetPinValue(PORT_t port,PIN_t pin);

void MGPIO_voidSetAltFuncMode(PORT_t port,PIN_t pin);

#define BIT2_MUSK	3
#define BIT3_MUSK	7
#define BIT4_MUSK	15

#endif /* MGPIO_INTERFACE_H_ */
