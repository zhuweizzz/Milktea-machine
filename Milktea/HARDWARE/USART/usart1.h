#ifndef __USART1_H
#define __USART1_H

#include "stm32f4xx.h"

#define USART1_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define USART1_GPIO_CLK RCC_AHB1Periph_GPIOA
#define USART1_GPIO_AF GPIO_AF_USART1
#define USART1_GPIO GPIOA
#define USART1_TX_GPIO_Pin GPIO_Pin_9
#define USART1_RX_GPIO_Pin GPIO_Pin_10
#define USART1_TX_GPIO_PinSource GPIO_PinSource9
#define USART1_RX_GPIO_PinSource GPIO_PinSource10

#define USART1_CLK_Cmd RCC_APB2PeriphClockCmd
#define USART1_CLK RCC_APB2Periph_USART1

void Usart1_GPIO_Init(void);

void Usart1_Config(void);

void USART1_NVIC_Config(void);

void Usart1_Initialization(void);

void Usart1_SendByte(uint8_t ch);

void Usart1_SendString(char *str);

void Usart1_SendNumber(int num);

#endif

