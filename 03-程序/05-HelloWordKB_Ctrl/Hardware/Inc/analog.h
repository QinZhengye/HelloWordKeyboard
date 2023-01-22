//
// Created by Administrator on 2022/11/22.
//

#ifndef HELLOWORDKB_CTRL_ANALOG_H
#define HELLOWORDKB_CTRL_ANALOG_H

#include "main.h"

void analog_Init();
float analog_GetMotoCurrentA();
float analog_GetMotoCurrentC();
int16_t analog_GetBattery_mV();
int16_t analog_GetVBus_mV();

#endif //HELLOWORDKB_CTRL_ANALOG_H
