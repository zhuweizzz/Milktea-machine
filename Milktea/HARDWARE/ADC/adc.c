#include "adc.h"

void ADC_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	ADC_GPIO_CLK_Cmd(ADC_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = ADC_GPIO_Pin;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(ADC_GPIO, &GPIO_InitStructure);
}

void ADC_Config(void)
{
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	ADC_CLK_Cmd(ADC_CLK, ENABLE);
	
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_20Cycles;
	
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStructure.ADC_ExternalTrigConvEdge =ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_NbrOfConversion = 1; 
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	
	ADC_Init(ADC_, &ADC_InitStructure);
	
	ADC_RegularChannelConfig(ADC_, ADC_Channel, 1, ADC_SampleTime_56Cycles);
	
	ADC_ITConfig(ADC_, ADC_IT_EOC, ENABLE);
	
	ADC_Cmd(ADC_, ENABLE);
	
	ADC_SoftwareStartConv(ADC_);
}

static void ADC_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
}

void ADC_Initialization(void)
{	
	ADC_GPIO_Init();
	
	ADC_Config();
	
	ADC_NVIC_Config();
}

float ADC_ConvertedValue = 1;

void ADC_IRQHandler(void)
{
	if (ADC_GetFlagStatus(ADC_, ADC_FLAG_EOC) == SET)
		ADC_ConvertedValue = ADC_GetConversionValue(ADC_);
	ADC_ClearITPendingBit(ADC_, ADC_FLAG_EOC);
}
