#include "burdening.h"


void Burd_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	BURD_GPIO_CLK_Cmd(BURD_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = BURD_GPIO_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(BURD_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(BURD_GPIO, BURD_GPIO_Pin);	
}

void Burd_Initialization(void)
{
	Burd_GPIO_Init();
}

void Burd_OUT(void)
{
	GPIO_ResetBits(BURD_GPIO, BURD_GPIO_Pin);
	Delay_Ms(8000);
	GPIO_SetBits(BURD_GPIO, BURD_GPIO_Pin);
	Delay_Ms(8000);
}


