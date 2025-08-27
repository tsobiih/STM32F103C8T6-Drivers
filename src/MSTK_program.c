#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "MSTK_config.h"
#include "MSTK_interface.h"
#include "MSTK_private.h"

void MSTK_voidInit(void)
{
	//specify clock source AHB/8 (1 tick = 1us)
	STK->CTRL &=~ (1 << CLKSOURCE);
}
void MSTK_voidDelay_us(u32 value){
	STK->LOAD = value-1;

	STK->VAL = 0;

	STK->CTRL |= (1 << ENABLE);

	while(!READ_BIT(STK->CTRL,COUNTFLAG));

	STK->CTRL &=~ (1 << ENABLE);
}
void MSTK_voidDelay_ms(u16 value)
{
	//max delay 16777.215 ms
	STK->LOAD = (value*1000) - 1;

	STK->VAL = 0;

	STK->CTRL |= (1 << ENABLE);

	while(!READ_BIT(STK->CTRL,COUNTFLAG));

	STK->CTRL &=~ (1 << ENABLE);
}
u32  MSTK_u32GetElapsedTime(void)
{
	u32 time = STK->LOAD - STK->VAL;
	return time;
}

void MSTK_voidEnableSystickINT(void)
{
	STK->CTRL |= (1 << TICKINT);
}

void MSTK_voidDisableSystickINT(void)
{
	STK->CTRL &=~ (1 << TICKINT);
}

