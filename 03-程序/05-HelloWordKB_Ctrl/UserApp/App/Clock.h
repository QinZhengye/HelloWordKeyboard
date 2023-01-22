//
// Created by QZY on 2022/12/11.
//

#ifndef HELLOWORDKB_CTRL_CLOCK_H
#define HELLOWORDKB_CTRL_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "UserApp.h"
#include "AppEvent.h"

void Clock_Init();
void Clock_Task(void *arg);

class CClock
{
public:
    void SetDate(const uint16_t _year, const uint8_t _month, const uint8_t _day)
    {
        year = _year;
        month = _month;
        day = _day;
    }

    void GetDate(uint16_t *_year, uint8_t *_month, uint8_t *_day)
    {
        *_year = year;
        *_month = month;
        *_day = day;
    }

    void SetTime(const uint8_t _hour, const uint8_t _min, const uint8_t _sec)
    {
        hour = _hour;
        min = _min;
        sec = _sec;
    }

    void GetTime(uint8_t *_hour, uint8_t *_min, uint8_t *_sec)
    {
        *_hour = hour;
        *_min = min;
        *_sec = sec;
    }

    void TimeSecInc()
    {
        if (++sec >= 60)
        {
            sec = 0;
            if (++min >= 60)
            {
                min = 0;
                if (++hour >= 24)
                {
                    hour = 0;
                    TimeDayInc();
                }
            }
        }

        AppEvent_GLB_Set(EVENT_GLB_CLOCK_SEC);
    }

    void TimeDayInc()
    {
        // TODO

        AppEvent_GLB_Set(EVENT_GLB_CLOCK_DAY);
    }

private:
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
};


extern CClock lock;


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_CLOCK_H
