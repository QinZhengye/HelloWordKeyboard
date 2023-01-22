//
// Created by QZY on 2022/11/20.
//

#include "hardware.h"

void hardware_Init()
{
    power_Init();
    keypad_Init();
    mag_Init();
    rs485_Init();
}
