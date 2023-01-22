//
// Created by QZY on 2022/12/4.
//
#include <stdio.h>
#include "LightTask.h"
#include "cmsis_os2.h"
#include "main.h"
#include "UserApp.h"
#include "Ctrl/Motor/math_utils.h"

#define LIGHT_WS_HIGH   0xFE
#define LIGHT_WS_LOW    0xE0

SPI_HandleTypeDef *lightSPIHandle = &hspi3;
osSemaphoreId *lightSPISem = &semSPI3;

uint8_t rgbSendBuffer[LIGHT_LED_NUM * 3 * 8 + LIGHT_RESET_SPACE_NUM] = {0};
uint8_t rgbCounter = 0;                     // 0-199
uint8_t brightnessPreDiv = 2;               // 亮度1/4
bool isPadEnable = true;
bool isKnobEnable = true;
uint8_t Color_R = 128;
uint8_t Color_G = 0;
uint8_t Color_B = 255;


static void Light_Update();
static void Light_SetPadRGB(uint8_t r, uint8_t g, uint8_t b);
static void Light_SetKnobRGB(uint8_t r, uint8_t g, uint8_t b);
static void Light_SendOut();


void Light_Init()
{

}

void Light_Task(void *arg)
{
    printf("Light_Task ready\r\n");
    while (!SystemReady)
        osDelay(10);
    while (1)
    {
        // 计数
        if (++rgbCounter >= 200)
            rgbCounter = 0;
        // 更新动效
        Light_Update();
        // 输出
        Light_SendOut();

        osDelay(10);
    }
}

void Light_SetEnable(bool enable)
{
    isPadEnable = enable;
    isKnobEnable = enable;
    if (!enable)
    {
        Light_SetPadRGB(0, 0, 0);
        Light_SetKnobRGB(0, 0, 0);
    }
}

void Light_SetPadEnable(bool enable)
{
    isPadEnable = enable;
    if (!enable)
        Light_SetPadRGB(0, 0, 0);
}

void Light_SetKnobEnable(bool enable)
{
    isKnobEnable = enable;
    if (!enable)
        Light_SetKnobRGB(0, 0, 0);
}

static void Light_SetPadRGB(uint8_t r, uint8_t g, uint8_t b)
{
    // To ensure there's no sequence zero bits, otherwise will case ws2812b protocol error.
    if (b < 1)
        b = 1;
    for (uint8_t ledIdx = 0; ledIdx < LIGHT_KEYPAD_LED_NUM; ledIdx++)   // 遍历灯
    {
        for (uint8_t i = 0; i < 8; i++)     // 遍历8个位
        {
            rgbSendBuffer[(ledIdx * 3 + 0) * 8 + i] = (g >> brightnessPreDiv) & (0x80 >> i) ? LIGHT_WS_HIGH : LIGHT_WS_LOW;
            rgbSendBuffer[(ledIdx * 3 + 1) * 8 + i] = (r >> brightnessPreDiv) & (0x80 >> i) ? LIGHT_WS_HIGH : LIGHT_WS_LOW;
            rgbSendBuffer[(ledIdx * 3 + 2) * 8 + i] = (b >> brightnessPreDiv) & (0x80 >> i) ? LIGHT_WS_HIGH : LIGHT_WS_LOW;
        }
    }
}

static void Light_SetKnobRGB(uint8_t r, uint8_t g, uint8_t b)
{
    // To ensure there's no sequence zero bits, otherwise will case ws2812b protocol error.
    if (b < 1)
        b = 1;
    //for (uint8_t ledIdx = 0; ledIdx < LIGHT_KNOB_LED_NUM; ledIdx++)   // 遍历灯
    for (uint8_t ledIdx = 0; ledIdx < 1; ledIdx++)   // 遍历灯
    {
        for (uint8_t i = 0; i < 8; i++)     // 遍历8个位
        {
            rgbSendBuffer[((ledIdx + LIGHT_KEYPAD_LED_NUM) * 3 + 0) * 8 + i] = (g >> brightnessPreDiv) & (0x80 >> i) ? LIGHT_WS_HIGH : LIGHT_WS_LOW;
            rgbSendBuffer[((ledIdx + LIGHT_KEYPAD_LED_NUM) * 3 + 1) * 8 + i] = (r >> brightnessPreDiv) & (0x80 >> i) ? LIGHT_WS_HIGH : LIGHT_WS_LOW;
            rgbSendBuffer[((ledIdx + LIGHT_KEYPAD_LED_NUM) * 3 + 2) * 8 + i] = (b >> brightnessPreDiv) & (0x80 >> i) ? LIGHT_WS_HIGH : LIGHT_WS_LOW;
        }
    }
}

static void Light_Update()
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    if (rgbCounter < 100)
    {
        r = (uint16_t)Color_R * rgbCounter / 100;
        g = (uint16_t)Color_G * rgbCounter / 100;
        b = (uint16_t)Color_B * rgbCounter / 100;
    }
    else
    {
        r = (uint16_t)Color_R * (200 - rgbCounter) / 100;
        g = (uint16_t)Color_G * (200 - rgbCounter) / 100;
        b = (uint16_t)Color_B * (200 - rgbCounter) / 100;
    }

    if (isKnobEnable)
        Light_SetKnobRGB(r, g, b);
    if (isPadEnable)
        Light_SetPadRGB(r, g, b);
}

static void Light_SendOut()
{
    if (osSemaphoreAcquire(*lightSPISem, osWaitForever) == osOK)
        HAL_SPI_Transmit_DMA(lightSPIHandle, rgbSendBuffer, sizeof(rgbSendBuffer));
}

float Light_RGB2Angle(uint8_t r, uint8_t g, uint8_t b)
{
    if (g >= b && b >= r)  // 00FFxx, 1
    {
        return (float)(0xFF - b) / 255.0f * _PI_3;
    }
    else if (g >= r && r >= b)  // xxFF00, 2
    {
        return (float)r / 255.0f * _PI_3 + _PI_3;
    }
    else if (r >= g && g >= b)   // FFxx00, 3
    {
        return (float)(0xFF - g) / 255.0f * _PI_3 + 2*_PI_3;
    }
    else if (r >= b && b >= g)  // FF00xx, 4
    {
        return (float)b / 255.0f * _PI_3 + _PI;
    }
    else if (b >= r && r >= g)  // xx00FF, 5
    {
        return (float)(0xFF - r) / 255.0f * _PI_3 + 4*_PI_3;
    }
    else if (b >= g && g >= r)  // 00xxFF, 6
    {
        return (float)g / 255.0f * _PI_3 + 5*_PI_3;
    }
    else
        return 0.0f;
}

void Light_Angle2RGB(float angle, uint8_t *r, uint8_t *g, uint8_t *b)
{
    angle = Normalize(angle);
    if (angle < _PI_3)      //
    {
        *r = 0x00;
        *g = 0xFF;
        *b = 255 - angle * 255.0f / _PI_3;
    }
    else if (angle < 2*_PI_3)   //
    {
        *r = (angle - _PI_3) * 255.0f / _PI_3;
        *g = 0xFF;
        *b = 0x00;
    }
    else if (angle < 3*_PI_3)   //
    {
        *r = 0xFF;
        *g = 255 - (angle - 2*_PI_3) * 255.0f / _PI_3;
        *b = 0x00;
    }
    else if (angle < 4*_PI_3)
    {
        *r = 0xFF;
        *g = 0x00;
        *b = (angle - 3*_PI_3) * 255.0f / _PI_3;
    }
    else if (angle < 5*_PI_3)
    {
        *r = 255 - (angle - 4*_PI_3) * 255.0f / _PI_3;
        *g = 0x00;
        *b = 0xFF;
    }
    else
    {
        *r = 0x00;
        *g = (angle - 5*_PI_3) * 255.0f / _PI_3;
        *b = 0xFF;
    }
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if (hspi == lightSPIHandle)
    {
        osSemaphoreRelease(*lightSPISem);
    }
}
