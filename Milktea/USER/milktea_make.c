#include "milktea_make.h"


//对所有机器进行初始化

void MilkTea_Init(void)
{
	SysTick_Initialization();
	
	FollingCup_Init();
	
	MOTOR_Init();
	
	FenZhuang_Initianization();
	
	GTANG_Init();
	
	TEA_Initialization();
	
	Blender_Init();
	
	Burd_Initialization();
	
	Packge_Init();
}

void MilkTea_Make(MilkTea_Typedef *Milk_Tea_Structure)  //	落杯->分装机加奶粉->果糖机加果糖->保温桶加茶->加小料->搅拌->封口
{
	//传送带移动到  落杯   处
	Motor_Moveto(Loc_Cupdown);
	
	//落杯
	
	FolingCup_DrowCup();
	Delay_Ms(1000);
	
	//传送带移动到  分装机   处 
		
	Motor_Moveto(Loc_Fenzhaung);
	
	//设定分装机值后加奶粉
	
	FenZhuang_addMilk(Milk_Tea_Structure->milk_value);
	
	 
	//传送带移动到  果糖机   处
	
	Motor_Moveto(Loc_Guotang);
	
	
	//加果糖
	
	GTANG_Add_Suger(Milk_Tea_Structure->sugar_value);
	
	
	//传送带移动到  保温桶   处
	
	Motor_Moveto(Loc_Tea);
	
	//加茶
	TEA_OUT();
	Delay_Ms(1000);
	
	//传送带移动到  搅拌机 处
	Motor_Moveto(Loc_Mix);
	
	//搅拌
	
	Blender_Mix();
	
	//传送带移动到  漏斗  处 
	
	Motor_Moveto(Loc_Funnel);
	
	//加小料
	Burd_OUT();
	
	Delay_Ms(2000);
	//传送带移动到  封口机  处
	
	Motor_Moveto(Loc_Fengkou);
	
	Packge_Seal();
	//封口55
	
	Motor_Moveto(Loc_Out);
	
	
}


