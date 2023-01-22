#ifndef CTRL_STEP_FW_AS5047_M0_STM32_H
#define CTRL_STEP_FW_AS5047_M0_STM32_H

#include "Ctrl/Sensor/Encoder/Instances/encoder_mt6816.h"


class Encoder : public EncoderMT6816Base
{
public:
    explicit Encoder(SPI_HandleTypeDef* _spi) : EncoderMT6816Base()
    {
        spiHandle = _spi;
    }

    SPI_HandleTypeDef* spiHandle = nullptr;


private:
    void SpiInit() override;

    uint16_t SpiTransmitAndRead16Bits(uint16_t _data) override;
};

#endif
