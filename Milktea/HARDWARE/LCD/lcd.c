#include "lcd.h"

//void LCD_Delay1ms(uint c)   //误差 0us
//{
//    uchar a,b;
//	for (; c>0; c--)
//	{
//		 for (b=199;b>0;b--)
//		  	for(a=1;a>0;a--);    
//	}	
//}

void LCDsetcoord(uchar x,uchar y)
{
	uchar adress=0;
	if(y==0)
		adress=0x00+x;
	else
		adress=0x40+x;			  //根据xy的值计算指针位置
	LCDwriteCmd(adress | 0x80);  //写设置指针指令
}

/*void LCDwaiteReady()    //读/写检测
{
	uchar sta;
	LCD_D0=0xFF;
	LCD_RS=0;
	LCD_RW=1;
	do{
		LCD_E=1;
		sta=LCD_D0;
		LCD_E=0;
	}while(sta&0x80);
}*/

void LCDwriteCmd(uchar cmd)
{
//	LCDwaiteReady(); //进行LCD的读写检测
	LCD_E0;
	LCD_RS0;
	LCD_RW0;

	LCD_D0(cmd);
	LCD_Delay1ms(1);

	LCD_E1;
	LCD_Delay1ms(5);
	LCD_E0;
}

void LCDwritedate(uchar date)
{
//	LCDwaiteReady();
	LCD_E0;
	LCD_RS1;
	LCD_RW0;
	LCD_D0(date);

	LCD_Delay1ms(1);

	LCD_E1;
	LCD_Delay1ms(5);
	LCD_E0;
}

void LCDshowstr(uchar x, uchar y,uchar *str)
{
	LCDsetcoord(x,y);
	while(*str!='\0')
	{
		LCDwritedate(*str);
		str++;
	}
}

void LCDAreaClear(uchar x, uchar y, uchar len)
{
    LCDsetcoord(x, y);   //设置起始地址
    while (len--)         //连续写入空格
    {
        LCDwritedate(' ');
    }
}

void LCDFullClear(void)
{
    LCDwriteCmd(0x01);
}



void LCDinit(void)
{
	LCDwriteCmd(0x38);  //0x38设置16x2显示 5*7点阵
	LCDwriteCmd(0x0C);  //0x0c 开显示
	LCDwriteCmd(0x06); 	//读或者写一个字符后地址指针加1
	LCDwriteCmd(0x01);
}
