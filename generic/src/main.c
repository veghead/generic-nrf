
/** @file
 * @brief nRF52-DK talk to RAK4270 over UART
 */

#include <stdint.h>
#include "generic.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "bsp.h"


int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);
    
    uint8_t led = 0;
    // Main Loop (tm)
    while(true) {
        bsp_board_led_off(led);
        led = next_led(led);
        bsp_board_led_on(led);
        nrf_delay_ms(200);
    }
}


