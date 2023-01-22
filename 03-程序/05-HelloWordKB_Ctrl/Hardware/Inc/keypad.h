//
// Created by Administrator on 2022/11/22.
//

#ifndef HELLOWORDKB_CTRL_KEYPAD_H
#define HELLOWORDKB_CTRL_KEYPAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void keypad_Init();
void keypad_Scan(uint8_t *keyBuff, uint16_t size);

#ifdef __cplusplus
}   /*---------------------------- C++ Scope ---------------------------*/
#endif

#endif //HELLOWORDKB_CTRL_KEYBOARD_H
