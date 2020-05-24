#ifndef __USART2_H
#define __USART2_H

#include "stm32f4xx.h"

#define USART2_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define USART2_GPIO_CLK RCC_AHB1Periph_GPIOD
#define USART2_GPIO_AF GPIO_AF_USART2
#define USART2_GPIO GPIOD
#define USART2_TX_GPIO_Pin GPIO_Pin_5
#define USART2_RX_GPIO_Pin GPIO_Pin_6
#define USART2_TX_GPIO_PinSource GPIO_PinSource5
#define USART2_RX_GPIO_PinSource GPIO_PinSource6

#define USART2_CLK_Cmd RCC_APB1PeriphClockCmd
#define USART2_CLK RCC_APB1Periph_USART2

void Usart2_GPIO_Init(void);

void Usart2_Config(void);

void Usart2_Initialization(void);

void Usart2_SendByte(uint8_t ch);

void Usart2_SendDataFlow(uint8_t *dataFlow, uint16_t len);

#endif

