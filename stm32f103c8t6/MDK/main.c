#include "delay.h"
#include "sys.h"
#include "menu.h"
#include "gpio.h"
#include "exti.h"
#include "D153B.h"
#include "timer.h"
#include "p3.h"
#include "usart.h"
#include "mycar.h"

int rpm=2000;
int dir=1;
int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	LED_Init();
	delay_init();
	menu_init();
	KEY_Init();
	EXTIX_Init();
	TIM2_Int_Init(10000-1, 720-1);
	TIM4_Encoder_Init(3000-1, 72-1);
	D153B_init();
	p3_init(115200);
	mycar_init();
	
	while(1) 
	{		
		mycar.screen.display(mycar.control(mycar.controller));
	}
}

