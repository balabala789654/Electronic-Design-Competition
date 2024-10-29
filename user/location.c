#include "ti_msp_dl_config.h"
#include "user.h"

float Odom = 0;
static int Motion_Search_Time = 0;
static int Motion_Correct_Time = 0;
enum Motion Robot_Motion;

bool Search_Black_Line(bool _dir){
	if(_dir)
		Straight_And_Spin_Set(0, 200, 0);
	else 
		Straight_And_Spin_Set(0, -200, 0);
	
	if(During_Line_Patrol_Judgment_Flag){
		Motion_Search_Time=0;
		Robot_Motion = Motion_Stop_Flag;
		return 1;
	}else{
		return 0;
	}
}

bool Beep_Led_Flag = 0;

void TIMER_Location_INST_IRQHandler(void){
	if(Robot_Motion == Motion_Straight_Flag){
		Straight_And_Spin_Set(150, 0, 1);
//		Odom += ((Left_speed + Right_speed)/2.0f) * 0.03f;
		Odom += Left_speed * 0.03f;
		
		if(During_Line_Patrol_Judgment_Flag){
			Odom=0.0f;
			Robot_Motion = Motion_Stop_Flag;
			Beep_Led_Flag=1;
		}
		if((Car_Length + Odom) > (Space_Length + 0.1f)){
			Odom=0.0f;
			Robot_Motion = Motion_Stop_Flag;
			Beep_Led_Flag=1;
		}
	}
	else if(Robot_Motion == Motion_Straight_Hypotenuse_Flag){
		Straight_And_Spin_Set(150, 0, 1);
//		Odom += ((Left_speed + Right_speed)/2.0f) * 0.03f;
		Odom += Left_speed * 0.03f;
		if(During_Line_Patrol_Judgment_Flag){
			Odom=0.0f;
			Robot_Motion = Motion_Stop_Flag;
			Beep_Led_Flag=1;
		}		
		if((Car_Length + Odom) > (Space_Hypotenuse +  0.05f)){
			Odom=0.0f;
			Robot_Motion = Motion_Stop_Flag;
			Beep_Led_Flag=1;
		}	
	}
	else if(Robot_Motion == Motion_Search_Flag){ //搜寻
		Motion_Search_Time++;
		if(Motion_Search_Time < 100)
			Search_Black_Line(1);
		else if((Motion_Search_Time >= 100) && (Motion_Search_Time < 200))
			Search_Black_Line(0);
		else Motion_Search_Time = 0;
	}
	else if(Robot_Motion == Motion_Patrol_Flag){ //巡线
		Straight_And_Spin_Set(200, Line_Patrol_Judgment(), 0);
		if(!During_Line_Patrol_Judgment_Flag){
			Beep_Led_Flag=1;
			Robot_Motion = Motion_Stop_Flag;
		}
	}
	else if(Robot_Motion == Motion_IMU_Correction_Flag){ //IMU修正
		Straight_And_Spin_Set(0, Line_Patrol_Judgment(), 0);
	}
	else if(Robot_Motion == Motion_Correction_Left_Flag){ //向左修正
		Motion_Correct_Time++;
		Straight_And_Spin_Set(0, -100, 0);
		if(Motion_Correct_Time > 25){
			Motion_Correct_Time=0;
			Robot_Motion = Motion_Stop_Flag;
		}
	}
	else if(Robot_Motion == Motion_Correction_Right_Flag){ //向右修正
		Motion_Correct_Time++;
		Straight_And_Spin_Set(0, 100, 0);
		if(Motion_Correct_Time > 25){
			Motion_Correct_Time=0;
			Robot_Motion = Motion_Stop_Flag;
		}
	}
	else if(Robot_Motion == Motion_Stop_Flag){
		Beep_Led_Flag=1;
		Straight_And_Spin_Set(0, 0, 0);
		
	}
}
