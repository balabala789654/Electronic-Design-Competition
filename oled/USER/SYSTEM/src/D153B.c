#include "D153B.h"
#include "timer.h"
#include "gpio.h"
#include "mycar.h"

void motorA_forward(void);
void motorA_reverse(void);
void motorA_brake(void);
void motorA_rpm(int _rpm);
void motorA_init(void);
void motorA_direction(char _direction);
void motorB_forward(void);
void motorB_reverse(void);
void motorB_brake(void);
void motorB_rpm(int _rpm);
void motorB_init(void);
void motorB_direction(char _direction);




void D153B_init(void)
{
	D153B_goio_Init();
	TIM3_PWM_Init(3000-1, 72-1);
	mycar.chassis.motorA.init=motorA_init;
	mycar.chassis.motorB.init=motorB_init;
	
	mycar.chassis.motorA.init();
	mycar.chassis.motorB.init();
}


/***********************************************/
/***********************************************/
void motorA_init(void)
{
	mycar.chassis.motorA.direction=motorA_direction;
	mycar.chassis.motorA.rpm=motorA_rpm;
}

void motorA_rpm(int _rpm)
{
	TIM_SetCompare1(TIM3, _rpm);
}

void motorA_direction(char _direction)
{
	if(_direction==forward) motorA_forward();
	else if(_direction==reverse) motorA_reverse();
	else if(_direction==brake) motorA_brake();
}

void motorA_forward(void)
{
	motorA_in_1=1;
	motorA_in_2=0;
}

void motorA_reverse(void)
{
	motorA_in_1=0;
	motorA_in_2=1;
}

void motorA_brake(void)
{
	motorA_in_1=0;
	motorA_in_2=0;
}

/***********************************************/
/***********************************************/
void motorB_init(void)
{
	mycar.chassis.motorB.direction=motorB_direction;
	mycar.chassis.motorB.rpm=motorB_rpm;
}

void motorB_rpm(int _rpm)
{
	TIM_SetCompare2(TIM3, _rpm);
}

void motorB_direction(char _direction)
{
	if(_direction==forward) motorB_forward();
	else if(_direction==reverse) motorB_reverse();
	else if(_direction==brake) motorB_brake();
}

void motorB_forward(void)
{
	motorB_in_1=1;
	motorB_in_2=0;
}

void motorB_reverse(void)
{
	motorB_in_1=0;
	motorB_in_2=1;
}

void motorB_brake(void)
{
	motorB_in_1=0;
	motorB_in_2=0;
}

