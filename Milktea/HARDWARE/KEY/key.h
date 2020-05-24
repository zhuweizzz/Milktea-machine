#ifndef _KEY_H
#define _KEY_H

#include "stm32f4xx.h"
#include "systick.h"

#define KEY_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define KEY_GPIO_CLK RCC_AHB1Periph_GPIOA
#define KEY_GPIO GPIOA
#define KEY_GPIO_Pin GPIO_Pin_15

void KEY_GPIO_Init(void);

void KEY_Initialization(void);

uint8_t KEY_Scan(void);

#endif 

