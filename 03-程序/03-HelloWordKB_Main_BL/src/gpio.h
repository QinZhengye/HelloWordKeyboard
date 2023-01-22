#ifndef __GPIO_HH__
#define __GPIO_HH__

#include <stdint.h>

#define RCC_APB2ENR  (*(volatile uint32_t*)0x40021018U)

#define rcc_gpio_enable(gpion) \
	RCC_APB2ENR |= (1 << (gpion + 2));

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOF 5

#define GPIO_CRL(x)  *((volatile uint32_t*)(x*0x400 +  0 + 0x40010800U))
#define GPIO_CRH(x)  *((volatile uint32_t*)(x*0x400 +  4 + 0x40010800U))
#define GPIO_IDR(x)  *((volatile uint32_t*)(x*0x400 +  8 + 0x40010800U))
#define GPIO_BSRR(x) *((volatile uint32_t*)(x*0x400 + 16 + 0x40010800U))

inline static void gpio_set_mode(uint32_t gpiodev, uint16_t gpion, uint8_t mode) {
	if (gpion < 8)
		GPIO_CRL(gpiodev) = (GPIO_CRL(gpiodev) & ~(0xf << ((gpion)<<2))) | (mode << ((gpion)<<2));
	else
		GPIO_CRH(gpiodev) = (GPIO_CRH(gpiodev) & ~(0xf << ((gpion-8)<<2))) | (mode << ((gpion-8)<<2));
}

#define gpio_set_output(a,b)    gpio_set_mode(a,b,0x2)
#define gpio_set_input(a,b)     gpio_set_mode(a,b,0x0)
#define gpio_set_input_pp(a,b)  gpio_set_mode(a,b,0x8)

#define gpio_clear(gpiodev, gpion) \
	GPIO_BSRR(gpiodev) = (1 << (16 + gpion))
#define gpio_set(gpiodev, gpion) \
	GPIO_BSRR(gpiodev) = (1 << (gpion))

#define gpio_read(gpiodev, gpion) \
	(GPIO_IDR(gpiodev) & (1 << (gpion)))

#if defined(ENABLE_GPIO_DFU_BOOT) && defined(GPIO_DFU_BOOT_CUSTOM)
int force_dfu_gpio();
#endif

#endif
