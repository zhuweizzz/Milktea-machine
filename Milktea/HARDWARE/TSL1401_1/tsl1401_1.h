#ifndef __TSL1401_1_H
#define __TSL1401_1_H

#include "stm32f4xx.h"
#include "systick.h"

#define TSL1401_1_SI_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define TSL1401_1_SI_GPIO_CLK RCC_AHB1Periph_GPIOA
#define TSL1401_1_SI_GPIO GPIOA
#define TSL1401_1_SI_GPIO_Pin GPIO_Pin_6

#define TSL1401_1_CLK_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define TSL1401_1_CLK_GPIO_CLK RCC_AHB1Periph_GPIOA
#define TSL1401_1_CLK_GPIO GPIOA
#define TSL1401_1_CLK_GPIO_Pin GPIO_Pin_7

#define TSL1401_1_AO_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define TSL1401_1_AO_GPIO_CLK RCC_AHB1Periph_GPIOB
#define TSL1401_1_AO_GPIO GPIOB
#define TSL1401_1_AO_GPIO_Pin GPIO_Pin_0

#define TSL1401_1_ADC_CLK_Cmd RCC_APB2PeriphClockCmd
#define TSL1401_1_ADC_CLK RCC_APB2Periph_ADC1
#define TSL1401_1_ADC_ ADC1
#define TSL1401_1_ADC_Channel ADC_Channel_8

#define TSL1401_1_SI_H() GPIO_SetBits(TSL1401_1_SI_GPIO, TSL1401_1_SI_GPIO_Pin)
#define TSL1401_1_SI_L() GPIO_ResetBits(TSL1401_1_SI_GPIO, TSL1401_1_SI_GPIO_Pin)

#define TSL1401_1_CLK_H() GPIO_SetBits(TSL1401_1_CLK_GPIO, TSL1401_1_CLK_GPIO_Pin)
#define TSL1401_1_CLK_L() GPIO_ResetBits(TSL1401_1_CLK_GPIO, TSL1401_1_CLK_GPIO_Pin)

void TSL1401_1_SI_GPIO_Init(void);

void TSL1401_1_CLK_GPIO_Init(void);

void TSL1401_1_AO_GPIO_Init(void);

void TSL1401_1_AO_ADC_Config(void);

void TSL1401_1_AO_Init(void);

uint16_t TSL1401_1_AO_ADC_Measure(void);

void TSL1401_1_Initiazation(void);

void TSL1401_1_GetData(uint16_t *data);

void TSL1401_1_AdjustExposure(uint16_t *data);

#endif
