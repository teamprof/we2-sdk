/*
 * board.c
 *
 *  Created on: 2021/02/03
 *      Author: 902447
 */

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "WE2_device.h"
#include "console_io.h"
#include "xprintf.h"
#if defined (__ARM_FEATURE_CMSE) &&  (__ARM_FEATURE_CMSE == 3U)
#include "trustzone_cfg.h"
   #include "trustzone_cfg.h"
#endif
#ifdef IP_2x2
#include "hx_drv_hw2x2.h"
#endif
#ifdef IP_5x5
#include "hx_drv_hw5x5.h"
#endif
#ifdef IP_cdm
#include "hx_drv_cdm.h"
#endif
#ifdef IP_csirx
#include "hx_drv_csirx.h"
#endif
#ifdef IP_csitx
#include "hx_drv_csitx.h"
#endif
#ifdef IP_dp
#include "hx_drv_dp.h"
#endif
#ifdef IP_edm
#include "hx_drv_edm.h"
#endif
#ifdef IP_hxautoi2c_mst
#include "hx_drv_hxautoi2c_mst.h"
#endif
#ifdef IP_inp
#include "hx_drv_inp.h"
#endif
#ifdef IP_inp1bitparser
#include "hx_drv_inp1bitparser.h"
#endif
#ifdef IP_inpovparser
#include "hx_drv_inpovparser.h"
#endif
#ifdef IP_jpeg
#include "hx_drv_jpeg.h"
#endif
#ifdef IP_sensorctrl
#include "hx_drv_sensorctrl.h"
#endif
#ifdef IP_tpg
#include "hx_drv_tpg.h"
#endif
#ifdef IP_xdma
#include "hx_drv_xdma.h"
#endif
#ifdef IP_uart
#include"hx_drv_uart.h"
#endif
#ifdef IP_mb
#include "hx_drv_mb.h"
#endif
#ifdef IP_scu
#include "hx_drv_scu.h"
#endif
#ifdef IP_timer
#include "hx_drv_timer.h"
#endif
#ifdef IP_rtc
#include "hx_drv_rtc.h"
#endif
#ifdef IP_watchdog
#include "hx_drv_watchdog.h"
#endif
#ifdef IP_iic
#include"hx_drv_iic.h"
#endif
#ifdef IP_gpio
#include"hx_drv_gpio.h"
#endif
#ifdef IP_spi
#include"hx_drv_spi.h"
#endif
#ifdef IP_pwm
#include"hx_drv_pwm.h"
#endif
#ifdef IP_i3c_slv
#include"hx_drv_i3c_slv.h"
#endif
#ifdef IP_dma
#include "hx_drv_dmac.h"
#endif
#if defined(RTE_CMSIS_RTOS2)
#if defined(RTE_CMSIS_RTOS2_FreeRTOS)
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "FreeRTOSConfig.h"
#endif
#if defined(RTE_CMSIS_RTOS2_RTX5)
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "RTX_Config.h"
#endif
#endif
#ifdef IP_timer
#include "timer_interface.h"
#endif

#if defined(__GNU__) && defined(SEMIHOST)
extern void initialise_monitor_handles(void);
#endif

int board_init() {
	/*TODO driver init*/
	uint32_t freq;

// #ifdef IC_PACKAGE_WLCSP65
// 	hx_drv_scu_set_PB6_pinmux(SCU_PB6_PINMUX_UART1_RX, 1);
// 	hx_drv_scu_set_PB7_pinmux(SCU_PB7_PINMUX_UART1_TX, 1);
// #endif
// #ifdef IC_PACKAGE_LQFP128
// 	hx_drv_scu_set_UART_RX_TX_CTS_RTS_pinmux(SCU_UART_PINMUX_UART1);
// #endif
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#ifdef TRUSTZONE_SEC_ONLY
    TZ_Set_ALL_Secure();
#else
    TZ_Set_Secure_ByCFG();
#endif
#endif

// #if defined(__GNU__) && defined(SEMIHOST)
// 	initialise_monitor_handles();
// #endif


// #ifdef IP_scu
// 	hx_drv_scu_init();
// #endif
	hx_drv_scu_get_freq(SCU_CLK_FREQ_TYPE_LSC_CM55S, &freq);
	SystemCoreClockUpdate(freq);

// #ifdef IP_dma
// #if defined(IP_INST_DMA0) || defined(IP_INST_NS_DMA0)
//     hx_drv_dmac_init(USE_HX_DMAC_0, DMAC0_BASE);
// #endif
// #if defined(IP_INST_DMA1) || defined(IP_INST_NS_DMA1)
//     hx_drv_dmac_init(USE_HX_DMAC_1, DMAC1_BASE);
// #endif
// #if defined(IP_INST_DMA2) || defined(IP_INST_NS_DMA2)
//     hx_drv_dmac_init(USE_HX_DMAC_2, DMAC2_BASE);
// #endif
// #if defined(IP_INST_DMA3) || defined(IP_INST_NS_DMA3)
//     hx_drv_dmac_init(USE_HX_DMAC_3, DMAC3_BASE);
// #endif
// #endif
// #ifdef IP_timer
// #if defined(IP_INST_TIMER0) || defined(IP_INST_NS_TIMER0)
// 	hx_drv_timer_init(TIMER_ID_0, HX_TIMER0_BASE);
// #endif
// #if defined(IP_INST_TIMER1) || defined(IP_INST_NS_TIMER1)
// 	hx_drv_timer_init(TIMER_ID_1, HX_TIMER1_BASE);
// #endif
// #if defined(IP_INST_TIMER2) || defined(IP_INST_NS_TIMER2)
// 	hx_drv_timer_init(TIMER_ID_2, HX_TIMER2_BASE);
// #endif
// #if defined(IP_INST_TIMER3) || defined(IP_INST_NS_TIMER3)
// 	hx_drv_timer_init(TIMER_ID_3, HX_TIMER3_BASE);
// #endif
// #if defined(IP_INST_TIMER4) || defined(IP_INST_NS_TIMER4)
// 	hx_drv_timer_init(TIMER_ID_4, HX_TIMER4_BASE);
// #endif
// #if defined(IP_INST_TIMER5) || defined(IP_INST_NS_TIMER5)
// 	hx_drv_timer_init(TIMER_ID_5, HX_TIMER5_BASE);
// #endif
// #if defined(IP_INST_TIMER6) || defined(IP_INST_NS_TIMER6)
// 	hx_drv_timer_init(TIMER_ID_6, HX_TIMER6_BASE);
// #endif
// #if defined(IP_INST_TIMER7) || defined(IP_INST_NS_TIMER7)
// 	hx_drv_timer_init(TIMER_ID_7, HX_TIMER7_BASE);
// #endif
// #if defined(IP_INST_TIMER8) || defined(IP_INST_NS_TIMER8)
// 	hx_drv_timer_init(TIMER_ID_8, HX_TIMER8_BASE);
// #endif
// #endif
// #ifdef IP_watchdog
// #if defined(IP_INST_WDT0) || defined(IP_INST_NS_WDT0)
// 	hx_drv_watchdog_init(WATCHDOG_ID_0, HX_WDG0_BASE);
// #endif
// #if defined(IP_INST_WDT1) || defined(IP_INST_NS_WDT1)
// 	hx_drv_watchdog_init(WATCHDOG_ID_1, HX_WDG1_BASE);
// #endif
// #endif
// #ifdef IP_rtc
// #if defined(IP_INST_RTC0) || defined(IP_INST_NS_RTC0)
// 	hx_drv_rtc_init(RTC_ID_0, HX_RTC0_BASE);
// #endif
// #if defined(IP_INST_RTC1) || defined(IP_INST_NS_RTC1)
// 	hx_drv_rtc_init(RTC_ID_1, HX_RTC1_BASE);
// #endif
// #if defined(IP_INST_RTC2) || defined(IP_INST_NS_RTC2)
// 	hx_drv_rtc_init(RTC_ID_2, HX_RTC2_BASE);
// #endif
// #endif
// #ifdef IP_2x2
// 	hx_drv_hw2x2_init(HW_2X2_BASEADDR);
// #endif
// #ifdef IP_5x5
// 	hx_drv_hw5x5_init(HW_5X5_BASEADDR);
// #endif
// #ifdef IP_cdm
// 	hx_drv_cdm_init(HW_CDM_BASEADDR);
// #endif
// #ifdef IP_csirx
// 	hx_drv_csirx_init(CSIRX_REGS_BASE, CSIRX_DPHY_REG_BASE);
// #endif
// #ifdef IP_csitx
// 	hx_drv_csitx_init(CSITX_REGS_BASE, CSITX_DPHY_REG);
// #endif
// #ifdef IP_dp
// 	hx_drv_dp_init(HW_DP_BASEADDR, HW_DP_HSC_BASEADDR, HW_HXRGB2YUV_BASEADDR, HW_HXCSC_BASEADDR);
// #endif
// #ifdef IP_edm
// 	hx_drv_edm_init_regbase(HW_EDM_BASEADDR, HW_EDM_HSC_BASEADDR);
// #endif
// #ifdef IP_hxautoi2c_mst
// 	hx_drv_hxautoi2c_init(HW_HXAUTOI2C_BASE_ADDR);
// #endif
// #ifdef IP_inp
// 	hx_drv_inp_init(HW_INP_BASEADDR, HW_INP_HSC_BASEADDR);
// #endif
// #ifdef IP_inp1bitparser
// 	hx_drv_inp1bitparser_init(HW_INP1BITPARSER_BASEADDR, HW_INP1BITPARSER_LSC_BASEADDR);
// #endif
// #ifdef IP_inpovparser
// 	hx_drv_inpovparser_init(HW_INPOVPARSER_BASEADDR, HW_INPOVPARSER_LSC_BASEADDR);
// #endif
// #ifdef IP_jpeg
// 	hx_drv_jpeg_init(HW_JPEG_BASEADDR, HW_JPEG_HSC_BASEADDR);
// #endif
// #ifdef IP_sensorctrl
// 	hx_drv_sensorctrl_init(HW_SENSORCTRL_BASEADDR, HW_SENSORCTRL_LSC_BASEADDR);
// #endif
// #ifdef IP_tpg
// 	hx_drv_tpg_init_reg_addr(HW_TPG_BASEADDR);
// #endif
// #ifdef IP_xdma
// 	hx_drv_xdma_init(HW_XDMA_BASEADDR, HW_XDMA_HSC_BASEADDR);
// #endif
// #ifdef IP_mb
// 	hx_drv_mb_init(MB_CORE_CM55S, HX_MAILBOX_INT_BASE);
// #endif
// #ifdef IP_uart
// 	#if defined(IP_INST_UART0) || defined(IP_INST_NS_UART0)
// 	hx_drv_uart_init(USE_DW_UART_0, HX_UART0_BASE);
// 	#endif
// 	#if defined(IP_INST_UART1) || defined(IP_INST_NS_UART1)
// 	hx_drv_uart_init(USE_DW_UART_1, HX_UART1_BASE);
// 	#endif
// 	#if defined(IP_INST_UART2) || defined(IP_INST_NS_UART2)
// 	hx_drv_uart_init(USE_DW_UART_2, HX_UART2_BASE);
// 	#endif
// #endif
// #ifdef IP_gpio
// 	#if defined(IP_INST_GPIO_G0) || defined(IP_INST_NS_GPIO_G0)
// 	hx_drv_gpio_init(GPIO_GROUP_0, HX_GPIO_GROUP_0_BASE);
// 	#endif
// 	#if defined(IP_INST_GPIO_G1) || defined(IP_INST_NS_GPIO_G1)
// 	hx_drv_gpio_init(GPIO_GROUP_1, HX_GPIO_GROUP_1_BASE);
// 	#endif
// 	#if defined(IP_INST_GPIO_G2) || defined(IP_INST_NS_GPIO_G2)
// 	hx_drv_gpio_init(GPIO_GROUP_2, HX_GPIO_GROUP_2_BASE);
// 	#endif
// 	#if defined(IP_INST_GPIO_G3) || defined(IP_INST_NS_GPIO_G3)
// 	hx_drv_gpio_init(GPIO_GROUP_3, HX_GPIO_GROUP_3_BASE);
// 	#endif
// 	#if defined(IP_INST_SB_GPIO) || defined(IP_INST_NS_SB_GPIO)
// 	hx_drv_gpio_init(GPIO_GROUP_4, HX_GPIO_GROUP_4_BASE);
// 	#endif
// 	#if defined(IP_INST_AON_GPIO) || defined(IP_INST_NS_AON_GPIO)
// 	hx_drv_gpio_init(GPIO_GROUP_5, HX_GPIO_GROUP_5_BASE);
// 	#endif
// #endif
// #ifdef IP_iic
// 	#ifndef BOOT_USED
// 	#if defined(IP_INST_IIC_HOST) || defined(IP_INST_NS_IIC_HOST)
// 	hx_drv_i2cm_init(USE_DW_IIC_0, HX_I2C_HOST_MST_0_BASE, DW_IIC_SPEED_FAST);
// 	#endif
// 	#if defined(IP_INST_IIC_HOST_SENSOR) || defined(IP_INST_NS_IIC_HOST_SENSOR)
// 	hx_drv_i2cm_init(USE_DW_IIC_1, HX_I2C_HOST_MST_1_BASE, DW_IIC_SPEED_FAST);
// 	#endif
// 	#endif
// 	#if defined(IP_INST_IIC_SLAVE0) || defined(IP_INST_NS_IIC_SLAVE0)
// 	hx_drv_i2cs_init(USE_DW_IIC_SLV_0, HX_I2C_HOST_SLV_0_BASE);
// 	#endif
// 	#if defined(IP_INST_IIC_SLAVE1) || defined(IP_INST_NS_IIC_SLAVE1)
// 	hx_drv_i2cs_init(USE_DW_IIC_SLV_1, HX_I2C_HOST_SLV_1_BASE);
// 	#endif
// #endif
// #ifdef IP_spi
//     #if defined(IP_INST_NS_QSPI_HOST)
//     #error "IP_INST_NS_QSPI_HOST is not Supported"
//     #endif
//     #if defined(IP_INST_NS_OSPI_HOST)
//     #error "IP_INST_NS_QSPI_HOST is not Supported"
//     #endif
//     #if defined(IP_INST_QSPI_HOST)
//     #error "IP_INST_QSPI_HOST is not Supported"
//     #endif
//     #if defined(IP_INST_SSPI_HOST) || defined(IP_INST_NS_SSPI_HOST)
//     hx_drv_spi_mst_init(USE_DW_SPI_MST_S, DW_SPI_S_RELBASE);
//     #endif
//     #if defined(IP_INST_OSPI_HOST)
//     #error "IP_INST_OSPI_HOST is not Supported"
//     #endif
// #endif
// #ifdef IP_pwm
// 	#if defined(IP_INST_PWM0) || defined(IP_INST_NS_PWM0)
// 	hx_drv_pwm_init(PWM0, HW_PWM0_BASEADDR);
// 	#endif	
// 	#if defined(IP_INST_PWM1) || defined(IP_INST_NS_PWM1)
// 	hx_drv_pwm_init(PWM1, HW_PWM1_BASEADDR);
// 	#endif	
// 	#if defined(IP_INST_PWM2) || defined(IP_INST_NS_PWM2)
// 	hx_drv_pwm_init(PWM2, HW_PWM2_BASEADDR);
// 	#endif	
// #endif
#ifdef LIB_COMMON
	xprintf_setup();
#endif

xprintf("hello 100\r\n");

	return 0;
}


int board_deinit()
{
#ifdef LIB_COMMON
	xprintf_desetup();
#endif

	/*TODO Driver deinit*/

	return 0;
}

int board_delay_ms(uint32_t ms)
{
// #ifdef FREERTOS_SECONLY
// 	vTaskDelay(pdMS_TO_TICKS(ms));
// 	return TIMER_NO_ERROR;
// #endif
// #ifdef FREERTOS_NS
// 	vTaskDelay(pdMS_TO_TICKS(ms));
// 	return 0;
// #endif
// #if defined(RTE_CMSIS_RTOS2)
// #if defined(RTE_CMSIS_RTOS2_FreeRTOS)
// 	osDelay((ms * configTICK_RATE_HZ) / 1000);
// 	return 0;
// #endif
// #if defined(RTE_CMSIS_RTOS2_RTX5)
// 	osDelay((ms * OS_TICK_FREQ) / 1000);
// 	return 0;
// #endif
// #endif
// #ifdef IP_timer
// 	if(hx_drv_timer_cm55x_delay_ms(ms, TIMER_STATE_DC) == TIMER_NO_ERROR)
// 	{
// 		return 0;
// 	}else{
// 		return -1;
// 	}
// #endif
	return -1;
}



// /*
//  * board.c
//  *
//  *  Created on: 2021/02/03
//  *      Author: 902447
//  */

// #include <string.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include "WE2_device.h"
// #include "console_io.h"
// #ifdef LIB_COMMON
// #include "xprintf.h"
// #endif
// #include "pinmux_init.h"
// #include "platform_driver_init.h"
// #ifdef IP_timer
// #include "hx_drv_timer.h"
// #endif
// #if defined(FREERTOS_SECONLY) || defined(FREERTOS_NS) || defined(RTE_RTOS_FreeRTOS_CORE)
// /* FreeRTOS kernel includes. */
// #include "FreeRTOS.h"
// #include "task.h"
// #include "queue.h"
// #include "timers.h"
// #if defined(FREERTOS_OSHAL) 
// #include "cmsis_os2.h"
// #endif
// #endif
// #if defined(RTE_CMSIS_RTOS2)
// #if defined(RTE_CMSIS_RTOS2_FreeRTOS)
// #include "cmsis_os2.h"                  // ::CMSIS:RTOS2
// #include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
// #include "FreeRTOSConfig.h"
// #endif
// #if defined(RTE_CMSIS_RTOS2_RTX5)
// #include "cmsis_os2.h"                  // ::CMSIS:RTOS2
// #include "RTX_Config.h"
// #endif
// #endif
// #if defined(RTOS2_RTX_SECONLY) || defined(RTOS2_RTX_NS)
// #include "cmsis_os2.h"
// #include "RTX_Config.h"
// #endif
// #if defined(RTOS2_FREERTOS_SECONLY) || defined(RTOS2_FREERTOS_NS)
// #include "cmsis_os2.h"
// #include "FreeRTOS.h"
// #include "FreeRTOSConfig.h"
// #endif
// #ifdef IP_timer
// #include "timer_interface.h"
// #endif

// int board_init() {
// 	/*set pinmux init*/
// 	pinmux_init();
// 	/*platform driver init*/
// 	platform_driver_init();
// #ifdef IP_uart
// 	console_setup(DW_UART_1_ID, UART_BAUDRATE_115200);
// #endif
// #ifdef LIB_COMMON
// 	xprintf_setup();
// #endif

// 	return 0;
// }


// int board_deinit()
// {
// #ifdef IP_uart
// 	console_desetup(DW_UART_1_ID);
// #endif
// #ifdef LIB_COMMON
// 	xprintf_desetup();
// #endif
// 	/*TODO Driver deinit*/

// 	return 0;
// }

// int board_delay_ms(uint32_t ms)
// {
// #if !defined(RTE_CMSIS_RTOS2)
// #if defined(FREERTOS_SECONLY) || defined(FREERTOS_NS) || defined(RTE_RTOS_FreeRTOS_CORE)
// #if !defined(FREERTOS_OSHAL) 
//     if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING) {
//         vTaskDelay(pdMS_TO_TICKS(ms));
//         return 0;
//     }
// #else
//     if (osKernelGetState() == osKernelRunning) {
//         osDelay((ms * configTICK_RATE_HZ) / 1000);
//         return 0;
//     }
// #endif
// #endif
// #if defined(RTOS2_FREERTOS_SECONLY) || defined(RTOS2_FREERTOS_NS)
//     if (osKernelGetState() == osKernelRunning) {
//         osDelay((ms * configTICK_RATE_HZ) / 1000);
//         return 0;
//     }
// #endif
// #if defined(RTOS2_RTX_SECONLY) || defined(RTOS2_RTX_NS)
//     if (osKernelGetState() == osKernelRunning) {
//         osDelay((ms * OS_TICK_FREQ) / 1000);
//         return 0;
//     }
// #endif
// #elif defined(RTE_CMSIS_RTOS2)
// #if defined(RTE_CMSIS_RTOS2_FreeRTOS)
//     if (osKernelGetState() == osKernelRunning) {
//         osDelay((ms * configTICK_RATE_HZ) / 1000);
//         return 0;
//     }
// #endif
// #if defined(RTE_CMSIS_RTOS2_RTX5)
//     if (osKernelGetState() == osKernelRunning) {
//         osDelay((ms * OS_TICK_FREQ) / 1000);
//         return 0;
//     }
// #endif
// #endif
// #ifdef IP_timer
// 	if(hx_drv_timer_cm55x_delay_ms(ms, TIMER_STATE_DC) == TIMER_NO_ERROR)
// 	{
// 		return 0;
// 	}else{
// 		return -1;
// 	}
// #endif
// 	return -1;
// }
