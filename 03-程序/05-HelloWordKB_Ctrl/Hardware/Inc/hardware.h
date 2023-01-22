//
// Created by QZY on 2022/11/20.
//

#ifndef HELLOWORDKB_CTRL_HARDWARE_H
#define HELLOWORDKB_CTRL_HARDWARE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "power.h"
#include "keypad.h"
#include "analog.h"
#include "mag.h"
#include "rs485.h"

// 互斥量
// SPI2
// SPI3
// UART1-Tx
// UART1-Rx
void hardware_Init();


#ifdef __cplusplus
}   /*---------------------------- C++ Scope ---------------------------*/
#endif

#endif //HELLOWORDKB_CTRL_HARDWARE_H
