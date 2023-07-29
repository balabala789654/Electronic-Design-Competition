#ifndef _MENU_H
#define _MENU_H

#include "sys.h"
#define page 2

typedef struct
{
	char menu_page;
	void (*display)(int _input);
	
}MENU;

void menu_init(void);
void menu_display(MENU *_menu);

#endif

