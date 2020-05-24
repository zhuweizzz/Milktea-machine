#include "follingcup.h"



//static void NVIC_Configuration(void)
//{
//  NVIC_InitTypeDef NVIC_InitStructure;
//  
//  /* 配置NVIC为优先级组1 */
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//  
//  /* 配置中断源：按键1 */
//  NVIC_InitStructure.NVIC_IRQChannel = KEY_INT_EXTI_IRQ;
//  /* 配置抢占优先级 */
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//  /* 配置子优先级 */
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//  /* 使能中断通道 */
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	
//  NVIC_Init(&NVIC_InitStructure);
// 
//	
//}

//void EXTI_Contl(FunctionalState STATE)
//{
//	EXTI_InitTypeDef EXTI_InitStructure;
//	
//	EXTI_InitStructure.EXTI_Line=KEY_INT_EXTI_LINE;
//	//模式
//	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
//	//设置下降沿触发
//	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
//	
//	EXTI_InitStructure.EXTI_LineCmd=STATE;
//	
//	EXTI_Init(&EXTI_InitStructure);
//	
//}
	

//void EXTI_Key_Config()
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	
//	RCC_AHB1PeriphClockCmd(KEY_INT_GPIO_CLK,ENABLE);
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE); //使能syscfg时钟
//	
//	NVIC_Configuration();
//	
//	
//	//配置GPIO
//	
//	GPIO_InitStructure.GPIO_Pin=KEY_INT_GPIO_PIN;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
//	GPIO_Init(KEY_INT_GPIO_PORT,&GPIO_InitStructure);
//	
//	//将EXTI中断源连接到KEY
//	
//	SYSCFG_EXTILineConfig(KEY_INT_EXTI_PORTSOURCE,KEY_INT_EXTI_PINSOURCE);
//	
//	//选择中断源
////	
////	EXTI_Contl(DISABLE);

//}
	

void MoterRelayinit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	MotorRelay_GPIO_CLK_Cmd(MotorRelay_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = MotorRelay_pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(MotorRelay_GPIO,&GPIO_InitStructure);
	
	GPIO_SetBits(MotorRelay_GPIO,MotorRelay_pin);
	
}

void  FollingCup_Init(void)
{
//	EXTI_Key_Config();
	MoterRelayinit();
}




//unsigned char Flag_onecup=0;

void FolingCup_DrowCup(void)
{
	
		GPIO_ResetBits(MotorRelay_GPIO,MotorRelay_pin);
	
		Delay_Ms(1925);
	
		GPIO_SetBits(MotorRelay_GPIO,MotorRelay_pin);
	
//		EXTI_Contl(ENABLE);
	
//		Flag_onecup=0;
//	
//		while(Flag_onecup==0);
//		
//		Flag_onecup=0;
	
	
}

//void KEY_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(KEY_INT_EXTI_LINE)!=RESET)
//	{
//		EXTI_Contl(DISABLE);
//		
//		Flag_onecup=1;
//		
//		Delay_Ms(500);
//		
//		GPIO_ResetBits(MotorRelay_GPIO,MotorRelay_pin);
//		
//		EXTI_ClearITPendingBit(KEY_INT_EXTI_LINE);
//	}
//}

