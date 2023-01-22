//
// Created by QZY on 2022/11/27.
//

#include "encoder_mt6816.h"

void EncoderMT6816Base::Init()
{
    SpiInit();
    VarInit();
}


float EncoderMT6816Base::GetRawAngle()
{
    uint8_t bitCount = 0;
    uint16_t txDat1 = 0x8300;
    uint16_t txDat2 = 0x8400;
    uint16_t rxDat1, rxDat2;
    uint16_t sample_data;

    rxDat1 = SpiTransmitAndRead16Bits(txDat1);
    rxDat2 = SpiTransmitAndRead16Bits(txDat2);
    sample_data = ((rxDat1 & 0x00FF) << 8) | (rxDat2 & 0x00FF);

    // 校验
    for (uint8_t i = 0; i < 16; i++)
    {
        if (sample_data & (0x0001 << i))
            bitCount++;
    }
    if (bitCount & 0x0001)
        return -1.0f;   // 奇偶校验错误

    if (sample_data & (0x0001 << 1))
        return -2.0f;   // 弱磁场

    sample_data = sample_data >> 2;     // 数据对齐

    return ((float)sample_data / (float) COUNT_PER_ROTATE) * _2PI;
}
