//
// Created by QZY on 2022/12/11.
//

#include "Clock.h"

CClock lock;


void Clock_Init()
{
    // TODO 读取RTC时间
    lock.SetDate(2022, 12, 20);
    lock.SetTime(20, 46, 15);
}

void Clock_Task(void *arg)
{
    while (1)
    {
        osDelay(1000);
        lock.TimeSecInc();
    }
}
