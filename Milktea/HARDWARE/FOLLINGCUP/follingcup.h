 #ifndef _FOLLINGCUP_H
#define _FOLLINGCUP_H


#include "stm32f4xx.h"
#include "systick.h"
#include "usart1.h"



//#define KEY_INT_GPIO_PORT         GPIOC  

//#define KEY_INT_GPIO_CLK          RCC_AHB1Periph_GPIOC
//#define KEY_INT_GPIO_PIN          GPIO_Pin_13

//#define KEY_INT_EXTI_PORTSOURCE   EXTI_PortSourceGPIOC
//#define KEY_INT_EXTI_PINSOURCE    EXTI_PinSource13
//#define KEY_INT_EXTI_LINE         EXTI_Line13
//#define KEY_INT_EXTI_IRQ          EXTI15_10_IRQn

//#define KEY_IRQHandler            EXTI15_10_IRQHandler



#define MotorRelay_GPIO 					GPIOE
#define MotorRelay_GPIO_CLK 			RCC_AHB1Periph_GPIOE
#define MotorRelay_GPIO_CLK_Cmd		RCC_AHB1PeriphClockCmd
#define MotorRelay_pin 						GPIO_Pin_9



void FollingCup_Init(void);
//static void NVIC_Configuration(void);
//void EXTI_Key_Config(void);
void FolingCup_DrowCup(void);
//void KEY_IRQHandler(void);

#endif


