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
	oled_display_chinese(16, 0, 8, 0);
	OLED_ShowString(0, 2, "img_cx: ");
	OLED_ShowNum(60, 2, mycar.communicate.rec_data[1], 3, 8);
	OLED_ShowString(0, 4, "img_cy: ");
	OLED_ShowNum(60, 4, mycar.communicate.rec_data[2], 3, 8);

}
