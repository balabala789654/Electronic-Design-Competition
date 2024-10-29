#include "ti_msp_dl_config.h"
#include "user.h"

static float Position_KP;
static float Position_KI;
static float Position_KD;
static float Integral_bias[2] = {0};
static float Last_Bias[2] = {0};

void PID_Init(float _kp, float _ki, float _kd){
	Position_KP=_kp;
	Position_KI=_ki;
	Position_KD=_kd;
	
}

float Position_PID (float Encoder,float Target, uint8_t _i)
{
	float Bias,output;
	Bias=Target-Encoder;                                  									//计算偏差
	Integral_bias[_i]+=Bias;	                                 								//求出偏差的积分
	output=Position_KP*Bias+Position_KI*Integral_bias[_i]+Position_KD*(Bias-Last_Bias[_i]);       	//位置式PID控制器
	Last_Bias[_i]=Bias;                                       									//保存上一次偏差 
	return output;                                           								//增量输出
}
