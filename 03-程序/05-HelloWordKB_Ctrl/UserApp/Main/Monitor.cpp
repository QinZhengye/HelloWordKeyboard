//
// Created by QZY on 2022/12/17.
//

#include "Monitor.h"
#include <stdio.h>
#include "cmsis_os2.h"
#include "KnobTask.h"
#include "UserApp.h"

#define MONITOR 0


void Monitor_Printf();
void Monitor_ShowThread();

void Monitor_Task(void *arg)
{
    uint16_t  cnt;
    while (!SystemReady)
        osDelay(10);

    while (1)
    {
#if (MONITOR)
        cnt++;

        if (cnt % 3 == 0)
        {
            Monitor_Printf();
        }
        if (cnt % 200 == 0)
        {
            Monitor_ShowThread();
        }
#endif
        osDelay(100);
    }
}

void Monitor_Printf()
{
    printf("knob:%d,motor=%d,Tag=%.2f,Pos=%.2f\r\n",
           knob.GetMode(),
           motor.config.controlMode,
           motor.target,
           knob.GetPosition());
}

#define THREAD_MAX_COUNT    12
osThreadId_t threadArray[THREAD_MAX_COUNT];

void Monitor_ShowThread()
{
    uint32_t realCount, idx;
    realCount = osThreadEnumerate(threadArray, THREAD_MAX_COUNT);

    printf("\r\n=============================\r\n");
    for (idx = 0; idx < realCount; idx++)
    {
        osThreadId_t id = threadArray[idx];
        uint32_t stackSpace = osThreadGetStackSpace(id);
        printf("%02d|%16s %6d\r\n",
               idx+1, osThreadGetName(id),
               stackSpace);
    }
}
