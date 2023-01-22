//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_KNOBTASK_H
#define HELLOWORDKB_CTRL_KNOBTASK_H

#ifdef  __cplusplus
extern "C"
{
#endif

#include <Ctrl/Motor/knob.h>


extern KnobSimulator knob;         // 旋钮
extern Motor motor;
extern bool IsKnobTaskReady;

void Knob_Init();
void Knob_Task(void *arg);
void Knob_Start();


#ifdef  __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_KNOBTASK_H
