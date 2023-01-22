#include "encoder.h"
#include "main.h"


void Encoder::SpiInit()
{

}


uint16_t Encoder::SpiTransmitAndRead16Bits(uint16_t _dataTx)
{
    uint16_t rxDat[1];
    HAL_GPIO_WritePin(MAG_CS_GPIO_Port,MAG_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(spiHandle, (uint8_t *)&_dataTx, (uint8_t *)&rxDat, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(MAG_CS_GPIO_Port,MAG_CS_Pin, GPIO_PIN_SET);
    return rxDat[0];
}
