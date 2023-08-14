#include "stm32f10x.h"                  // Device header
#include "gpio.h"
#include "usart.h"
#include "timer.h"
/*
180���
	����Ŀ���һ����Ҫһ��20ms�����壬�Ƕȶ�Ӧ���£�
	t = 0.5ms������������-�����ת�� 0 ��	50
	t = 1.0ms������������-�����ת�� 45��	100
	t = 1.5ms������������-�����ת�� 90��	150
	t = 2.0ms������������-�����ת�� 135��	200
	t = 2.5ms������������-�����ת��180��	250
	��������������������������������

360���

	PWM �ź���360���ת�ٵĹ�ϵ��
	0.5ms----------------�������ת�٣�
	
	1.5ms----------------�ٶ�Ϊ0��
	
	2.5ms----------------�������ת�٣�
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

