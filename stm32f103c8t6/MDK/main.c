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
#include "E18_D80NK.h"
#include "k210.h"

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	LED_Init();
	delay_init();
	menu_init();
	E18_D80NK_init();
	EXTIX_Init();
	TIM2_Int_Init(10000-1, 720-1);
	TIM4_Encoder_Init(3000-1, 72-1);
	D153B_init();
	p3_init(115200);
	K210_Init();
	mycar_init();
	while(1) 
	{		
		mycar.screen.display(mycar.control(mycar.controller.car_controller, mycar.controller.controller_flag));
	}
}

