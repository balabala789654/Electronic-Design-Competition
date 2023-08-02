#include "k210.h"
#include "usart.h"
#include "mycar.h"

void K210_Init(void)
{
	k210_init(115200);
}

char data_head_find(int _last_data[data_len])
{
	char n;
	for(int i=0; i<data_len; i++)
	{
		if(_last_data[i]==0xaa)
		{
			n=i;
			break;
		}
	}
	return n;
}

char data_end_find(int _last_data[data_len])
{
	char n;
	for(int i=0; i<data_len; i++)
	{
		if(_last_data[i]==0xbb)
		{
			n=i;
			break;
		}
	}
	return n;	
}

char* data_head_end_comfirm(char (*head)(int _last_data[data_len]), char (*end)(int _last_data[data_len]), int _data[data_len])
{
	static char head_end_data[2];
	head_end_data[0] = head(_data);
	head_end_data[1] = end(_data);
	return head_end_data;
}

int* k210_verify(int _last_data[data_len], char _head, char _end)
{
	static int _data[data_len];
	char n=_head;
	
	for(int i=0; i<data_len; i++)
	{
		_data[i] = _last_data[n++];
		if(n==data_len) n=0;
	}
	return _data;
}




