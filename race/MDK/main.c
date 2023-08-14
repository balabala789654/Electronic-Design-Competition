#include "stm32f10x.h"                  // Device header
#include "gpio.h"
#include "usart.h"
#include "timer.h"
/*
180舵机
	舵机的控制一般需要一个20ms的脉冲，角度对应如下：
	t = 0.5ms——————-舵机会转动 0 °	50
	t = 1.0ms——————-舵机会转动 45°	100
	t = 1.5ms——————-舵机会转动 90°	150
	t = 2.0ms——————-舵机会转动 135°	200
	t = 2.5ms——————-舵机会转动180°	250
	————————————————

360舵机

	PWM 信号与360舵机转速的关系：
	0.5ms----------------正向最大转速；
	
	1.5ms----------------速度为0；
	
	2.5ms----------------反向最大转速；
*/
int angle=50;
int angle1=50;
int main()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); 
	LED_Init();
	TIM2_Int_Init(8000-1, 720-1);
	TIM3_PWM_Init(2000-1, 720-1);
	while(1)
	{
		TIM_SetCompare1(TIM3, angle);
		TIM_SetCompare2(TIM3, angle1);
	}
 }

