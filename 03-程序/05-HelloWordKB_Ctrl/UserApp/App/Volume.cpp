//
// Created by Administrator on 2022/12/13.
//

#include "Volume.h"

CVolume volume;

CVolume::CVolume()
{
    memset(HidBuffer, 0, sizeof(HidBuffer));
    HidBuffer[0] = 3;       // Report ID
}

void CVolume::TriggerSend()
{
    HidBuffer[1] = Volume;
    osMessageQueuePut(queueHIDSendHandle, HidBuffer, 0, 0);
}

float CVolume::VolumeToAngle(uint8_t vol)
{
    return (float)vol * (VOLUME_ANGLE_MAX - VOLUME_ANGLE_MIN) / 100.0f + VOLUME_ANGLE_MIN;
}

uint8_t CVolume::AngleToVolume(float angle)
{
    float vol = (angle - VOLUME_ANGLE_MIN) * 100.0f / (VOLUME_ANGLE_MAX - VOLUME_ANGLE_MIN);
    if (vol < 0)
        return 0;
    else if (vol > 100)
        return 100;
    else if ((uint8_t)vol % 2 != 0)
        return (uint8_t) vol - 1;
    else
        return (uint8_t) vol;
}
