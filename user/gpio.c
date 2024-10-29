#include "ti_msp_dl_config.h"
#include "user.h"

bool* Mode_select(void){ //²¦Âë¿ª¹Ø
	static bool mode[2]={0};
	mode[0] = DL_GPIO_readPins(GPIO_Mode_PORT, GPIO_Mode_mode1_PIN);
	mode[1] = DL_GPIO_readPins(GPIO_Mode_PORT, GPIO_Mode_mode2_PIN);
	
	return mode;
}

void Led_work(void){
	DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_led2_PIN);
}

void Led_stop(void){
	DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_led2_PIN);
}
