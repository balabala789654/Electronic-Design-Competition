/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerG_backupConfig gPWM_BeepBackup;
DL_TimerA_backupConfig gTIMER_0Backup;
DL_TimerG_backupConfig gTIMER_EncoderBackup;
DL_TimerA_backupConfig gTIMER_LocationBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_PWM_Motor_init();
    SYSCFG_DL_PWM_Beep_init();
    SYSCFG_DL_TIMER_0_init();
    SYSCFG_DL_TIMER_Encoder_init();
    SYSCFG_DL_TIMER_Location_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gPWM_BeepBackup.backupRdy 	= false;
	gTIMER_0Backup.backupRdy 	= false;
	gTIMER_EncoderBackup.backupRdy 	= false;
	gTIMER_LocationBackup.backupRdy 	= false;

}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerG_saveConfiguration(PWM_Beep_INST, &gPWM_BeepBackup);
	retStatus &= DL_TimerA_saveConfiguration(TIMER_0_INST, &gTIMER_0Backup);
	retStatus &= DL_TimerG_saveConfiguration(TIMER_Encoder_INST, &gTIMER_EncoderBackup);
	retStatus &= DL_TimerA_saveConfiguration(TIMER_Location_INST, &gTIMER_LocationBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerG_restoreConfiguration(PWM_Beep_INST, &gPWM_BeepBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(TIMER_0_INST, &gTIMER_0Backup, false);
	retStatus &= DL_TimerG_restoreConfiguration(TIMER_Encoder_INST, &gTIMER_EncoderBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(TIMER_Location_INST, &gTIMER_LocationBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerG_reset(PWM_Motor_INST);
    DL_TimerG_reset(PWM_Beep_INST);
    DL_TimerA_reset(TIMER_0_INST);
    DL_TimerG_reset(TIMER_Encoder_INST);
    DL_TimerA_reset(TIMER_Location_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerG_enablePower(PWM_Motor_INST);
    DL_TimerG_enablePower(PWM_Beep_INST);
    DL_TimerA_enablePower(TIMER_0_INST);
    DL_TimerG_enablePower(TIMER_Encoder_INST);
    DL_TimerA_enablePower(TIMER_Location_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Motor_C0_IOMUX,GPIO_PWM_Motor_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Motor_C0_PORT, GPIO_PWM_Motor_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Motor_C1_IOMUX,GPIO_PWM_Motor_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Motor_C1_PORT, GPIO_PWM_Motor_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_Beep_C0_IOMUX,GPIO_PWM_Beep_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_Beep_C0_PORT, GPIO_PWM_Beep_C0_PIN);

    DL_GPIO_initDigitalInput(GPIO_Line_patrol_PIN_0_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Line_patrol_PIN_1_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Line_patrol_PIN_2_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Line_patrol_PIN_3_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Line_patrol_PIN_4_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Line_patrol_PIN_5_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_Motor_dir_m_A_IN_1_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_Motor_dir_m_A_IN_2_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_Motor_dir_m_B_IN_1_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_Motor_dir_m_B_IN_2_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_Motor_dir_enable_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_m_A_en_1_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_m_A_en_2_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_m_B_en_1_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_m_B_en_2_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_LED_led_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_LED_led2_IOMUX);

    DL_GPIO_initDigitalInputFeatures(GPIO_Mode_mode1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_Mode_mode2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_clearPins(GPIOA, GPIO_Motor_dir_m_A_IN_1_PIN |
		GPIO_Motor_dir_m_A_IN_2_PIN |
		GPIO_LED_led_PIN |
		GPIO_LED_led2_PIN);
    DL_GPIO_enableOutput(GPIOA, GPIO_Motor_dir_m_A_IN_1_PIN |
		GPIO_Motor_dir_m_A_IN_2_PIN |
		GPIO_LED_led_PIN |
		GPIO_LED_led2_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOA, DL_GPIO_PIN_0_EDGE_RISE |
		DL_GPIO_PIN_1_EDGE_RISE);
    DL_GPIO_setUpperPinsPolarity(GPIOA, DL_GPIO_PIN_28_EDGE_RISE |
		DL_GPIO_PIN_31_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Encoder_m_A_en_1_PIN |
		GPIO_Encoder_m_A_en_2_PIN |
		GPIO_Encoder_m_B_en_1_PIN |
		GPIO_Encoder_m_B_en_2_PIN);
    DL_GPIO_enableInterrupt(GPIOA, GPIO_Encoder_m_A_en_1_PIN |
		GPIO_Encoder_m_A_en_2_PIN |
		GPIO_Encoder_m_B_en_1_PIN |
		GPIO_Encoder_m_B_en_2_PIN);
    DL_GPIO_clearPins(GPIOB, GPIO_Motor_dir_m_B_IN_1_PIN |
		GPIO_Motor_dir_m_B_IN_2_PIN);
    DL_GPIO_setPins(GPIOB, GPIO_Motor_dir_enable_PIN);
    DL_GPIO_enableOutput(GPIOB, GPIO_Motor_dir_m_B_IN_1_PIN |
		GPIO_Motor_dir_m_B_IN_2_PIN |
		GPIO_Motor_dir_enable_PIN);

}



SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_enableMFCLK();
    DL_SYSCTL_enableMFPCLK();
	DL_SYSCTL_setMFPCLKSource(DL_SYSCTL_MFPCLK_SOURCE_SYSOSC);
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOA_INT_IRQn, 0);

}


/*
 * Timer clock configuration to be sourced by  / 1 (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 32000000 Hz / (1 * (31 + 1))
 */
static const DL_TimerG_ClockConfig gPWM_MotorClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 31U
};

static const DL_TimerG_PWMConfig gPWM_MotorConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 1000,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_Motor_init(void) {

    DL_TimerG_setClockConfig(
        PWM_Motor_INST, (DL_TimerG_ClockConfig *) &gPWM_MotorClockConfig);

    DL_TimerG_initPWMMode(
        PWM_Motor_INST, (DL_TimerG_PWMConfig *) &gPWM_MotorConfig);

    DL_TimerG_setCaptureCompareOutCtl(PWM_Motor_INST, DL_TIMER_CC_OCTL_INIT_VAL_HIGH,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_Motor_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_0_INDEX);

    DL_TimerG_setCaptureCompareOutCtl(PWM_Motor_INST, DL_TIMER_CC_OCTL_INIT_VAL_HIGH,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_Motor_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(PWM_Motor_INST);


    
    DL_TimerG_setCCPDirection(PWM_Motor_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 1 (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   160000 Hz = 32000000 Hz / (1 * (199 + 1))
 */
static const DL_TimerG_ClockConfig gPWM_BeepClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 199U
};

static const DL_TimerG_PWMConfig gPWM_BeepConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 500,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_Beep_init(void) {

    DL_TimerG_setClockConfig(
        PWM_Beep_INST, (DL_TimerG_ClockConfig *) &gPWM_BeepClockConfig);

    DL_TimerG_initPWMMode(
        PWM_Beep_INST, (DL_TimerG_PWMConfig *) &gPWM_BeepConfig);

    DL_TimerG_setCaptureCompareOutCtl(PWM_Beep_INST, DL_TIMER_CC_OCTL_INIT_VAL_HIGH,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_Beep_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_Beep_INST, 400, DL_TIMER_CC_0_INDEX);

    DL_TimerG_enableClock(PWM_Beep_INST);


    
    DL_TimerG_setCCPDirection(PWM_Beep_INST , DL_TIMER_CC0_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   250000 Hz = 32000000 Hz / (1 * (127 + 1))
 */
static const DL_TimerA_ClockConfig gTIMER_0ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 127U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_0_INST_LOAD_VALUE = (10 ms * 250000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTIMER_0TimerConfig = {
    .period     = TIMER_0_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC_UP,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_0_init(void) {

    DL_TimerA_setClockConfig(TIMER_0_INST,
        (DL_TimerA_ClockConfig *) &gTIMER_0ClockConfig);

    DL_TimerA_initTimerMode(TIMER_0_INST,
        (DL_TimerA_TimerConfig *) &gTIMER_0TimerConfig);
    DL_TimerA_enableInterrupt(TIMER_0_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
    DL_TimerA_enableClock(TIMER_0_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   125000 Hz = 32000000 Hz / (1 * (255 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_EncoderClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 255U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_Encoder_INST_LOAD_VALUE = (100 ms * 125000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_EncoderTimerConfig = {
    .period     = TIMER_Encoder_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_Encoder_init(void) {

    DL_TimerG_setClockConfig(TIMER_Encoder_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_EncoderClockConfig);

    DL_TimerG_initTimerMode(TIMER_Encoder_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_EncoderTimerConfig);
    DL_TimerG_enableInterrupt(TIMER_Encoder_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
    DL_TimerG_enableClock(TIMER_Encoder_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   125000 Hz = 32000000 Hz / (1 * (255 + 1))
 */
static const DL_TimerA_ClockConfig gTIMER_LocationClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 255U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_Location_INST_LOAD_VALUE = (30ms * 125000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTIMER_LocationTimerConfig = {
    .period     = TIMER_Location_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_Location_init(void) {

    DL_TimerA_setClockConfig(TIMER_Location_INST,
        (DL_TimerA_ClockConfig *) &gTIMER_LocationClockConfig);

    DL_TimerA_initTimerMode(TIMER_Location_INST,
        (DL_TimerA_TimerConfig *) &gTIMER_LocationTimerConfig);
    DL_TimerA_enableInterrupt(TIMER_Location_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(TIMER_Location_INST_INT_IRQN, 0);
    DL_TimerA_enableClock(TIMER_Location_INST);





}


SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /*
     * Initializes the SysTick period to 10.00 ms,
     * enables the interrupt, and starts the SysTick Timer
     */
    DL_SYSTICK_config(320000);
}

