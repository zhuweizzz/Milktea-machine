#ifndef _TEA_H
#define _TEA_H

#define TEA_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define TEA_GPIO_CLK RCC_AHB1Periph_GPIOD
#define TEA_GPIO GPIOD
#define TEA_GPIO_Pin GPIO_Pin_9

#include "stm32f4xx.h"
#include "systick.h"


void TEA_GPIO_Init(void);

void TEA_Initialization(void);

void TEA_OUT(void);













#endif

