#ifndef __LCDSUPPLEMENT_H
#define __LCDSUPPLEMENT_H

#include "stm32f4xx.h"
#include "systick.h"

#define uchar uint8_t

#define LCD_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define LCD_GPIO_CLK RCC_AHB1Periph_GPIOD
#define LCD_GPIO GPIOD

//sbit LCD_RS=P2^6;			//数据/命令选择端
//sbit LCD_RW=P2^5;			//读/写选择端
//sbit LCD_E=P2^7;			//使能信号

#define LCD_E0 GPIO_ResetBits(LCD_GPIO, GPIO_Pin_8)
#define LCD_RS0 GPIO_ResetBits(LCD_GPIO, GPIO_Pin_9)
#define LCD_RW0 GPIO_ResetBits(LCD_GPIO, GPIO_Pin_10)
#define LCD_E1 GPIO_SetBits(LCD_GPIO, GPIO_Pin_8)
#define LCD_RS1 GPIO_SetBits(LCD_GPIO, GPIO_Pin_9)
#define LCD_RW1 GPIO_SetBits(LCD_GPIO, GPIO_Pin_10)

#define LCD_D0(data) LCD_WriteData(data)

#define LCD_Delay1ms(Ms) Delay_Ms(Ms)

void LCD_Initialization(void);

void LCD_WriteData(uint8_t data);

#endif

