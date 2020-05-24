#ifndef __MPU6050_H
#define __MPU6050_H

#include "stm32f4xx.h"
#include "i2c.h"

#if FLAG

void Mpu6050_Init(void);

void Mpu6050_GetData(s16 *data);

#else

/************************************/
#define MPU6050_INT_CLK RCC_AHB1Periph_GPIOD
#define MPU6050_INT_PIN GPIO_Pin_7
#define MPU6050_INT_GPIO GPIOD


#define MPU6050_ADDR 0x68 //AD0½ÓGND
#define MPU6050_POWER_1_REG 0x6b
#define MPU6050_GYRO_CONFIG_REG 0x1b
#define MPU6050_ACCE_CONFIG_REG 0x1c
#define MPU6050_FIFO_REG 0x23
#define MPU6050_GYRO_SAMP_REG 0x19
#define MPU6050_CONFIG_REG 0x1a
#define MPU6050_POWER_2_REG 0x6c

#define MPU6050_GYRO_XOUT_H 0x43
#define MPU6050_GYRO_XOUT_L 0x44
#define MPU6050_GYRO_YOUT_H 0x45
#define MPU6050_GYRO_YOUT_L 0x46
#define MPU6050_GYRO_ZOUT_H 0x47
#define MPU6050_GYRO_ZOUT_L 0x48

#define MPU6050_ACCE_XOUT_H 0x3b
#define MPU6050_ACCE_XOUT_L 0x3c
#define MPU6050_ACCE_YOUT_H 0x3d
#define MPU6050_ACCE_YOUT_L 0x3e
#define MPU6050_ACCE_ZOUT_H 0x3f
#define MPU6050_ACCE_ZOUT_L 0x40

void MPU6050_CallBack(uint8_t code);

uint8_t MPU6050_Write(uint8_t slave_addr, uint8_t reg_addr, uint8_t len, const uint8_t * data);

uint8_t MPU6050_Read(uint8_t slave_addr, uint8_t reg_addr, uint8_t len, uint8_t * data);

void MPU6050_Init(void);

uint16_t MPU6050_GetData(uint8_t reg);

#endif

#endif

