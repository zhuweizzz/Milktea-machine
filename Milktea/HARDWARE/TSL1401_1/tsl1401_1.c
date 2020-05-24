#include "tsl1401_1.h"

void TSL1401_1_SI_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	TSL1401_1_SI_GPIO_CLK_Cmd(TSL1401_1_SI_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = TSL1401_1_SI_GPIO_Pin;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(TSL1401_1_SI_GPIO, &GPIO_InitStructure);
}

void TSL1401_1_CLK_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	TSL1401_1_CLK_GPIO_CLK_Cmd(TSL1401_1_CLK_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = TSL1401_1_CLK_GPIO_Pin;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(TSL1401_1_CLK_GPIO, &GPIO_InitStructure);
}

void TSL1401_1_AO_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	TSL1401_1_AO_GPIO_CLK_Cmd(TSL1401_1_AO_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = TSL1401_1_AO_GPIO_Pin;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(TSL1401_1_AO_GPIO, &GPIO_InitStructure);
}

void TSL1401_1_AO_ADC_Config(void)
{
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	TSL1401_1_ADC_CLK_Cmd(TSL1401_1_ADC_CLK, ENABLE);
	
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStructure.ADC_ExternalTrigConvEdge =ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_NbrOfConversion = 1; 
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_8b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	
	ADC_Init(TSL1401_1_ADC_, &ADC_InitStructure);
		
	ADC_Cmd(TSL1401_1_ADC_, ENABLE);
}

void TSL1401_1_AO_Init(void)
{
	TSL1401_1_AO_GPIO_Init();
	
	TSL1401_1_AO_ADC_Config();
}

uint16_t TSL1401_1_AO_ADC_Measure(void)
{
	uint16_t AO_ADC_ConvertedValue = 0;
	
	ADC_RegularChannelConfig(TSL1401_1_ADC_, TSL1401_1_ADC_Channel, 1, ADC_SampleTime_56Cycles);
	
	ADC_ClearFlag(TSL1401_1_ADC_, ADC_FLAG_EOC);
	
	ADC_SoftwareStartConv(TSL1401_1_ADC_);
	
	while(!ADC_GetFlagStatus(TSL1401_1_ADC_, ADC_FLAG_EOC));
	
	AO_ADC_ConvertedValue = ADC_GetConversionValue(TSL1401_1_ADC_);	
		
	return AO_ADC_ConvertedValue;
}

void TSL1401_1_Initiazation(void)
{
	TSL1401_1_SI_GPIO_Init();
	
	TSL1401_1_CLK_GPIO_Init();
	
	TSL1401_1_AO_Init();
}

int TSL1401_1_ExposureTime = 20;

void TSL1401_1_GetData(uint16_t *data)
{
	uint8_t i = 0;
	TSL1401_1_SI_H();
	TSL1401_1_CLK_H();
	TSL1401_1_SI_L();
	TSL1401_1_CLK_L();
	for (i = 0; i < 128; i++)
	{
		TSL1401_1_CLK_H();
		TSL1401_1_CLK_L();
	}
	Delay_Us(TSL1401_1_ExposureTime);
	TSL1401_1_SI_H();
	TSL1401_1_CLK_H();
	TSL1401_1_SI_L();
	Delay_Us(1);
	*data = TSL1401_1_AO_ADC_Measure();
	TSL1401_1_CLK_L();
	for (i = 1; i < 128; i++)
	{
		TSL1401_1_CLK_H();
		Delay_Us(1);
		*(data + i) = TSL1401_1_AO_ADC_Measure();
		TSL1401_1_CLK_L();
	}
	TSL1401_1_CLK_H();
	TSL1401_1_CLK_L();
	TSL1401_1_AdjustExposure(data);
}

void TSL1401_1_AdjustExposure(uint16_t *data)
{
	uint8_t i = 0;
	uint32_t sum = 0;
	uint16_t average = 0;
	
	for (i = 0; i < 128; i++)
	{
		sum += *(data + i);
	}
	average = sum / 128;
	TSL1401_1_ExposureTime += (50 * (150 - average));
}
