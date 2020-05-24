#ifndef __LED_H
#define __LED_H

#define LED_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define LED_GPIO_CLK RCC_AHB1Periph_GPIOA
#define LED_GPIO GPIOA
#define LED_GPIO_Pin GPIO_Pin_9

#include "stm32f4xx.h"

void LED_GPIO_Init(void);

void LED_Initialization(void);

void LED_On(void);

void LED_Off(void);

#endif

