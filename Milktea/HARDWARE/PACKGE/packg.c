#include "packg.h"
#include "systick.h"

void PACK_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	PACKG_GPIO_CLK_Cmd(PACKG_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = PACKG_PUSH_Pin1|PACKG_PUSH_Pin2;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PACKG_GPIO,&GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin=PACKG_MOTOR_EN_Pin | PACKG_MOTOR_STEP_Pin | PACKG_MOTOR_DIR_Pin;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(PACKG_GPIO,&GPIO_InitStructure);

}



void Packge_Init()
{
	PACK_GPIO_Init();
}


void Packge_Push_Up()
{
	GPIO_SetBits(PACKG_GPIO,PACKG_PUSH_Pin1);
	Delay_Ms(4190);
	GPIO_ResetBits(PACKG_GPIO,PACKG_PUSH_Pin1);
}

void Packge_Push_Down()
{
	GPIO_SetBits(PACKG_GPIO,PACKG_PUSH_Pin2);
	Delay_Ms(4190);
	GPIO_ResetBits(PACKG_GPIO,PACKG_PUSH_Pin2);
}



 void StepMotor_Enable(void)
{
	GPIO_ResetBits(PACKG_GPIO, PACKG_MOTOR_EN_Pin);
}


void StepMotor_Disable(void)
{
	GPIO_SetBits(PACKG_GPIO, PACKG_MOTOR_EN_Pin);
}

void StepMotor_Turn(int cycle)
{	
	uint16_t i = 0, j = 0;
	if (cycle > 0)
	{
		GPIO_SetBits(PACKG_GPIO, PACKG_MOTOR_DIR_Pin);
	}
	else
	{
		GPIO_ResetBits(PACKG_GPIO, PACKG_MOTOR_DIR_Pin);
		cycle = -cycle;
	}
	for (i = 0; i < cycle; i++)
	{
		for (j = 0; j < 20; j++)
		{
			GPIO_SetBits(PACKG_GPIO, PACKG_MOTOR_STEP_Pin);
			Delay_Ms(5);
			GPIO_ResetBits(PACKG_GPIO, PACKG_MOTOR_STEP_Pin);
			Delay_Ms(5);
		}
	}
}


void Packge_Seal(void)
{
	Packge_Push_Up();
	Delay_Ms(8000);
	Packge_Push_Down();
	
	StepMotor_Enable();
	StepMotor_Turn(60);
	StepMotor_Disable();
}



