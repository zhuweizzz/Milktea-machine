#ifndef _GUOTANG_H
#define _GUOTANG_H

#include "stm32f4xx.h"
#include "systick.h"

//extern unsigned char butten[4][4];

#define BUTTEN_GPIO GPIOF
#define BUTTEN_GPIO_CLK RCC_AHB1Periph_GPIOF
#define BUTTEN_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd

#define BUTTENALL_Pin GPIO_Pin_All
#define BUTTEN11_Pin GPIO_Pin_0
#define BUTTEN21_Pin GPIO_Pin_1
#define BUTTEN31_Pin GPIO_Pin_2
#define BUTTEN41_Pin GPIO_Pin_3
#define BUTTEN12_Pin GPIO_Pin_4
#define BUTTEN22_Pin GPIO_Pin_5
#define BUTTEN32_Pin GPIO_Pin_6
#define BUTTEN42_Pin GPIO_Pin_7
#define BUTTEN13_Pin GPIO_Pin_8
#define BUTTEN23_Pin GPIO_Pin_9
#define BUTTEN33_Pin GPIO_Pin_10
#define BUTTEN43_Pin GPIO_Pin_11
#define BUTTEN14_Pin GPIO_Pin_12
#define BUTTEN24_Pin GPIO_Pin_13
#define BUTTEN34_Pin GPIO_Pin_14
#define BUTTEN44_Pin GPIO_Pin_15



void GTANG_PUSH_Butten(unsigned char butten);
void GTANG_Init(void);

void GTANG_Add_Suger(unsigned char value);

#endif
