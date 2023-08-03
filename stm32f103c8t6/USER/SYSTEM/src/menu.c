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
	OLED_ShowString(0, 0, "A:");
	OLED_ShowNum(20, 0, mycar.communicate.rec_data[1], 3, 8);
	OLED_ShowNum(60, 0, mycar.communicate.rec_data[2], 3, 8);
	OLED_ShowString(0, 2, "B:");
	OLED_ShowNum(20, 2, mycar.communicate.rec_data[3], 3, 8);
	OLED_ShowNum(60, 2, mycar.communicate.rec_data[4], 3, 8);
	OLED_ShowString(0, 4, "C:");
	OLED_ShowNum(20, 4, mycar.communicate.rec_data[5], 3, 8);
	OLED_ShowNum(60, 4, mycar.communicate.rec_data[6], 3, 8);
	OLED_ShowString(0, 6, "D:");
	OLED_ShowNum(20, 6, mycar.communicate.rec_data[7], 3, 8);
	OLED_ShowNum(60, 6, mycar.communicate.rec_data[8], 3, 8);	
}
