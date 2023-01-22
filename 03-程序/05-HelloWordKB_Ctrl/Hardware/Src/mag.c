//
// Created by Administrator on 2022/11/22.
//   For MT6816, 14Bit
//

#include "mag.h"

SPI_HandleTypeDef *hMagSPI = &hspi2;

#define MAG_CS_Clr()   HAL_GPIO_WritePin(MAG_CS_GPIO_Port,MAG_CS_Pin, GPIO_PIN_RESET)//DC
#define MAG_CS_Set()   HAL_GPIO_WritePin(MAG_CS_GPIO_Port,MAG_CS_Pin, GPIO_PIN_SET)

void mag_Init()
{

}

uint16_t mag_WriteRead16Bit(uint16_t wDat)
{
    uint16_t rxDat[1];
    MAG_CS_Clr();
    HAL_SPI_TransmitReceive(hMagSPI, (uint8_t *)&wDat, (uint8_t *)&rxDat, 1, HAL_MAX_DELAY);
    MAG_CS_Set();
    return rxDat[0];
}

float mag_GetAngle()
{
    uint8_t bitCount = 0;
    uint16_t txDat1 = 0x8300;
    uint16_t txDat2 = 0x8400;
    uint16_t rxDat1, rxDat2;
    uint16_t sample_data;

    rxDat1 = mag_WriteRead16Bit(txDat1);
    rxDat2 = mag_WriteRead16Bit(txDat2);
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

    sample_data = sample_data >> 2;     // 对齐

    return (float)sample_data * 360.0f / 16384;
}