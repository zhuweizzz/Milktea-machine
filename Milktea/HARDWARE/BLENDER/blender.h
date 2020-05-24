#ifndef _BLENDER_H
#define _BLENDER_H

#include "stm32f4xx.h"


#define Blender_Key_GPIO GPIOE
#define Blender_GPIO_CLK RCC_AHB1Periph_GPIOE
#define Blender_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd

#define Key_ALL_Pin GPIO_Pin_13|GPIO_Pin_14


#define Key1_Pin GPIO_Pin_13
#define Key2_Pin GPIO_Pin_14

#define Key_power_Pin GPIO_Pin_15

#define Mix_Time  4000

void Blender_Init(void);

void Blender_Motor_Up(void);

void Blender_Mix(void);

    



#endif

