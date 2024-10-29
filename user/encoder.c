#include "ti_msp_dl_config.h"
#include "user.h"

/*
	霍尔编码器，旋转一周为13个脉冲
	电机减速比 1：20
*/



int Left_count, Right_count = 0;

volatile uint32_t gpioA;
volatile uint32_t gpioB;
void GROUP1_IRQHandler(void){
	switch(DL_GPIO_getPendingInterrupt(GPIO_Encoder_PORT)){
		case GPIO_Encoder_m_A_en_1_IIDX:{
			Left_count++;
//			if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_m_A_en_2_PIN))
//				Left_count++;
//			else
//				Left_count--;
			break;
		}
		case GPIO_Encoder_m_B_en_1_IIDX:{
			Right_count++;
			
//			if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_m_B_en_2_PIN))
//				Right_count--;
//			else 
//				Right_count++;
			break;
		}
		default:
			break;
	}
}

float Per_Pulse_Distance = (float)(2 * pi * Radius)/(float)(Reduction_Ratio * 13);

float Left_speed, Right_speed = 0.0f;
int Left_speed_PWM, Right_speed_PWM = 0;

void TIMER_Encoder_INST_IRQHandler(void){
	Left_speed = (Per_Pulse_Distance * Left_count)/(0.1);
	Right_speed = (Per_Pulse_Distance * Right_count)/(0.1);
	Left_speed_PWM = Rpm_To_PWM(Left_speed);
	Right_speed_PWM = Rpm_To_PWM(Right_speed);
	Left_count=0;
	Right_count=0;
}



