/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_Motor */
#define PWM_Motor_INST                                                     TIMG0
#define PWM_Motor_INST_IRQHandler                               TIMG0_IRQHandler
#define PWM_Motor_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define PWM_Motor_INST_CLK_FREQ                                          1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Motor_C0_PORT                                             GPIOA
#define GPIO_PWM_Motor_C0_PIN                                     DL_GPIO_PIN_12
#define GPIO_PWM_Motor_C0_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_PWM_Motor_C0_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_PWM_Motor_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_Motor_C1_PORT                                             GPIOA
#define GPIO_PWM_Motor_C1_PIN                                     DL_GPIO_PIN_13
#define GPIO_PWM_Motor_C1_IOMUX                                  (IOMUX_PINCM35)
#define GPIO_PWM_Motor_C1_IOMUX_FUNC                 IOMUX_PINCM35_PF_TIMG0_CCP1
#define GPIO_PWM_Motor_C1_IDX                                DL_TIMER_CC_1_INDEX

/* Defines for PWM_Beep */
#define PWM_Beep_INST                                                      TIMG6
#define PWM_Beep_INST_IRQHandler                                TIMG6_IRQHandler
#define PWM_Beep_INST_INT_IRQN                                  (TIMG6_INT_IRQn)
#define PWM_Beep_INST_CLK_FREQ                                            160000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Beep_C0_PORT                                              GPIOA
#define GPIO_PWM_Beep_C0_PIN                                      DL_GPIO_PIN_21
#define GPIO_PWM_Beep_C0_IOMUX                                   (IOMUX_PINCM46)
#define GPIO_PWM_Beep_C0_IOMUX_FUNC                  IOMUX_PINCM46_PF_TIMG6_CCP0
#define GPIO_PWM_Beep_C0_IDX                                 DL_TIMER_CC_0_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (2499U)
/* Defines for TIMER_Encoder */
#define TIMER_Encoder_INST                                               (TIMG7)
#define TIMER_Encoder_INST_IRQHandler                           TIMG7_IRQHandler
#define TIMER_Encoder_INST_INT_IRQN                             (TIMG7_INT_IRQn)
#define TIMER_Encoder_INST_LOAD_VALUE                                   (12499U)
/* Defines for TIMER_Location */
#define TIMER_Location_INST                                              (TIMA1)
#define TIMER_Location_INST_IRQHandler                          TIMA1_IRQHandler
#define TIMER_Location_INST_INT_IRQN                            (TIMA1_INT_IRQn)
#define TIMER_Location_INST_LOAD_VALUE                                   (3749U)




/* Defines for PIN_0: GPIOA.2 with pinCMx 7 on package pin 8 */
#define GPIO_Line_patrol_PIN_0_PORT                                      (GPIOA)
#define GPIO_Line_patrol_PIN_0_PIN                               (DL_GPIO_PIN_2)
#define GPIO_Line_patrol_PIN_0_IOMUX                              (IOMUX_PINCM7)
/* Defines for PIN_1: GPIOB.24 with pinCMx 52 on package pin 42 */
#define GPIO_Line_patrol_PIN_1_PORT                                      (GPIOB)
#define GPIO_Line_patrol_PIN_1_PIN                              (DL_GPIO_PIN_24)
#define GPIO_Line_patrol_PIN_1_IOMUX                             (IOMUX_PINCM52)
/* Defines for PIN_2: GPIOB.20 with pinCMx 48 on package pin 41 */
#define GPIO_Line_patrol_PIN_2_PORT                                      (GPIOB)
#define GPIO_Line_patrol_PIN_2_PIN                              (DL_GPIO_PIN_20)
#define GPIO_Line_patrol_PIN_2_IOMUX                             (IOMUX_PINCM48)
/* Defines for PIN_3: GPIOB.19 with pinCMx 45 on package pin 38 */
#define GPIO_Line_patrol_PIN_3_PORT                                      (GPIOB)
#define GPIO_Line_patrol_PIN_3_PIN                              (DL_GPIO_PIN_19)
#define GPIO_Line_patrol_PIN_3_IOMUX                             (IOMUX_PINCM45)
/* Defines for PIN_4: GPIOB.18 with pinCMx 44 on package pin 37 */
#define GPIO_Line_patrol_PIN_4_PORT                                      (GPIOB)
#define GPIO_Line_patrol_PIN_4_PIN                              (DL_GPIO_PIN_18)
#define GPIO_Line_patrol_PIN_4_IOMUX                             (IOMUX_PINCM44)
/* Defines for PIN_5: GPIOA.7 with pinCMx 14 on package pin 13 */
#define GPIO_Line_patrol_PIN_5_PORT                                      (GPIOA)
#define GPIO_Line_patrol_PIN_5_PIN                               (DL_GPIO_PIN_7)
#define GPIO_Line_patrol_PIN_5_IOMUX                             (IOMUX_PINCM14)
/* Defines for m_A_IN_1: GPIOA.8 with pinCMx 19 on package pin 16 */
#define GPIO_Motor_dir_m_A_IN_1_PORT                                     (GPIOA)
#define GPIO_Motor_dir_m_A_IN_1_PIN                              (DL_GPIO_PIN_8)
#define GPIO_Motor_dir_m_A_IN_1_IOMUX                            (IOMUX_PINCM19)
/* Defines for m_A_IN_2: GPIOA.9 with pinCMx 20 on package pin 17 */
#define GPIO_Motor_dir_m_A_IN_2_PORT                                     (GPIOA)
#define GPIO_Motor_dir_m_A_IN_2_PIN                              (DL_GPIO_PIN_9)
#define GPIO_Motor_dir_m_A_IN_2_IOMUX                            (IOMUX_PINCM20)
/* Defines for m_B_IN_1: GPIOB.3 with pinCMx 16 on package pin 15 */
#define GPIO_Motor_dir_m_B_IN_1_PORT                                     (GPIOB)
#define GPIO_Motor_dir_m_B_IN_1_PIN                              (DL_GPIO_PIN_3)
#define GPIO_Motor_dir_m_B_IN_1_IOMUX                            (IOMUX_PINCM16)
/* Defines for m_B_IN_2: GPIOB.2 with pinCMx 15 on package pin 14 */
#define GPIO_Motor_dir_m_B_IN_2_PORT                                     (GPIOB)
#define GPIO_Motor_dir_m_B_IN_2_PIN                              (DL_GPIO_PIN_2)
#define GPIO_Motor_dir_m_B_IN_2_IOMUX                            (IOMUX_PINCM15)
/* Defines for enable: GPIOB.6 with pinCMx 23 on package pin 20 */
#define GPIO_Motor_dir_enable_PORT                                       (GPIOB)
#define GPIO_Motor_dir_enable_PIN                                (DL_GPIO_PIN_6)
#define GPIO_Motor_dir_enable_IOMUX                              (IOMUX_PINCM23)
/* Port definition for Pin Group GPIO_Encoder */
#define GPIO_Encoder_PORT                                                (GPIOA)

/* Defines for m_A_en_1: GPIOA.0 with pinCMx 1 on package pin 1 */
// pins affected by this interrupt request:["m_A_en_1","m_A_en_2","m_B_en_1","m_B_en_2"]
#define GPIO_Encoder_INT_IRQN                                   (GPIOA_INT_IRQn)
#define GPIO_Encoder_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_Encoder_m_A_en_1_IIDX                           (DL_GPIO_IIDX_DIO0)
#define GPIO_Encoder_m_A_en_1_PIN                                (DL_GPIO_PIN_0)
#define GPIO_Encoder_m_A_en_1_IOMUX                               (IOMUX_PINCM1)
/* Defines for m_A_en_2: GPIOA.28 with pinCMx 3 on package pin 3 */
#define GPIO_Encoder_m_A_en_2_IIDX                          (DL_GPIO_IIDX_DIO28)
#define GPIO_Encoder_m_A_en_2_PIN                               (DL_GPIO_PIN_28)
#define GPIO_Encoder_m_A_en_2_IOMUX                               (IOMUX_PINCM3)
/* Defines for m_B_en_1: GPIOA.1 with pinCMx 2 on package pin 2 */
#define GPIO_Encoder_m_B_en_1_IIDX                           (DL_GPIO_IIDX_DIO1)
#define GPIO_Encoder_m_B_en_1_PIN                                (DL_GPIO_PIN_1)
#define GPIO_Encoder_m_B_en_1_IOMUX                               (IOMUX_PINCM2)
/* Defines for m_B_en_2: GPIOA.31 with pinCMx 6 on package pin 5 */
#define GPIO_Encoder_m_B_en_2_IIDX                          (DL_GPIO_IIDX_DIO31)
#define GPIO_Encoder_m_B_en_2_PIN                               (DL_GPIO_PIN_31)
#define GPIO_Encoder_m_B_en_2_IOMUX                               (IOMUX_PINCM6)
/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOA)

/* Defines for led: GPIOA.14 with pinCMx 36 on package pin 29 */
#define GPIO_LED_led_PIN                                        (DL_GPIO_PIN_14)
#define GPIO_LED_led_IOMUX                                       (IOMUX_PINCM36)
/* Defines for led2: GPIOA.27 with pinCMx 60 on package pin 47 */
#define GPIO_LED_led2_PIN                                       (DL_GPIO_PIN_27)
#define GPIO_LED_led2_IOMUX                                      (IOMUX_PINCM60)
/* Port definition for Pin Group GPIO_Mode */
#define GPIO_Mode_PORT                                                   (GPIOA)

/* Defines for mode1: GPIOA.25 with pinCMx 55 on package pin 45 */
#define GPIO_Mode_mode1_PIN                                     (DL_GPIO_PIN_25)
#define GPIO_Mode_mode1_IOMUX                                    (IOMUX_PINCM55)
/* Defines for mode2: GPIOA.26 with pinCMx 59 on package pin 46 */
#define GPIO_Mode_mode2_PIN                                     (DL_GPIO_PIN_26)
#define GPIO_Mode_mode2_IOMUX                                    (IOMUX_PINCM59)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_Motor_init(void);
void SYSCFG_DL_PWM_Beep_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_Encoder_init(void);
void SYSCFG_DL_TIMER_Location_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
