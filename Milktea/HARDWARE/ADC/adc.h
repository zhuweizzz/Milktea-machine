#ifndef __ADC_H
#define __ADC_H

#include "stm32f4xx.h"

#define ADC_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define ADC_GPIO_CLK RCC_AHB1Periph_GPIOB
#define ADC_GPIO GPIOB
#define ADC_GPIO_Pin GPIO_Pin_0

#define ADC_CLK_Cmd RCC_APB2PeriphClockCmd
#define ADC_CLK RCC_APB2Periph_ADC1
#define ADC_ ADC1
#define ADC_Channel ADC_Channel_8

void ADC_GPIO_Init(void);

void ADC_Config(void);

void ADC_NVIC_Config(void);

void ADC_Initialization(void);

void ADC_IRQHandler(void);

#endif

