#ifndef __PWM_H
#define __PWM_H

#include "stm32f4xx.h"

#define PWM_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define PWM_GPIO      	GPIOA
#define PWM_GPIO_Pin  	GPIO_Pin_5
#define PWM_GPIOSource 	GPIO_PinSource5
#define PWM_GPIO_AF 			GPIO_AF_TIM2

#define PWM_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM_TIM_CLK 		RCC_APB1Periph_TIM2
#define PWM_TIM 				TIM2

void PWM_GPIO_Init(void);

void PWM_TIM_Init(void);

void PWM_Initialization(void);

void PWM_SetScale(uint16_t scale);

#endif


