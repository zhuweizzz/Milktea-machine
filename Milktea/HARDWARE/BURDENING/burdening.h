#ifndef _BURDENING_H
#define _BURDENING_H

#include "stm32f4xx.h"
#include "systick.h"


#define BURD_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define BURD_GPIO_CLK RCC_AHB1Periph_GPIOD
#define BURD_GPIO GPIOD
#define BURD_GPIO_Pin GPIO_Pin_10

void Burd_GPIO_Init(void);

void Burd_Initialization(void);

void Burd_OUT(void);



#endif

