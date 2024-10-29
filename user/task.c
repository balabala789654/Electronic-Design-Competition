#include "ti_msp_dl_config.h"
#include "user.h"

enum Motion Last_Robot_Motion;

void Beep_And_Led_Work(uint8_t _times){
	if(_times){
		Beep_work();
		Led_work();
	}
}

void Beep_And_Led_Stop(uint8_t _times){
	if(_times){
		Led_stop();
		Beep_stop();	
	}
}

void Beep_And_Led_Delay(int _times){
	Beep_And_Led_Work(1);
	delay_ms(_times);
	Beep_And_Led_Stop(1);
}

bool Task_1(uint8_t _times){
	if(!_times) return 0;
	if(During_Line_Patrol_Judgment_Flag){ //´æÔÚºÚÏß
		Robot_Motion = Motion_Stop_Flag;
		times--;
		return 1;
	}
	Robot_Motion = Motion_Straight_Flag;
	return 0;
}

static uint8_t Task2_time =2;
bool Task_2(uint8_t _times){
	if(!Task2_time) return 0;
	
	if(Last_Robot_Motion == Motion_Stop_Flag){
		Robot_Motion = Motion_Straight_Flag;
		Last_Robot_Motion = Motion_Straight_Flag;
	}
	if((Last_Robot_Motion == Motion_Straight_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Search_Flag;
		Last_Robot_Motion = Motion_Search_Flag;
	}
	if((Last_Robot_Motion == Motion_Search_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Patrol_Flag;
		Last_Robot_Motion = Motion_Patrol_Flag;
	}
	if((Last_Robot_Motion == Motion_Patrol_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Stop_Flag;
		Last_Robot_Motion = Motion_Stop_Flag;
		Task2_time--;
	}	
	return 0;
}

static uint8_t Task3_time =1;
bool Task_3(uint8_t _times){
	if(!Task3_time) return 0;
	
	if((Last_Robot_Motion == Motion_Stop_Flag) && (Task3_time==1)){
		Robot_Motion = Motion_Straight_Hypotenuse_Flag;
		Last_Robot_Motion = Motion_Straight_Hypotenuse_Flag;
		Task3_time++;
	}
	if((Last_Robot_Motion == Motion_Straight_Hypotenuse_Flag) && (Robot_Motion == Motion_Stop_Flag) && (Task3_time==2)){
		Robot_Motion = Motion_Search_Flag;
		Last_Robot_Motion = Motion_Search_Flag;
		Task3_time++;
	}
	if((Last_Robot_Motion == Motion_Search_Flag) && (Robot_Motion == Motion_Stop_Flag) && (Task3_time==3)){
		Robot_Motion = Motion_Patrol_Flag;
		Last_Robot_Motion = Motion_Patrol_Flag;
		Task3_time++;
	}
	if((Last_Robot_Motion == Motion_Patrol_Flag) && (Robot_Motion == Motion_Stop_Flag) && (Task3_time==4)){
		Robot_Motion = Motion_Correction_Left_Flag;
		Last_Robot_Motion = Motion_Correction_Left_Flag;
		Task3_time++;
	}
	if((Last_Robot_Motion == Motion_Correction_Left_Flag) && (Robot_Motion == Motion_Stop_Flag) && (Task3_time==5)){
		Robot_Motion = Motion_Straight_Hypotenuse_Flag;
		Last_Robot_Motion = Motion_Straight_Hypotenuse_Flag;
		Task3_time++;
	}
	if((Last_Robot_Motion == Motion_Straight_Hypotenuse_Flag) && (Robot_Motion == Motion_Stop_Flag) && (Task3_time==6)){
		Robot_Motion = Motion_Patrol_Flag;
		Last_Robot_Motion = Motion_Patrol_Flag;
		Task3_time++;
	}
	if((Last_Robot_Motion == Motion_Patrol_Flag) && (Robot_Motion == Motion_Stop_Flag) && (Task3_time==7)){
		Robot_Motion = Motion_Stop_Flag;
		Last_Robot_Motion = Motion_Stop_Flag;
		Task3_time++;
	}
	return 0;	
}


static uint8_t Task4_time =4;
bool Task_4(uint8_t _times){
	if(!Task4_time) return 0;
	
	if(Last_Robot_Motion == Motion_Stop_Flag){
		Robot_Motion = Motion_Straight_Hypotenuse_Flag;
		Last_Robot_Motion = Motion_Straight_Hypotenuse_Flag;
	}
	else if((Last_Robot_Motion == Motion_Straight_Hypotenuse_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Search_Flag;
		Last_Robot_Motion = Motion_Search_Flag;
	}
	else if((Last_Robot_Motion == Motion_Search_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Patrol_Flag;
		Last_Robot_Motion = Motion_Patrol_Flag;
	}
	else if((Last_Robot_Motion == Motion_Patrol_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Correction_Left_Flag;
		Last_Robot_Motion = Motion_Correction_Left_Flag;
	}
	else if((Last_Robot_Motion == Motion_Correction_Left_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Straight_Hypotenuse_Flag;
		Last_Robot_Motion = Motion_Straight_Hypotenuse_Flag;
	}
	else if((Last_Robot_Motion == Motion_Straight_Hypotenuse_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Patrol_Flag;
		Last_Robot_Motion = Motion_Patrol_Flag;
	}
	else if((Last_Robot_Motion == Motion_Patrol_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Robot_Motion = Motion_Correction_Right_Flag;
		Last_Robot_Motion = Motion_Correction_Right_Flag;
	}
	else if((Last_Robot_Motion == Motion_Correction_Right_Flag) && (Robot_Motion == Motion_Stop_Flag)){
		Last_Robot_Motion = Motion_Stop_Flag;
		Robot_Motion = Motion_Stop_Flag;
		Task4_time--;
	}
	return 0;	
}