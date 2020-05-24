#ifndef __I2C_H
#define __I2C_H

#include "stm32f4xx.h"
#include "sysTick.h"

#define I2C_GPIO_SCL_CLK_Cmd RCC_AHB1PeriphClockCmd 
#define I2C_GPIO_SDA_CLK_Cmd RCC_AHB1PeriphClockCmd 

#define I2C_SCL_CLK RCC_AHB1Periph_GPIOB 
#define I2C_SDA_CLK RCC_AHB1Periph_GPIOB

#define I2C_SCL_GPIO GPIOB
#define I2C_SDA_GPIO GPIOB

#define I2C_SCL_PIN GPIO_Pin_8
#define I2C_SDA_PIN GPIO_Pin_9

#define I2C_SDA_IN() {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;};
#define I2C_SDA_OUT() {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;};

#define I2C_SCL_1() GPIO_SetBits(I2C_SCL_GPIO, I2C_SCL_PIN)
#define I2C_SCL_0() GPIO_ResetBits(I2C_SCL_GPIO, I2C_SCL_PIN)
#define I2C_SDA_1() GPIO_SetBits(I2C_SDA_GPIO, I2C_SDA_PIN)
#define I2C_SDA_0() GPIO_ResetBits(I2C_SDA_GPIO, I2C_SDA_PIN)

#define I2C_SCL_Read() GPIO_ReadInputDataBit(I2C_SCL_GPIO, I2C_SCL_PIN)
#define I2C_SDA_Read() GPIO_ReadInputDataBit(I2C_SDA_GPIO, I2C_SDA_PIN)

#define Ack 0
#define NAck 1

void I2C_GPIO_Init(void);

void I2C_Initialization(void);

static void I2C_Delay(void);

void I2C_Start(void);

void I2C_Stop(void);

uint8_t I2C_WaitAck(void);

void I2C_Ack(void);

void I2C_NAck(void);

void I2C_TransmitByte(uint8_t data);

uint8_t I2C_ReceiveByte(uint8_t ack);

#endif

