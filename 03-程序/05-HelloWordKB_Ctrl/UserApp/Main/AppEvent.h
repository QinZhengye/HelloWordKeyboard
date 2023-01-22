//
// Created by QZY on 2022/12/12.
//

#ifndef HELLOWORDKB_CTRL_APPEVENT_H
#define HELLOWORDKB_CTRL_APPEVENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os2.h"
#include "cmsis_os.h"

#define EVENT_GLB_WORKMODE_CHG      (1L << 0)
#define EVENT_GLB_PAGE_CHG          (1L << 1)
#define EVENT_GLB_CLOCK_SEC         (1L << 2)
#define EVENT_GLB_CLOCK_DAY         (1L << 3)
#define EVENT_GLB_KNOB_CW           (1L << 4)
#define EVENT_GLB_KNOB_CCW          (1L << 5)
#define EVENT_GLB_STOCK_UPDATE      (1L << 6)
#define EVENT_GLB_VOLUME_CHG        (1L << 7)
#define EVENT_GLB_LAYER_CHG         (1L << 8)
#define EVENT_GLB_KEY_KNOB          (1L << 9)
#define EVENT_GLB_KEY_01            (1L << 10)
#define EVENT_GLB_KEY_02            (1L << 11)
#define EVENT_GLB_LIGHT_SET         (1L << 12)


void AppEvent_Init();
void AppEvent_GLB_Set(uint32_t evt);
bool AppEvent_GLB_Has(uint32_t evt);
void AppEvent_GLB_Clear(uint32_t evt);
void AppEvent_GLB_ClearAct();


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_APPEVENT_H
