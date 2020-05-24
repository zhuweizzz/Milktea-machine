#ifndef __USART3_H
#define __USART3_H

#include "stm32f4xx.h"
#include "stdio.h"

#define USART3_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define USART3_GPIO_CLK RCC_AHB1Periph_GPIOD
#define USART3_GPIO_AF GPIO_AF_USART3
#define USART3_GPIO GPIOD
#define USART3_TX_GPIO_Pin GPIO_Pin_8
#define USART3_RX_GPIO_Pin GPIO_Pin_9
#define USART3_TX_GPIO_PinSource GPIO_PinSource8
#define USART3_RX_GPIO_PinSource GPIO_PinSource9

#define USART3_CLK_Cmd RCC_APB1PeriphClockCmd
#define USART3_CLK RCC_APB1Periph_USART3

void Usart3_GPIO_Init(void);

void Usart3_Config(void);

void Usart3_Initialization(void);

void Usart3_SendByte(uint8_t ch);

void Usart3_SendDataFlow(uint8_t *dataFlow, uint16_t len);

#endif

