#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f4xx.h"

void SysTick_Initialization(void);

void Delay_Ms(__IO uint32_t nMs);

void Delay_Us(__IO uint32_t nUs);

#endif 

