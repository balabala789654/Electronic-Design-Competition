#ifndef _K210_H
#define _K210_H

#define data_len 4

void K210_Init(void);


typedef struct
{
	int verify_data[data_len];
	int rec_data[data_len];
	char head;
	char end;
}COMMUNICATE;

char* data_head_end_comfirm(char (*head)(int _last_data[data_len]), char (*end)(int _last_data[data_len]), int _data[data_len]);
int* k210_verify(int _last_data[data_len], char _head, char _end);
char data_end_find(int _last_data[data_len]);
char data_head_find(int _last_data[data_len]);



#endif

