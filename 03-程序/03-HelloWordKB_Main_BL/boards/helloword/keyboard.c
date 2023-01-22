//
// Created by QZY on 2022/11/18.
//

#include "gpio.h"

#if defined(ENABLE_GPIO_DFU_BOOT) && defined(GPIO_DFU_BOOT_CUSTOM)

void DelayUs(uint32_t _us)
{
    for (int i = 0; i < _us; i++)
        for (int j = 0; j < 4; j++)
                __asm__("nop");
}

int force_dfu_gpio() {
    rcc_gpio_enable(GPIO_DFU_BOOT_PORT);
    gpio_set_input_pp(GPIO_DFU_BOOT_PORT, GPIO_DFU_BOOT_PIN);
    DelayUs(100);
    return (gpio_read(GPIO_DFU_BOOT_PORT, GPIO_DFU_BOOT_PIN) == GPIO_DFU_BOOT_VAL);
}

#endif

