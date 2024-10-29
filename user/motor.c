#include "ti_msp_dl_config.h"
#include "user.h"
#include "math.h"

/*
	左轮 电机A
	右轮 电机B
*/

float Straight_Speed, Spin_Speed;
bool Use_PID_Control_Flag = 0;

int Rpm_To_PWM(float _Rpm){
	int PWM = (int)(_Rpm/(0.002f));
	return PWM;
}

float Low_Pass_Filter(float _input){
	static float _Last_output;
	static float P = 0.1;
	float _output;
	_output = _input*P + _Last_output*(1-P);
	
	_Last_output = _output;
	return _output;
}

//float fabs(float _input){
//	if(_input >= 0.0f) 
//		return _input;
//	else 
//		return (-_input);
//}

void MotorA_Direction_Set(bool _dir){ // 电机A bool 正转：1 反转：0
	if(_dir){
		DL_GPIO_setPins(GPIO_Motor_dir_m_A_IN_1_PORT, GPIO_Motor_dir_m_A_IN_1_PIN);
		DL_GPIO_clearPins(GPIO_Motor_dir_m_A_IN_2_PORT, GPIO_Motor_dir_m_A_IN_2_PIN);
	}
	else{
		DL_GPIO_clearPins(GPIO_Motor_dir_m_A_IN_1_PORT, GPIO_Motor_dir_m_A_IN_1_PIN);
		DL_GPIO_setPins(GPIO_Motor_dir_m_A_IN_2_PORT, GPIO_Motor_dir_m_A_IN_2_PIN);		
	}
	return;
}

void MotorB_Direction_Set(bool _dir){ //电机B bool 正转：1 反转：0
	if(_dir){
		DL_GPIO_setPins(GPIO_Motor_dir_m_B_IN_1_PORT, GPIO_Motor_dir_m_B_IN_1_PIN);
		DL_GPIO_clearPins(GPIO_Motor_dir_m_B_IN_2_PORT, GPIO_Motor_dir_m_B_IN_2_PIN);
	}
	else{
		DL_GPIO_clearPins(GPIO_Motor_dir_m_B_IN_1_PORT, GPIO_Motor_dir_m_B_IN_1_PIN);
		DL_GPIO_setPins(GPIO_Motor_dir_m_B_IN_2_PORT, GPIO_Motor_dir_m_B_IN_2_PIN);		
	}
	return;
}

void Motor_start(void){
	DL_TimerG_startCounter(PWM_Motor_INST); //电机启动
}


void Motor_stop(void){
	DL_TimerG_stopCounter(PWM_Motor_INST); //电机停止
}

//底盘控制
char Chassis_Control(float _straight, float _spin, bool _mode){
	float motor_A_speed_set, motor_B_speed_set = 0;
	
	if(_spin < 0.0f){ //左转
		motor_A_speed_set = _straight - fabs(_spin);
		motor_B_speed_set = _straight + fabs(_spin);
		
		if(motor_A_speed_set < 0){ //左转时存在电机A反转情况 电机B必定正转
			MotorA_Direction_Set(0);
			motor_A_speed_set = fabs(motor_A_speed_set);
		}
		else{
			MotorA_Direction_Set(1);
		}
		MotorB_Direction_Set(1);
		
		if(_mode){
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, Position_PID(Rpm_To_PWM(Left_speed), (int)motor_A_speed_set, 0), MotorA_speed);
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, Position_PID(Rpm_To_PWM(Right_speed), (int)motor_B_speed_set, 1), MotorB_speed);	
		}else{
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, (int)motor_A_speed_set, MotorA_speed);
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, (int)motor_B_speed_set, MotorB_speed);	
		}
	}
	else{ //右转
		motor_A_speed_set = _straight + fabs(_spin);
		motor_B_speed_set = _straight - fabs(_spin);
		
		if(motor_B_speed_set < 0){ //右转时存在电机B反转情况 电机A必定正转
			MotorB_Direction_Set(0);
			motor_B_speed_set = fabs(motor_B_speed_set);
		}
		else{
			MotorB_Direction_Set(1);
		}
		
		MotorA_Direction_Set(1);		
		if(_mode){
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, Position_PID(Rpm_To_PWM(Left_speed), (int)motor_A_speed_set, 0), MotorA_speed);
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, Position_PID(Rpm_To_PWM(Right_speed), (int)motor_B_speed_set, 1), MotorB_speed);	
		}else{
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, (int)motor_A_speed_set, MotorA_speed);
			DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, (int)motor_B_speed_set, MotorB_speed);	
		}
	}
	return 0;
}

void Straight_And_Spin_Set(float _straight, float _spin, bool _chassis_mode){
	
	Straight_Speed = _straight;
	Spin_Speed = _spin;
	if(_chassis_mode) Use_PID_Control_Flag = 1;
	else Use_PID_Control_Flag = 0;
}

int PWM_FeedBack = 0;
void PID_Control_Chassis_Stright(float _target){
	MotorA_Direction_Set(1);
	MotorB_Direction_Set(1);

//	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, Position_PID(Left_speed, _target, 0), MotorA_speed);
//	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, Position_PID(Right_speed, _target, 1), MotorB_speed);	

	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, (int)_target, MotorA_speed);
	DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, (int)_target, MotorB_speed);
	PWM_FeedBack = Rpm_To_PWM(Left_speed);
}

void IMU_Correction_Posture(float _target, float _current){
	
//	Straight_And_Spin_Set();
}
