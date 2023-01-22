//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_GUITASK_H
#define HELLOWORDKB_CTRL_GUITASK_H

#ifdef __cplusplus
extern "C" {
#endif


void GUI_Init();
void GUI_Task(void *arg);

void GUI_Setting_Next();
void GUI_Setting_Prev();
void GUI_Setting_Enter();


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //HELLOWORDKB_CTRL_GUITASK_H
