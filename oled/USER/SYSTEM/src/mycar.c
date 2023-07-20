#include "mycar.h"

	
int abs(int _input);
void chassis_control(int _straight, int _spin);
int mycar_control(p3 (* _p3)(uint8_t _data[13]));

MYCAR mycar;

void mycar_init(void)
{
	mycar.controller=p3_remote_output;
	mycar.chassis.control=chassis_control;
	mycar.control=mycar_control;
}

int mycar_control(p3 (* _p3)(uint8_t _data[13]))
{
	int _straight = _p3(verify_data).ch[3]*1000/127;
	int _spin = _p3(verify_data).ch[0]*1000/127;
	
	mycar.chassis.control(_straight, _spin);
	return _straight;
}


void chassis_control(int _straight, int _spin)
{
	if(_spin==0)
	{
		if(_straight<0) 
		{
			mycar.chassis.motorA.direction(2);
			mycar.chassis.motorB.direction(2);
		}
		else 
		{
			mycar.chassis.motorA.direction(1);
			mycar.chassis.motorB.direction(1);
		}
		
		mycar.chassis.motorA.rpm(abs(_straight));
		mycar.chassis.motorB.rpm(abs(_straight));
	}
	else 
	{
		if(_spin<0)
		{
			mycar.chassis.motorA.direction(1);
			mycar.chassis.motorB.direction(2);
		}
		else 
		{
			mycar.chassis.motorA.direction(2);
			mycar.chassis.motorB.direction(1);
			
		}
		mycar.chassis.motorA.rpm(abs(_spin));
		mycar.chassis.motorB.rpm(abs(_spin));
		
		
	}
	
}



int abs(int _input)
{
	if(_input<0) return -_input;
	else return _input;
}



