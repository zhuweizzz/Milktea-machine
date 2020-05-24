#include "led.h"

void LED_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	LED_GPIO_CLK_Cmd(LED_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED_GPIO_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(LED_GPIO, LED_GPIO_Pin);	
}

void LED_Initialization(void)
{
	LED_GPIO_Init();
}

void LED_On(void)
{
	GPIO_SetBits(LED_GPIO, LED_GPIO_Pin);
}

void LED_Off(void)
{
	GPIO_ResetBits(LED_GPIO, LED_GPIO_Pin);
}
