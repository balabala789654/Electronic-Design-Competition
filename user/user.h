#ifndef __USER_H_
#define __USER_H_

#include "stdint.h"

#define MotorA_speed GPIO_PWM_Motor_C0_IDX
#define MotorB_speed GPIO_PWM_Motor_C1_IDX
#define pi 3.14f
#define Radius 0.024f //单位 m
#define Reduction_Ratio 20
#define Car_Length 0.15f
#define Space_Hypotenuse 1.28f	// m
#define Space_Length 1.0f			// m

enum Motion{
	Motion_Straight_Flag = 1,
	Motion_Straight_Hypotenuse_Flag,
	Motion_Patrol_Flag,
	Motion_Search_Flag,
	Motion_IMU_Correction_Flag,
	Motion_Correction_Left_Flag,
	Motion_Correction_Right_Flag,
	Motion_Stop_Flag
};

extern enum Motion Robot_Motion;
extern enum Motion Last_Robot_Motion;
extern float Left_speed, Right_speed; 	//轮速
extern float Straight_Speed, Spin_Speed;
extern float Odom;						//里程
extern uint8_t times;
extern bool During_Line_Patrol_Judgment_Flag;
extern bool Posture_Correction_Flag;
extern bool Posture_Correction_Task3_Flag;
extern bool Posture_Correction_Complete_Flag;
extern bool Use_PID_Control_Flag;
extern bool Beep_Led_Flag;

void delay_ms(int _time);
char Chassis_Control(float _straight, float _spin, bool _mode);
bool* Line_patrol_read(void);
void PID_Control_Chassis_Stright(float _target);
bool* Mode_select(void);
void Beep_work(void);
void Beep_stop(void);
void Led_work(void);
void Led_stop(void);
float Line_Patrol_Judgment(void);
float Low_Pass_Filter(float _input);
void Beep_And_Led_Stop(uint8_t _times);
void Beep_And_Led_Work(uint8_t _times);
void Beep_And_Led_Delay(int _times);
void Straight_And_Spin_Set(float _straight, float _spin, bool _chassis_mode);
int Rpm_To_PWM(float _Rpm);

void PID_Init(float _kp, float _ki, float _kd);
float Position_PID (float Encoder,float Target, uint8_t _i);

bool Task_1(uint8_t _times);
bool Task_2(uint8_t _times);
bool Task_3(uint8_t _times);
bool Task_4(uint8_t _times);

#endif