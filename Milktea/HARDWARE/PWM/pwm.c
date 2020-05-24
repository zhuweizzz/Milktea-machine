#include "pwm.h"

void PWM_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	PWM_GPIO_CLK_Cmd(PWM_GPIO_CLK, ENABLE);
	
	GPIO_PinAFConfig(PWM_GPIO, PWM_GPIOSource, PWM_GPIO_AF);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = PWM_GPIO_Pin;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(PWM_GPIO, &GPIO_InitStructure);	
}

void PWM_TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	PWM_TIM_CLK_Cmd(PWM_TIM_CLK, ENABLE);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 99;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 83;
	
	TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 50;
	
	TIM_OC1Init(PWM_TIM, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(PWM_TIM, ENABLE);
	
	TIM_Cmd(PWM_TIM, ENABLE);	
	
	TIM_CtrlPWMOutputs(PWM_TIM, ENABLE);
}

void PWM_Initialization(void)
{
	PWM_GPIO_Init();
	PWM_TIM_Init();
}

void PWM_SetScale(uint16_t scale)
{
	TIM_SetCompare1(PWM_TIM, scale);
}

