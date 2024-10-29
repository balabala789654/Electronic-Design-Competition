#include "ti_msp_dl_config.h"
#include "user.h"

/* This results in approximately 0.5s of delay assuming 32MHz CPU_CLK */
#define DELAY (32000) //1ms

uint8_t times = 1;

float KP = 2.3f;
float KI = 0.02f;
float KD = 1.0f;

int main(void)
{
    SYSCFG_DL_init();
	DL_TimerG_startCounter(PWM_Motor_INST);
		
	NVIC_EnableIRQ(TIMER_Location_INST_INT_IRQN);
	NVIC_EnableIRQ(GPIO_Encoder_INT_IRQN);
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
	NVIC_EnableIRQ(TIMER_Encoder_INST_INT_IRQN);
	
	PID_Init(KP, KI, KD);
	
	Mode_select();
	Last_Robot_Motion = Motion_Stop_Flag;
	
    while (1){		
		if(!*Mode_select() && !*(Mode_select()+1)){
			if(Task_1(times)){
				Beep_And_Led_Delay(500);
			}
		}
		else if(!*Mode_select() && *(Mode_select()+1))
			Task_2(1);
		else if(*Mode_select() && !*(Mode_select()+1))
			Task_3(1);
		else if(*Mode_select() && *(Mode_select()+1))
			Task_3(1);
		delay_cycles(DELAY);
    }
}


//滴答定时器中断
static int Motion_Beep_Led_Time=0;

void SysTick_Handler(void){		//Systick 中断实现点灯
	DL_GPIO_togglePins(GPIO_LED_PORT, GPIO_LED_led_PIN);
	Chassis_Control(Straight_Speed, Spin_Speed, Use_PID_Control_Flag);
	
	
	if(Beep_Led_Flag || (Motion_Beep_Led_Time != 0)){
		Beep_Led_Flag=0;
		Beep_And_Led_Work(1);
		Motion_Beep_Led_Time++;
		if(Motion_Beep_Led_Time > 100){
			Beep_And_Led_Stop(1);
			Motion_Beep_Led_Time=0;
		}
	}
}

bool During_Line_Patrol_Judgment_Flag = 0;
static uint8_t During_Line_Patrol_Judgment_Flag_Times=0;

bool Posture_Correction_Flag = 0;
bool Posture_Correction_Task3_Flag = 0;
bool Posture_Correction_Complete_Flag = 0;
static int32_t Posture_Correction_Times=0;

void TIMER_0_INST_IRQHandler(void){
	bool* Status;
	static uint8_t times;
	Status = Line_patrol_read();

	if(*Status & *(Status+1) & *(Status+2) & *(Status+3) & *(Status+4) & *(Status+5)) //没有黑线
		During_Line_Patrol_Judgment_Flag_Times++;
	else{
		During_Line_Patrol_Judgment_Flag = 1;
		During_Line_Patrol_Judgment_Flag_Times=0;
	}
	
	if(During_Line_Patrol_Judgment_Flag_Times > 60){
		During_Line_Patrol_Judgment_Flag=0; 	//如果超过1ms没有黑线 则全局发送没在黑线标志位
	}

	if(Posture_Correction_Flag){
		Posture_Correction_Times++;
		Straight_And_Spin_Set(0, 80, 0);
		if(Posture_Correction_Times > 50){
			Posture_Correction_Flag=0; 
			Posture_Correction_Times=0;
			Posture_Correction_Complete_Flag=1;//修正完成
			Straight_And_Spin_Set(0, 0, 0);
		}
	}else if(Posture_Correction_Task3_Flag){
		Posture_Correction_Times++;
		Straight_And_Spin_Set(0, -100, 0);
		if(Posture_Correction_Times > 100){
			Posture_Correction_Task3_Flag=0; 
			Posture_Correction_Times=0;
			Posture_Correction_Complete_Flag=1;//修正完成
			Straight_And_Spin_Set(0, 0, 0);
		}		
	}
}

void delay_ms(int _time){
	for(int i=0; i<_time; i++){
		delay_cycles(DELAY);
	}
}
