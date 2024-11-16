/*
 * pinmux_init.c
 *
 *  Created on: 2023�~9��8��
 *      Author: 902447
 */


#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "WE2_device.h"

#ifdef IP_scu
#include "hx_drv_scu.h"
#endif
#include "pinmux_init.h"

void __attribute__((weak)) pinmux_init()
{
	// uart1 pinmux
	hx_drv_scu_set_PB5_pinmux(SCU_PB5_PINMUX_UART1_TX, 1);
	hx_drv_scu_set_PB6_pinmux(SCU_PB6_PINMUX_UART1_RX, 1);
}
