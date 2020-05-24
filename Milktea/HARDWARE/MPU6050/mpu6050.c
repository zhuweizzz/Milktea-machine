#include "mpu6050.h"
#include "usart1.h"

void MPU6050_CallBack(uint8_t code)
{
	if (code == 0)
	{
		Usart1_SendString("Success");
	}
	else
	{
		Usart1_SendString("Error:");
		Usart1_SendByte(code);
		Usart1_SendByte(' ');
	}
}

uint8_t MPU6050_Write(uint8_t slave_addr, uint8_t reg_addr, uint8_t len, const uint8_t * data)
{
	uint8_t i;
	I2C_Start();
	I2C_TransmitByte((slave_addr<<1) | 0);
	if (I2C_WaitAck())
	{
		I2C_Stop();
		return 1;
	}
	I2C_TransmitByte(reg_addr);
	if (I2C_WaitAck())
	{
		I2C_Stop();
		return 1;
	}
	for (i = 0; i < len; i++)
	{
		I2C_TransmitByte(data[i]);
		if (I2C_WaitAck())
		{
			I2C_Stop();
			return 1;
		}
	}
	I2C_Stop();
	return 0;
}

uint8_t MPU6050_Read(uint8_t slave_addr, uint8_t reg_addr, uint8_t len, uint8_t * data)
{
	uint8_t i;
	I2C_Start();
	I2C_TransmitByte((slave_addr<<1) | 0);
	if (I2C_WaitAck())
	{
		I2C_Stop();
		return 1;
	}
	I2C_TransmitByte(reg_addr);
	if (I2C_WaitAck())
	{
		I2C_Stop();
		return 1;
	}
	I2C_Start();
	I2C_TransmitByte((slave_addr<<1) | 1);
	if (I2C_WaitAck())
	{
		I2C_Stop();
		return 1;
	}
	for (i = 0; i < len - 1; i++)
	{
		*(data + i) = I2C_ReceiveByte(Ack);
	}
	*(data + i) = I2C_ReceiveByte(NAck);
	I2C_Stop();
	return 0;
}

void MPU6050_Init(void)
{
	uint8_t data[7] = {0x80, 0x00, 0x18, 0x01, 0x07, 0x00, 0x06};
	MPU6050_Write(MPU6050_ADDR, MPU6050_POWER_1_REG, 1, data);//复位MPU6050
	Delay_ms(100);
	MPU6050_Write(MPU6050_ADDR, MPU6050_POWER_1_REG, 1, data + 1);//唤醒MPU6050，可以不要，复位后自动清零
	MPU6050_Write(MPU6050_ADDR, MPU6050_GYRO_CONFIG_REG, 1, data + 2);//陀螺仪量程2000
	MPU6050_Write(MPU6050_ADDR, MPU6050_ACCE_CONFIG_REG, 1, data + 3);//加速度计量程2
	MPU6050_Write(MPU6050_ADDR, MPU6050_GYRO_SAMP_REG, 1, data + 4);//采样频率
	MPU6050_Write(MPU6050_ADDR, MPU6050_FIFO_REG, 1, data + 5);//禁用FIFO
	MPU6050_Write(MPU6050_ADDR, MPU6050_CONFIG_REG, 1, data + 6);//低通滤波器，带宽5K，截止频率1K 
}

uint16_t MPU6050_GetData(uint8_t reg)
{
	uint8_t data;
	MPU6050_Read(MPU6050_ADDR, reg, 1, &data);
	return data;
}

