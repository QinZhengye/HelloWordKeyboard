//
// Created by QZY on 2022/11/20.
//

#ifndef HELLOWORDKB_CTRL_POWER_H
#define HELLOWORDKB_CTRL_POWER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void power_Init();
void power_Set5VEn(bool enable);
void power_Set12VEn(bool enable);

#ifdef __cplusplus
}   /*---------------------------- C++ Scope ---------------------------*/
#endif

#endif //HELLOWORDKB_CTRL_POWER_H
