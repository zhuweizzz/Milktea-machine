#ifndef _LCD_H_
#define _LCD_H_

#include "lcdsupplement.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif
 
//#define LCD_D0 P0

//sbit LCD_RS=P2^6;			//数据/命令选择端
//sbit LCD_RW=P2^5;			//读/写选择端
//sbit LCD_E=P2^7;			//使能信号



void LCDshowstr(uchar x, uchar y,uchar *str);
void LCDsetcoord(uchar x,uchar y);
void LCDwritedate(uchar date);
//void LCDwaiteReady();
void LCDwriteCmd(uchar cmd);
void LCDinit(void);
//void LCD_Delay1ms(uint c);
void LCDAreaClear(uchar x, uchar y, uchar len);
void LCDFullClear(void);

#endif
