#include "lcdsupplement.h"

uint16_t LCD_GPIO_Pin[11] = {GPIO_Pin_0, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3, GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_8, GPIO_Pin_9, GPIO_Pin_10};

void LCD_Initialization(void)
{
	uint8_t i = 0;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	LCD_GPIO_CLK_Cmd(LCD_GPIO_CLK, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	for (i = 0; i < 11; i++)
	{
		GPIO_InitStructure.GPIO_Pin = LCD_GPIO_Pin[i];	
		GPIO_Init(LCD_GPIO, &GPIO_InitStructure);
	}
}

void LCD_WriteData(uint8_t data)
{
	uint8_t i = 0;
	for (i = 0; i < 8; i++)
	{
		if (data >> i)
		{
			GPIO_SetBits(LCD_GPIO, LCD_GPIO_Pin[i]);	
		}
		else
		{
			GPIO_ResetBits(LCD_GPIO, LCD_GPIO_Pin[i]);	
		}
	}
}
