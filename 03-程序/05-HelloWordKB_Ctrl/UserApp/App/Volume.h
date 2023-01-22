//
// Created by Administrator on 2022/12/13.
//

#ifndef HELLOWORDKB_CTRL_VOLUME_H
#define HELLOWORDKB_CTRL_VOLUME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cstring>
#include "UserApp.h"
#include "USBTask.h"
#include "Ctrl/Motor/math_utils.h"


class CVolume
{
public:
    constexpr static const float VOLUME_ANGLE_MIN = -(_PI*3/4);
    constexpr static const float VOLUME_ANGLE_MAX = (_PI*3/4);

    CVolume();
    float VolumeToAngle(uint8_t vol);
    uint8_t AngleToVolume(float angle);
    void TriggerSend();

    uint8_t Volume = 68;

private:
    uint8_t HidBuffer[USB_REPORT_BUFF_SIZE];
};


extern CVolume volume;


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //HELLOWORDKB_CTRL_VOLUME_H
