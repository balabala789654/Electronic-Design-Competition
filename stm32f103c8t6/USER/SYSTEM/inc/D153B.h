#ifndef _D153B_H
#define _D153B_H

typedef struct
{
	void (*init)(void);
	void (*direction)(char _direction);
	void (*rpm)(int _rpm);
}MOTOR_A;

typedef struct
{
	void (*init)(void);
	void (*direction)(char _direction);
	void (*rpm)(int _rpm);
}MOTOR_B;

#define forward 1
#define reverse 2
#define brake 3

#define motorA_in_1_pin GPIO_Pin_4
#define motorA_in_2_pin GPIO_Pin_0

#define motorB_in_1_pin GPIO_Pin_5
#define motorB_in_2_pin GPIO_Pin_1


#define motorA_in_1 PCout(4) //PC4
#define motorA_in_2 PBout(0) //PB0

#define motorB_in_1 PCout(5) //PC5
#define motorB_in_2 PBout(1) //PB1

void D153B_init(void);


#endif

