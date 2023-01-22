//
// Created by QZY on 2022/12/12.
//
#include "stdio.h"
#include "AppEvent.h"


osEventFlagsId_t EventGlobal;


void AppEvent_Init()
{
    EventGlobal = osEventFlagsNew(NULL);
}

void AppEvent_GLB_Set(uint32_t evt)
{
    osEventFlagsSet(EventGlobal, evt);
}

// 不阻塞
bool AppEvent_GLB_Has(uint32_t evt)
{
    uint32_t retBits = osEventFlagsWait(EventGlobal, evt, osFlagsWaitAny, 0);
    if (retBits & 0x80000000)
        return false;
    return  ((retBits & evt) == evt);
}

void AppEvent_GLB_Clear(uint32_t evt)
{
    osEventFlagsClear(EventGlobal, evt);
}

void AppEvent_GLB_ClearAct()
{
    AppEvent_GLB_Clear(EVENT_GLB_KNOB_CW | EVENT_GLB_KNOB_CCW
                    | EVENT_GLB_KEY_KNOB | EVENT_GLB_KEY_01 | EVENT_GLB_KEY_02);
}
