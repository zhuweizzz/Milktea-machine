#include "fenzhuang.h"
#include "peifang.h"


static unsigned int FenZhuang_NowValue=0;

void FenZhuang_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	FenZhuang_GPIO_CLK_Cmd(FenZhuang_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = BUTTEN_ALL_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(FenZhuang_GPIO,&GPIO_InitStructure);
	
	GPIO_SetBits(FenZhuang_GPIO,BUTTEN_ALL_Pin);


	FenZhuang_NowValue=0;
	
}

void tGPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	tFenZhuang_GPIO_CLK_Cmd(tFenZhuang_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = t1_Pin|t2_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(tFenZhuang_GPIO,&GPIO_InitStructure);
	
	GPIO_ResetBits(tFenZhuang_GPIO,t1_Pin|t2_Pin);
	
}

void FenZhuang_Initianization(void)
{
	FenZhuang_Init();
	tGPIO_Init();
}

void FenZhuang_Push_Butten(unsigned int butten)
{
	switch(butten)
	{
		case BUTTEN_Addvalue:   GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Addvalue_Pin); 		break;
		case BUTTEN_Resetvalue: GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Resetvalue_Pin); 	break;
		case BUTTEN_Subtract: 	GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Subtract_Pin); 		break;
		case BUTTEN_Fast: 			GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Fast_Pin); 				break;
		case BUTTEN_Medium :		GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Medium_Pin);				break;
		case BUTTEN_Slow :			GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Slow_Pin);					break;
		case BUTTEN_Start :			GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Start_Pin); Delay_Ms(700);			break;
		case BUTTEN_Output :		GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Output_Pin);	Delay_Ms(2000);	break;
		case BUTTEN_Stop :			GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Stop_Pin);					break;
		default: break;
	}
	Delay_Ms(50);
	GPIO_SetBits(FenZhuang_GPIO,BUTTEN_ALL_Pin);
}


void FenZhuang_SetValue(unsigned int value)
{
	if(value<FenZhuang_NowValue)
	{
		while(value<FenZhuang_NowValue)
		{
			FenZhuang_Push_Butten(BUTTEN_Subtract);
			FenZhuang_NowValue--;
			Delay_Ms(50);
		}
			FenZhuang_Push_Butten(BUTTEN_Subtract);
			Delay_Ms(50);
	}
	else if(value>FenZhuang_NowValue)
	{
		while(value>FenZhuang_NowValue)
		{
			FenZhuang_NowValue++;
			FenZhuang_Push_Butten(BUTTEN_Addvalue);
			Delay_Ms(50);
		}
		FenZhuang_Push_Butten(BUTTEN_Addvalue);
		Delay_Ms(50);
	}
}

void FenZhuang_Output(unsigned int weight)
{
//	FenZhuang_Push_Butten(BUTTEN_Start);
//	Delay_Ms(3000); 
//	
//	Delay_Ms(weight*20);
//	
//	FenZhuang_Push_Butten(BUTTEN_Stop);
//	Delay_Ms(1000);
//	
//	FenZhuang_Push_Butten(BUTTEN_Output);
//	Delay_Ms(500);
	
	//Õð¶¯
	if(weight!=Milk1_value)
	{
		GPIO_ResetBits(FenZhuang_GPIO,BUTTEN_Start_Pin);
		Delay_Ms(4500);
		GPIO_SetBits(FenZhuang_GPIO,BUTTEN_Start_Pin);
		Delay_Ms(1000);
	}
	
	//³öÁÏ
	GPIO_SetBits(tFenZhuang_GPIO,t1_Pin);
	Delay_Ms(1000);
	GPIO_ResetBits(tFenZhuang_GPIO,t1_Pin);
	Delay_Ms(2000);
	
	GPIO_SetBits(tFenZhuang_GPIO,t2_Pin);
	Delay_Ms(1000);
	GPIO_ResetBits(tFenZhuang_GPIO,t2_Pin);
	
}


  void FenZhuang_addMilk(unsigned int weight)
{
	FenZhuang_Output(weight);
//	Delay_Ms(1000);
//	FenZhuang_SetValue(weight);
//	Delay_Ms(1000);
//	FenZhuang_Output(weight);
}

