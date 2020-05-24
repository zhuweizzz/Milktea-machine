#include "usart2.h"
#include "usart1.h"

void Usart2_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	USART2_GPIO_CLK_Cmd(USART2_GPIO_CLK, ENABLE);
	
	GPIO_PinAFConfig(USART2_GPIO, USART2_TX_GPIO_PinSource, USART2_GPIO_AF);
	GPIO_PinAFConfig(USART2_GPIO, USART2_RX_GPIO_PinSource, USART2_GPIO_AF);
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_Pin = USART2_TX_GPIO_Pin | USART2_RX_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	
	GPIO_Init(USART2_GPIO, &GPIO_InitStructure);	
	
}

void Usart2_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	USART2_CLK_Cmd(USART2_CLK, ENABLE);
	
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART2, &USART_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
}


void Usart2_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
}

void Usart2_Initialization(void)
{
	Usart2_GPIO_Init();
	
	Usart2_Config();
	
	Usart2_NVIC_Config();
}

void Usart2_SendByte(uint8_t ch)
{
	USART_SendData(USART2, ch);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

void Usart2_SendDataFlow(uint8_t *dataFlow, uint16_t len)
{
	uint16_t i;
	for (i = 0; i < len; i++)
	{
		Usart2_SendByte(*(dataFlow + i));
	}
}

uint8_t usart2_data[256] = {0};
uint16_t usart2_dataLen = 0;

void USART2_IRQHandler(void)
{
	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
	{
		usart2_data[usart2_dataLen] = USART_ReceiveData(USART2);
		usart2_dataLen++;
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	}
}
