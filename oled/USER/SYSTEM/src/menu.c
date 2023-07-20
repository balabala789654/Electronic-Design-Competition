#include "menu.h"
#include "oled.h"
#include "bmp.h"
#include "mycar.h"

void menu_page_1(int _input);


void menu_init(void)
{
	OLED_Init();			//≥ı ºªØOLED  
	OLED_Clear(); 	
	mycar.screen.menu_page=1;
	mycar.screen.display=menu_page_1;
}
void menu_page_1_1(void)
{	
	OLED_ShowString(0, 0, "speed: ");
}
void menu_page_1_2(void)
{
	OLED_DrawBMP(30, 0, 59+30, 7, image);
}

void menu_page_1(int _input)
{
	//OLED_ShowString(0, 0, "speed: ");
	OLED_ShowNum(0, 0, 12, 8, 8);
}
