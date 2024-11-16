#include "WE2_core.h"
#include "board.h"
#include "xprintf.h"
#include "hx_drv_scu_export.h"
#include "hx_drv_scu.h"

static volatile uint32_t cm55s_s_timer_event_cnt = 0;
static volatile uint32_t cm55s_s_timer_event_flag = 0;

void timer_event(uint32_t event)
{
    cm55s_s_timer_event_cnt++;
    cm55s_s_timer_event_flag = 1;
}


int main(void) {
    uint32_t version1;
    uint32_t version2;
    TIMER_CFG_T cfg;

    board_init();
    cfg.period = 1000;
    cfg.mode = TIMER_MODE_PERIODICAL;
    cfg.ctrl = TIMER_CTRL_CPU;
    cfg.state = TIMER_STATE_DC;

    xprintf("core1 hello_word_s running ...\r\n");

    xprintf("call scu_get_version\r\n");
    SCU_ERROR_E ret1 = hx_drv_scu_get_version(&version1, &version2);
    xprintf("ret = 0x%08X, version1 = 0x%08X, version1 = 0x%08X\r\n", ret1, version1, version1);

    // xprintf("call timer_cm55s_start\r\n");
    // TIMER_ERROR_E ret2 = hx_drv_timer_cm55s_start(&cfg, timer_event);
    // xprintf("ret = 0x%08X\r\n", ret2);

    while (1) {
      if (cm55s_s_timer_event_flag) {
          cm55s_s_timer_event_flag = 0;
        //   xprintf("cm55s_s_event_cnt = 0x%08X \r\n", cm55s_s_timer_event_cnt);
      }
    }

    for(;;) {}
}
