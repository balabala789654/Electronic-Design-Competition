#include "ti_msp_dl_config.h"
#include "user.h"

extern bool During_Line_Patrol_Judgment_Flag;

/*
	0 是黑线
	1 是白线
*/

bool* Line_patrol_read(void){ //巡线模块
	static bool Line_Patrol[6]={0};
	
//	_Status = DL_GPIO_readPins(GPIO_Line_patrol_PIN_0_PORT, GPIO_Line_patrol_PIN_0_PIN)
	Line_Patrol[0]=DL_GPIO_readPins(GPIO_Line_patrol_PIN_0_PORT, GPIO_Line_patrol_PIN_0_PIN);
	Line_Patrol[1]=DL_GPIO_readPins(GPIO_Line_patrol_PIN_1_PORT, GPIO_Line_patrol_PIN_1_PIN); 
	Line_Patrol[2]=DL_GPIO_readPins(GPIO_Line_patrol_PIN_2_PORT, GPIO_Line_patrol_PIN_2_PIN); 
	Line_Patrol[3]=DL_GPIO_readPins(GPIO_Line_patrol_PIN_3_PORT, GPIO_Line_patrol_PIN_3_PIN); 
	Line_Patrol[4]=DL_GPIO_readPins(GPIO_Line_patrol_PIN_4_PORT, GPIO_Line_patrol_PIN_4_PIN); 
	Line_Patrol[5]=DL_GPIO_readPins(GPIO_Line_patrol_PIN_5_PORT, GPIO_Line_patrol_PIN_5_PIN); 	
	
	return Line_Patrol;
}

float Line_Patrol_Judgment(void){
	
	float Uint_3 = 2.0;
	float Uint_2 = 1.5;
	float Uint_1 = 1.0;
	
	static bool* Status; 
	static uint8_t Last_Status;
	
	float Uint_Speed = 50;
	
	Status = Line_patrol_read();
	
	if(!During_Line_Patrol_Judgment_Flag) //没有在黑线上
		return 0; 

	if((!*(Status+2)) & (!*(Status+3)))
		return 0;
	
	if(*Status & *(Status+1) & *(Status+2) & *(Status+3) & *(Status+4) & *(Status+5)){ //没有黑线
		if(During_Line_Patrol_Judgment_Flag){
			if((Last_Status == 0x20)) return Uint_Speed * -Uint_3;
			else if((Last_Status == 0x10)) return Uint_Speed * -Uint_2;
			else if((Last_Status == 0x08)) return Uint_Speed * -Uint_1;
			else if((Last_Status == 0x04)) return Uint_Speed * Uint_1;
			else if((Last_Status == 0x02)) return Uint_Speed * Uint_2;
			else if((Last_Status == 0x01)) return Uint_Speed * Uint_3;
		}
	}else{
		if(!*Status){
			Last_Status = 0x01<<5;
			return Uint_Speed * -Uint_3;
		}else if(!*(Status+1)){
			Last_Status = 0x01<<4;
			return Uint_Speed * -Uint_2;
		}else if(!*(Status+2)){
			Last_Status = 0x01<<3;
			return Uint_Speed * -Uint_1;
		}else if(!*(Status+3)){
			Last_Status = 0x01<<2;
			return Uint_Speed * Uint_1;
		}else if(!*(Status+4)){
			Last_Status = 0x01<<1;
			return Uint_Speed * Uint_2;
		}else if(!*(Status+5)){
			Last_Status = 0x01;
			return Uint_Speed * Uint_3;
		}else {
			return 1; //错误
		}
	}
	return 0;
}                               
