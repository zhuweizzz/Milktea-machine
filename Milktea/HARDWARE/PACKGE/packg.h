#ifndef _PACKG_H
#define _PACKG_H

#include "stm32f4xx.h"


#define PACKG_GPIO GPIOD
#define PACKG_GPIO_CLK RCC_AHB1Periph_GPIOD
#define PACKG_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd

#define PACKG_PUSH_Pin1  GPIO_Pin_13
#define PACKG_PUSH_Pin2  GPIO_Pin_14

   #define PACKG_MOTOR_EN_Pin GPIO_Pin_5
#define PACKG_MOTOR_STEP_Pin GPIO_Pin_6
#define PACKG_MOTOR_DIR_Pin GPIO_Pin_7


void Packge_Init(void);

void StepMotor_Enable(void);
void StepMotor_Disable(void);
void StepMotor_Turn(int cycle);


void Packge_Seal(void);

#endif
