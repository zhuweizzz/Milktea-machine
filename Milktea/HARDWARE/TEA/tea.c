#include "tea.h"


void TEA_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	TEA_GPIO_CLK_Cmd(TEA_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = TEA_GPIO_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(TEA_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(TEA_GPIO, TEA_GPIO_Pin);	
}

void TEA_Initialization(void)
{
	TEA_GPIO_Init();
}

void TEA_OUT(void)
{
	GPIO_ResetBits(TEA_GPIO, TEA_GPIO_Pin);
	Delay_Ms(20000);
	GPIO_SetBits(TEA_GPIO, TEA_GPIO_Pin);
}

