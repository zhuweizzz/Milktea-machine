#include "systick.h"

static uint8_t fac_us = 0;
static uint32_t fac_ms = 0;

void SysTick_Initialization(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us = SystemCoreClock / 1000000;
	fac_ms = (uint32_t)fac_us * 1000;
}

void Delay_Us(uint32_t nUs)
{
	uint32_t temp;
	SysTick->LOAD = nUs * fac_us;
	SysTick->VAL = 0x00;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	do
	{
		temp = SysTick->CTRL;
	}while((temp&0x01) && !(temp&1<<16));
	SysTick->CTRL = ~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL = 0x00;
}

void Delay_Ms(uint32_t nMs)
{
	uint32_t temp;
	if (nMs < 99)
	{
		SysTick->LOAD = nMs * fac_ms;
		SysTick->VAL = 0x00;
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
		do
		{
			temp = SysTick->CTRL;
		}while((temp&0x01) && !(temp&1<<16));
		SysTick->CTRL = ~SysTick_CTRL_ENABLE_Msk;
		SysTick->VAL = 0x00;
	}
	else
	{
		uint32_t i = 0;
		for (i = 0; i < nMs; i++)
		{
			SysTick->LOAD = fac_ms;
			SysTick->VAL = 0x00;
			SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
			do
			{
				temp = SysTick->CTRL;
			}while((temp&0x01) && !(temp&1<<16));
			SysTick->CTRL = ~SysTick_CTRL_ENABLE_Msk;
			SysTick->VAL = 0x00;
		}
	}
}
