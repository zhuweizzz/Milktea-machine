#include "blender.h"
#include "systick.h"

void Blender_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	Blender_GPIO_CLK_Cmd(Blender_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = Key1_Pin|Key2_Pin;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Blender_Key_GPIO,&GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin=Key_power_Pin;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(Blender_Key_GPIO,&GPIO_InitStructure);
	
	GPIO_ResetBits(Blender_Key_GPIO,Key1_Pin | Key2_Pin);
	
	GPIO_SetBits(Blender_Key_GPIO,Key_power_Pin);
	
}




void Blender_Init()
{
	Blender_GPIO_Init();
}


void Blender_Motor_Up()
{
	GPIO_SetBits(Blender_Key_GPIO,Key1_Pin);
	Delay_Ms(3100);
	GPIO_ResetBits(Blender_Key_GPIO,Key1_Pin);
}


void Blender_Motor_Down()
{
	GPIO_SetBits(Blender_Key_GPIO,Key2_Pin);
	Delay_Ms(3100);
	GPIO_ResetBits(Blender_Key_GPIO,Key2_Pin);
}

//void Blender_Power()
//{
//	GPIO_ResetBits(Blender_Key_GPIO,Key_power_Pin);
//	Delay_Ms(Mix_Time);
//	GPIO_SetBits(Blender_Key_GPIO,Key_power_Pin);
//}

void Blender_Mix()
{
	GPIO_ResetBits(Blender_Key_GPIO,Key_power_Pin);
	Blender_Motor_Down();
	Delay_Ms(Mix_Time);
	GPIO_SetBits(Blender_Key_GPIO,Key_power_Pin);
	Blender_Motor_Up();
}







