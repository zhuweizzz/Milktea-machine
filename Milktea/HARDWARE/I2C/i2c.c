#include "i2c.h"

void I2C_GPIO_Init(void)
{
	GPIO_InitTypeDef I2C_GPIO_SCL_InitStructure;
	GPIO_InitTypeDef I2C_GPIO_SDA_InitStructure;
	
	I2C_GPIO_SCL_CLK_Cmd(I2C_SCL_CLK, ENABLE);
	I2C_GPIO_SDA_CLK_Cmd(I2C_SDA_CLK, ENABLE);
	
	I2C_GPIO_SCL_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	I2C_GPIO_SCL_InitStructure.GPIO_OType = GPIO_OType_PP;
	I2C_GPIO_SCL_InitStructure.GPIO_Pin = I2C_SCL_PIN;
	I2C_GPIO_SCL_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	I2C_GPIO_SCL_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	I2C_GPIO_SDA_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	I2C_GPIO_SDA_InitStructure.GPIO_OType = GPIO_OType_PP;
	I2C_GPIO_SDA_InitStructure.GPIO_Pin = I2C_SDA_PIN;
	I2C_GPIO_SDA_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	I2C_GPIO_SDA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(I2C_SCL_GPIO, &I2C_GPIO_SCL_InitStructure);
	GPIO_Init(I2C_SDA_GPIO, &I2C_GPIO_SDA_InitStructure);
	
	GPIO_SetBits(I2C_SCL_GPIO, I2C_SCL_PIN);
	GPIO_SetBits(I2C_SDA_GPIO, I2C_SDA_PIN);
}

void I2C_Initialization(void)
{
	I2C_GPIO_Init();
}

/* 开始信号，SCL高电平，SDA下降沿 */
void I2C_Start(void)
{
	I2C_SDA_OUT();
	I2C_SDA_1();
	I2C_SCL_1();
	Delay_Us(4);
	I2C_SDA_0();
	Delay_Us(4);
	I2C_SCL_0();
}

/* 结束信号，SCL高电平，SDA上升沿 */
void I2C_Stop(void)
{
	I2C_SCL_0();
	I2C_SDA_OUT();
	I2C_SDA_0();
	Delay_Us(4);
	I2C_SCL_1();
	I2C_SDA_1();
	Delay_Us(4);
}

/* 等待应答 */
uint8_t I2C_WaitAck(void)
{
	uint8_t time = 0;
	I2C_SCL_0();
	I2C_SDA_OUT();
	I2C_SDA_1();
	Delay_Us(1);
	I2C_SDA_IN();
	I2C_SCL_1();
	Delay_Us(1);
	while(I2C_SDA_Read())
	{
		time++;
		if (time > 250)
		{
			I2C_Stop();
			return NAck;
		}
	}
	I2C_SCL_0();
	return Ack;
}

void I2C_Ack(void)
{
	I2C_SCL_0();
	I2C_SDA_OUT();
	I2C_SDA_0();
	Delay_Us(2);
	I2C_SCL_1();
	Delay_Us(2);
	I2C_SCL_0();
}

void I2C_NAck(void)
{
	I2C_SCL_0();
	I2C_SDA_OUT();
	I2C_SDA_1();
	Delay_Us(2);
	I2C_SCL_1();
	Delay_Us(2);
	I2C_SCL_0();
}

void I2C_TransmitByte(uint8_t data)
{
	uint8_t i = 0;
	I2C_SCL_0();
	I2C_SDA_OUT();
	while(i < 8)
	{
		if (data<<i & 0x80)
			I2C_SDA_1();
		else
			I2C_SDA_0();
		Delay_Us(2);
		I2C_SCL_1();
		Delay_Us(2);
		I2C_SCL_0();
		Delay_Us(2);
		i++;
	}
	I2C_SDA_1();
}

uint8_t I2C_ReceiveByte(uint8_t ack)
{
	uint8_t data = 0;
	uint8_t i = 0;
	I2C_SCL_0();
	I2C_SDA_IN();
	while(i < 8)
	{
		I2C_SCL_0();
		Delay_Us(2);
		I2C_SCL_1();
		data <<= 1;//debug一天！
		data |= I2C_SDA_Read();
		i++;
		Delay_Us(1);
	}
	if (ack == Ack)
		I2C_Ack();
	else
		I2C_NAck();
	return data;
	
}


