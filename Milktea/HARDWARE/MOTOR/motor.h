#ifndef _MOTOR_H
#define _MOTOR_H
//传送带电机控制程序

#include "stm32f4xx.h"
#include "systick.h"

#define MOTOR_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define MOTOR_GPIO_CLK RCC_AHB1Periph_GPIOD

#define MOTOR_GPIO GPIOD
#define MOTOR_PUL_GPIO_Pin GPIO_Pin_1

#define MOTOR_DIR_GPIO_Pin GPIO_Pin_2

#define MOTOR_ERC_GPIO_Pin GPIO_Pin_3

#define pig 30.2

#define Loc_Zero          0.0
#define Loc_Cupdown				2.5
#define Loc_Fenzhaung			50.0
#define Loc_Guotang				81.5
#define Loc_Tea						114.5
#define Loc_Mix						131.5
#define Loc_Funnel				150.5
#define Loc_Fengkou				184.0
#define Loc_Out						200.0


void MOTOR_Init(void);

void ConfigPul(int PulNum);
void Motor_Go_forward(float L);
void Motor_Go_back(float L);

void Motor_Moveto(float Location);


#endif

