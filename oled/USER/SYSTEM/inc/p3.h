#ifndef _P3_H
#define _P3_H

#include "stdlib.h"
#include "sys.h"

typedef struct 
{
	int ch[4];
	char L2;
	char L1;
	char LU;
	char LL;
	char LD;
	char LR;
	char SE;
	char ST;
	char RL;
	char RD;
	char RR;
	char RU;
	char R1;
	char R2;
	char R_key;
	char L_key;	
}p3;
	
void head_verify(uint8_t _data[13]);
void verify_data_func(uint8_t _data[13]);
p3 p3_remote_output(uint8_t _data[13]);

extern uint8_t verify_data[13];

#endif

