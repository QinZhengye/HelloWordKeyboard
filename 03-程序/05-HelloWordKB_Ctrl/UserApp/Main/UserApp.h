//
// Created by QZY on 2022/11/20.
//

#ifndef HELLOWORDKB_CTRL_USERAPP_H
#define HELLOWORDKB_CTRL_USERAPP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os2.h"
#include "cmsis_os.h"
#include "AppEvent.h"


extern osSemaphoreId semSPI3;
extern bool SystemReady;


void UserMain();


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_USERAPP_H
