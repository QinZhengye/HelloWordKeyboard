#include <cstring>
#include "keyboard.h"
#include "cmsis_os.h"
#include "main.h"
#include "UserApp.h"

osSemaphoreId *keyboardSPISem = &semSPI3;

inline void DelayUs(uint32_t _us)
{
    for (int i = 0; i < _us; i++)
        for (int j = 0; j < 8; j++)  // ToDo: tune this for different chips
            __NOP();
}

void HWKeyboard::Update()
{
    if (osSemaphoreAcquire(*keyboardSPISem, osWaitForever) != osOK)
        return;
    ScanKeyStates();  // Around 40us use 4MHz SPI clk
    ApplyDebounceFilter();   // 两次防抖
    ApplyDebounceFilter();
    osSemaphoreRelease(*keyboardSPISem);

    Remap();
}

void HWKeyboard::ScanKeyStates()
{
    memset(spiBuffer, 0xFF, sizeof(spiBuffer));
    keypad_Scan(spiBuffer, sizeof(spiBuffer));
    keySta_OK = (HAL_GPIO_ReadPin(KEY_OK_GPIO_Port, KEY_OK_Pin) == 0);  // 按下==0, -->true
}

void HWKeyboard::ApplyDebounceFilter(uint32_t _filterTimeUs)
{
    keySta_OK_Last = keySta_OK;
    memcpy(debounceBuffer, spiBuffer, sizeof(spiBuffer));

    DelayUs(_filterTimeUs);
    ScanKeyStates();

    uint8_t mask;
    for (int i = 0; i < IO_NUMBER / 8 + 1; i++)
    {
        mask = debounceBuffer[i] ^ spiBuffer[i];
        spiBuffer[i] |= mask;   // 两次都按下 -->0
    }
    keySta_OK = (keySta_OK_Last && keySta_OK);  // 两次都按下 -->true
}

void HWKeyboard::Remap()
{
    int8_t index, bitIndex;

    memset(keyBuffer, 0, sizeof(keyBuffer));
    for (uint8_t i = 0; i < SPI_KEY_NUMBER; i++)    // 为每个按键找电平值
    {
        index =  (int8_t)(SPIKeyMap[i] / 8);
        bitIndex =  (int8_t)(SPIKeyMap[i] % 8);
        if ((spiBuffer[index] & (0x01 << bitIndex)) == 0x00)  // 低电平为按下
            keyBuffer[i/8] |= 0x80 >> (i%8);
    }
    if (keySta_OK)      // OK键按下
        keyBuffer[OK_KEY_INDEX/8] |= 0x80 >> (OK_KEY_INDEX%8);
    // Copy
    memcpy(keyBufferLast, keyBuffer, sizeof(keyBuffer));
}

bool HWKeyboard::KeyPressed(KeyID_t keyid)
{
    return keyBufferLast[keyid / 8] & (0x80 >> (keyid % 8));
}
