#include "stm32f4xx.h"
#include "key.h"

void KEY_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	KEY_GPIO_CLK_Cmd(KEY_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = KEY_GPIO_Pin;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_GPIO, &GPIO_InitStructure);
}

void KEY_Initialization(void)
{
	KEY_GPIO_Init();
}

uint8_t KEY_Scan(void)
{
	static uint8_t key_down = 0;
	if (GPIO_ReadInputDataBit(KEY_GPIO, KEY_GPIO_Pin) == 0 && key_down == 0)
	{
		Delay_Ms(10);
		if (GPIO_ReadInputDataBit(KEY_GPIO, KEY_GPIO_Pin) == 0)
		{
			key_down = 1;
			return 1;
		}
	}
	else if(GPIO_ReadInputDataBit(KEY_GPIO, KEY_GPIO_Pin) == 1)
	{
		key_down = 0;
		return 0;
	}
	return 0;
}

