#ifndef _MILKTEA_MAKE_H
#define _MILKTEA_MAKE_H

#include "stm32f4xx.h"
#include "systick.h"
#include "motor.h" 
#include "guotang.h"
#include "fenzhuang.h"
#include "peifang.h"
#include "blender.h"
#include "follingcup.h"
#include "tea.h"
#include "burdening.h"
#include "packg.h"


void MilkTea_Init(void);

void MilkTea_Make(MilkTea_Typedef *Milk_Tea_Structure);


#endif

