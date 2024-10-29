#include "ti_msp_dl_config.h"

void Beep_work(void){
	DL_TimerG_startCounter(PWM_Beep_INST);
}


void Beep_stop(void){
	DL_TimerG_stopCounter(PWM_Beep_INST);
}

