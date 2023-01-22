//
// Created by QZY on 2022/11/20.
//

#include "power.h"

void power_Init()
{
    power_Set5VEn(true);
    power_Set12VEn(true);
}

void power_Set5VEn(bool enable)
{
    HAL_GPIO_WritePin(PWR5V_EN_GPIO_Port, PWR5V_EN_Pin, enable? GPIO_PIN_SET: GPIO_PIN_RESET);
}

void power_Set12VEn(bool enable)
{
    HAL_GPIO_WritePin(PWR12V_EN_GPIO_Port, PWR12V_EN_Pin, enable? GPIO_PIN_SET: GPIO_PIN_RESET);
}
