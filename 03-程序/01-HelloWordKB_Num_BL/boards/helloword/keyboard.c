//
// Created by QZY on 2022/11/16.
//

#include "gpio.h"

#if defined(ENABLE_GPIO_DFU_BOOT) && defined(GPIO_DFU_BOOT_CUSTOM)

#define PL_GPIO_Port    GPIOB
#define PL_GPIO_Pin     0
#define CE_GPIO_Port    GPIOB
#define CE_GPIO_Pin     1
#define CP_GPIO_Port    GPIOA
#define CP_GPIO_Pin     5
#define DI_GPIO_Port    GPIOA
#define DI_GPIO_Pin     6


void DelayUs(uint32_t _us)
{
    for (int i = 0; i < _us; i++)
        for (int j = 0; j < 4; j++)
                __asm__("nop");
}

int force_dfu_gpio() {
    rcc_gpio_enable(GPIOA);
    rcc_gpio_enable(GPIOB);

    gpio_set_output(PL_GPIO_Port, PL_GPIO_Pin);
    gpio_set_output(CE_GPIO_Port, CE_GPIO_Pin);
    gpio_set_output(CP_GPIO_Port, CP_GPIO_Pin);
    gpio_set_input_pp(DI_GPIO_Port, DI_GPIO_Pin);

    // Enable
    gpio_clear(CE_GPIO_Port, CE_GPIO_Pin);
    // parallel load
    gpio_clear(PL_GPIO_Port, PL_GPIO_Pin);
    DelayUs(50);
    gpio_set(PL_GPIO_Port, PL_GPIO_Pin);
    DelayUs(50);

    for (unsigned int i = 0; i < 7; i++)
    {
        gpio_clear(CP_GPIO_Port, CP_GPIO_Pin);
        DelayUs(50);
        gpio_set(CP_GPIO_Port, CP_GPIO_Pin);
        DelayUs(50);
    }

    return (gpio_read(DI_GPIO_Port, DI_GPIO_Pin) == 0);
}

#endif
