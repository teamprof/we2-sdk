#include "WE2_core.h"
#include "board.h"
#include "xprintf.h"
#include "hx_drv_scu_export.h"
#include "hx_drv_scu.h"
 
static volatile uint32_t cm55m_s_timer_event_cnt = 0;
static volatile uint32_t cm55m_s_timer_event_flag = 0;

void timer_event(uint32_t event)
{
    cm55m_s_timer_event_cnt++;
    cm55m_s_timer_event_flag = 1;
}

int main(void) {
    uint32_t version1;
    uint32_t version2;
    board_init();

    TIMER_CFG_T cfg;
    cfg.period = 1000;
    cfg.mode = TIMER_MODE_PERIODICAL;
    cfg.ctrl = TIMER_CTRL_CPU;
    cfg.state = TIMER_STATE_DC;

    hx_drv_scu_set_PB0_pinmux(SCU_PB0_PINMUX_UART0_RX_1, 1);
    hx_drv_scu_set_PB1_pinmux(SCU_PB1_PINMUX_UART0_TX_1, 1);
    //hx_drv_scu_set_PB6_pinmux(SCU_PB6_PINMUX_UART1_RX);
    //hx_drv_scu_set_PB7_pinmux(SCU_PB7_PINMUX_UART1_TX);

    xprintf("core0 hello_word_s running ...\r\n");

    xprintf("call scu_get_version\r\n");
    SCU_ERROR_E ret1 = hx_drv_scu_get_version(&version1, &version2);
    xprintf("ret = 0x%08X, version1 = 0x%08X, version1 = 0x%08X\r\n", ret1, version1, version1);

    xprintf("call timer_cm55m_start\r\n");
    TIMER_ERROR_E ret2 = hx_drv_timer_cm55m_start(&cfg, timer_event);
    xprintf("ret = 0x%08X\r\n", ret2);

    SCU_ERROR_E cm55sRet;
    cm55sRet = hx_drv_scu_set_cm55s_state(SCU_CM55S_STATE_RESET);
    xprintf("hx_drv_scu_set_cm55s_state(SCU_CM55S_STATE_RESET) returns 0x%d\r\n", cm55sRet);

    cm55sRet = hx_drv_scu_set_cm55s_state(SCU_CM55S_STATE_NORMAL);
    xprintf("hx_drv_scu_set_cm55s_state(SCU_CM55S_STATE_NORMAL) returns 0x%d\r\n", cm55sRet);

    cm55sRet = hx_drv_scu_set_CM55S_CPUWAIT(SCU_CM55_CPU_RUN);
    xprintf("hx_drv_scu_set_CM55S_CPUWAIT(SCU_CM55_CPU_RUN) returns 0x%d\r\n", cm55sRet);
    

    while (1) {
      if (cm55m_s_timer_event_flag) {
          cm55m_s_timer_event_flag = 0;
          xprintf("cm55m_s_event_cnt = 0x%08X \r\n", cm55m_s_timer_event_cnt);
      }
    }

    for(;;) {}
}
