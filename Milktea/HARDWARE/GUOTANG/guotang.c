#include "guotang.h"


void GTANG_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	BUTTEN_GPIO_CLK_Cmd(BUTTEN_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = BUTTENALL_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(BUTTEN_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(BUTTEN_GPIO, BUTTENALL_Pin);	
}

void GTANG_PUSH_Butten(unsigned char butten)
{
	switch (butten)
	{
		case 0:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN11_Pin);	break;
		case 1:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN12_Pin); 	break;
		case 2: GPIO_ResetBits(BUTTEN_GPIO, BUTTEN13_Pin); 	break;
		case 3:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN14_Pin);  break;
		case 4:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN21_Pin);  break;
		case 5:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN22_Pin);  break;
		case 6:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN23_Pin);  break;
		case 7:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN24_Pin);	break;
		case 8:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN31_Pin);	break;
		case 9:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN32_Pin);	break;
		case 10:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN33_Pin);	break;
		case 11:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN34_Pin);  break;
		case 12:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN41_Pin);	break;
		case 13:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN42_Pin);	break;
		case 14:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN43_Pin);	break;
		case 15:	GPIO_ResetBits(BUTTEN_GPIO, BUTTEN44_Pin);	break;		
	}
	Delay_Ms(500);
	GPIO_SetBits(BUTTEN_GPIO,BUTTENALL_Pin);
}

void GTANG_Add_Suger(unsigned char value) //(0-15) 16ÖÖÌð¶È
{
	GTANG_PUSH_Butten(value);
	Delay_Ms(500*value);
}

