#ifndef _K210_H
#define _K210_H

#define data_len 4

void K210_Init(void);


typedef struct
{
	char rec_data[data_len];
	
}COMMUNICATE;
#endif

