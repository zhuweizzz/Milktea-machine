#include "motor.h"

//传送带电机控制程序	GPIOD pin1  pin2  pin3

float Loc_Now;

void MOTOR_Init(void)
{
	SysTick_Initialization();
	GPIO_InitTypeDef GPIO_InitStructure;
	
	MOTOR_GPIO_CLK_Cmd(MOTOR_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStructure.GPIO_Pin = MOTOR_PUL_GPIO_Pin;
	GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = MOTOR_DIR_GPIO_Pin;	
	GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = MOTOR_ERC_GPIO_Pin;
	GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
	GPIO_SetBits(MOTOR_GPIO, MOTOR_ERC_GPIO_Pin|MOTOR_PUL_GPIO_Pin|MOTOR_DIR_GPIO_Pin);
	
	Loc_Now=0;
	
}

/*****函数******/
/*
参数: 
1.传送带滚轮半径Rgun（单位：cm

2.需要运动的距离L（单位：cm）

总脉冲：2000L/pi*Rgun
*/
unsigned int divice=1;
void ConfigPul(int PulNum)
{	
		while(PulNum>0)
		{
			GPIO_SetBits(MOTOR_GPIO,MOTOR_PUL_GPIO_Pin);
			Delay_Us(25*divice);
			GPIO_ResetBits(MOTOR_GPIO,MOTOR_PUL_GPIO_Pin);
			Delay_Us(25*divice);
			PulNum--;
		}
}


int calculat_Pul(float L)
{
	float temp;
	
	temp=(L*20000.0)/pig;
	
	temp=(int)temp;
	
	return temp;
	
}

void Motor_Go_forward(float L)
{
	divice=4;
	GPIO_SetBits(MOTOR_GPIO, MOTOR_DIR_GPIO_Pin);
	ConfigPul(calculat_Pul(L));
	
}

void Motor_Go_back(float L)
{
	divice=1;
	GPIO_ResetBits(MOTOR_GPIO, MOTOR_DIR_GPIO_Pin);
	ConfigPul(calculat_Pul(L));
}

void Motor_Moveto(float Location)
{
	if(Location>Loc_Now)
	{
		Motor_Go_forward(Location-Loc_Now);
	}
	else if(Location<Loc_Now)
	{
		Motor_Go_back(Loc_Now-Location);
	}
	
	Loc_Now=Location;
}


