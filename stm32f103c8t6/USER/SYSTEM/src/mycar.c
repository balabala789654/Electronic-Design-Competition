#include "mycar.h"

int max_speed=3000;
int abs(int _input);
void chassis_control(int _straight, int _spin, char _flag);
int mycar_control(p3 (* _p3)(uint8_t _data[13]), char _flag);

MYCAR mycar;

void mycar_init(void)
{
	mycar.controller.car_controller=p3_remote_output;
	mycar.chassis.control=chassis_control;
	mycar.control=mycar_control;
}

int mycar_control(p3 (* _p3)(uint8_t _data[13]), char _flag)
{
	int _straight = _p3(verify_data).ch[3]*max_speed/127;
	int _spin = _p3(verify_data).ch[0]*1000/127;
	int _straight_1, _straight_2;
	
	_straight_1 = _straight+_spin;
	_straight_2 = _straight-_spin;
	
	mycar.chassis.control(_straight_1, _straight_2, _flag);
	return _straight;
}


void chassis_control(int _speed_1, int _speed_2, char _flag)
{
	if(_flag!=1)
	{
		mycar.chassis.motorA.rpm(0);
		mycar.chassis.motorB.rpm(0);
	}
	else 
	{
		if(_speed_1>=0)
			mycar.chassis.motorA.direction(1);
		else 
			mycar.chassis.motorA.direction(2);
		
		if(_speed_2>=0)
			mycar.chassis.motorB.direction(1);
		else 
			mycar.chassis.motorB.direction(2);

		
		mycar.chassis.motorA.rpm(abs(_speed_1));
		mycar.chassis.motorB.rpm(abs(_speed_2));
	}
	
	
	
}



int abs(int _input)
{
	if(_input<0) return -_input;
	else return _input;
}



