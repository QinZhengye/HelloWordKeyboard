//
// Created by Administrator on 2022/11/22.
//

#include "keypad.h"

extern SPI_HandleTypeDef hspi3;
SPI_HandleTypeDef *keypadSpiHandle = &hspi3;
static uint8_t spaceBuff[HW_KEY_NUMBER / 8 + 1] = {0};

void keypad_Init()
{

}

void keypad_Scan(uint8_t *keyBuff, uint16_t size)
{
    HAL_GPIO_WritePin(KEY_CE_GPIO_Port,KEY_CE_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_PL_GPIO_Port,KEY_PL_Pin,GPIO_PIN_SET);// Latch

    HAL_SPI_TransmitReceive(keypadSpiHandle, spaceBuff, keyBuff, size, HAL_MAX_DELAY);

    HAL_GPIO_WritePin(KEY_PL_GPIO_Port,KEY_PL_Pin,GPIO_PIN_RESET); // Sample
    HAL_GPIO_WritePin(KEY_CE_GPIO_Port,KEY_CE_Pin,GPIO_PIN_SET);
}
