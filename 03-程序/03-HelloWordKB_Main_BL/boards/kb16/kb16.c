#include "gpio.h"

#define PIN_COL 14  // C0
#define PIN_ROW 8   // R3

int force_dfu_gpio() {
    rcc_gpio_enable(GPIOB);

    gpio_set_output(GPIOB, PIN_COL);
    gpio_set(GPIOB, PIN_COL);

    gpio_set_input_pp(GPIOB, PIN_ROW);
    gpio_clear(GPIOB, PIN_ROW);

    for (unsigned int i = 0; i < 512; i++)
        __asm__("nop");

    uint16_t val = gpio_read(GPIOB, PIN_ROW);

    // Reset all pins
    gpio_set_input(GPIOB, PIN_COL);
    gpio_set_input(GPIOB, PIN_ROW);

    return val;
}
