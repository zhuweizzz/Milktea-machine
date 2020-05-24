#include "stm32f4xx.h"
#include "systick.h"

#include "fenzhuang.h"


#include "milktea_make.h"
#include "peifang.h"
#include "usart1.h"
 
extern uint8_t usart1_flag_new;
extern uint8_t usatr1_rxvalue;

int main(void)
{
	SysTick_Initialization();
	
	FenZhuang_Initianization(); 
	
	while(1)
	{
		FenZhuang_addMilk(30);
		
		Delay_Ms(3000);
		
		FenZhuang_addMilk(20);
		
		Delay_Ms(3000);
	}
	
	
	
	SysTick_Initialization();
	Usart1_Initialization();
	MilkTea_Init();
	
	MilkTea_Typedef MIlk_type;
	
	while(1)
	{
		if(usart1_flag_new==1)
		{
			usart1_flag_new=0;
			
			switch(usatr1_rxvalue)
			{
				case 0x01: 	MIlk_type.milk_value=Milk1_value;  MIlk_type.sugar_value=sugar1_value;  MIlk_type.tea_value=tea1_value; MilkTea_Make(&MIlk_type);	break;
				case 0x02:  MIlk_type.milk_value=Milk2_value;  MIlk_type.sugar_value=sugar2_value;  MIlk_type.tea_value=tea2_value; MilkTea_Make(&MIlk_type); break;
				case 0x03:  MIlk_type.milk_value=Milk3_value;  MIlk_type.sugar_value=sugar3_value;  MIlk_type.tea_value=tea3_value; MilkTea_Make(&MIlk_type);	break;
				case 0x04:  MIlk_type.milk_value=Milk4_value;  MIlk_type.sugar_value=sugar4_value;  MIlk_type.tea_value=tea4_value; MilkTea_Make(&MIlk_type);	break;
				default: break;
			}

			Usart1_SendByte(0x00);
		}
	}

}







