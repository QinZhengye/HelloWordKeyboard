//
// Created by QZY on 2022/11/27.
//

#ifndef HELLOWORDKB_CTRL_ENCODER_MT6816_H
#define HELLOWORDKB_CTRL_ENCODER_MT6816_H

#include "Ctrl/Sensor/Encoder/encoder_base.h"
#include "Ctrl/Motor/math_utils.h"


class EncoderMT6816Base : public EncoderBase
{
public:
    const static uint8_t RESOLUTION_BITS = 14;
    const static uint16_t COUNT_PER_ROTATE = 16384;

    EncoderMT6816Base() = default;

    void Init() override;

private:
    float GetRawAngle() override;

    /***** Platform Specified Implements *****/
    virtual void SpiInit() = 0;
    virtual uint16_t SpiTransmitAndRead16Bits(uint16_t _dataTx) = 0;
};

#endif //HELLOWORDKB_CTRL_ENCODER_MT6816_H
