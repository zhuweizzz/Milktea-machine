#include "usart3.h"

void Usart3_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	USART3_GPIO_CLK_Cmd(USART3_GPIO_CLK, ENABLE);
	
	GPIO_PinAFConfig(USART3_GPIO, USART3_TX_GPIO_PinSource, USART3_GPIO_AF);
	GPIO_PinAFConfig(USART3_GPIO, USART3_RX_GPIO_PinSource, USART3_GPIO_AF);
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_Pin = USART3_TX_GPIO_Pin | USART3_RX_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	
	GPIO_Init(USART3_GPIO, &GPIO_InitStructure);	
	
}

void Usart3_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	USART3_CLK_Cmd(USART3_CLK, ENABLE);
	
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART3, &USART_InitStructure);
	
	USART_Cmd(USART3, ENABLE);
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
}


void Usart3_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
}

void Usart3_Initialization(void)
{
	Usart3_GPIO_Init();
	
	Usart3_Config();
	
	Usart3_NVIC_Config();
}



void Usart3_SendByte(uint8_t ch)
{
	USART_SendData(USART3, ch);
	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
}

void Usart3_SendDataFlow(uint8_t *dataFlow, uint16_t len)
{
	uint16_t i;
	for (i = 0; i < len; i++)
	{
		Usart3_SendByte(*(dataFlow + i));
	}
}

uint8_t Usart3_data = 0x00;
extern uint8_t GY33_flag;

void USART3_IRQHandler(void)
{
	if (USART_GetITStatus(USART3, USART_IT_RXNE) == SET)
	{
		GY33_flag++;
		if (GY33_flag == 9)
			Usart3_data = USART_ReceiveData(USART3);
		else if (GY33_flag == 10)
			Usart3_data = (Usart3_data << 8) | USART_ReceiveData(USART3);
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	}
}
