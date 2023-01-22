//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_LIGHTTASK_H
#define HELLOWORDKB_CTRL_LIGHTTASK_H

#ifdef __cplusplus
extern "C" {
#endif


#include "UserApp.h"


#define LIGHT_KEYPAD_LED_NUM    8
#define LIGHT_KNOB_LED_NUM      8
#define LIGHT_LED_NUM           (LIGHT_KEYPAD_LED_NUM + LIGHT_KNOB_LED_NUM)
#define LIGHT_RESET_SPACE_NUM   20


void Light_Init();
void Light_Task(void *arg);

void Light_SetEnable(bool enable);
void Light_SetPadEnable(bool enable);
void Light_SetKnobEnable(bool enable);

float Light_RGB2Angle(uint8_t r, uint8_t g, uint8_t b);
void Light_Angle2RGB(float angle, uint8_t *r, uint8_t *g, uint8_t *b);


extern bool isPadEnable;
extern bool isKnobEnable;
extern uint8_t Color_R;
extern uint8_t Color_G;
extern uint8_t Color_B;


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_LIGHTTASK_H
