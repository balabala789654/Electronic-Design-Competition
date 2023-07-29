#ifndef _MYCAR_H
#define _MYCAR_H

#include "D153B.h"
#include "p3.h"
#include "menu.h"

typedef struct
{
	MOTOR_A motorA;
	MOTOR_B motorB;
	void (* control)(int _straight, int _spin);
}CHASSIS;

typedef struct
{
	CHASSIS chassis;
	MENU screen;	
	p3 (* controller)(uint8_t _data[13]);
	int (* control)(p3 (* _p3)(uint8_t _data[13]));

}MYCAR;


extern MYCAR mycar;
void mycar_init(void);

#endif


