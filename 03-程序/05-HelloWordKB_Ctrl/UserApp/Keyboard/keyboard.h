#ifndef HELLO_WORD_KEYBOARD_FW_HW_KEYBOARD_H
#define HELLO_WORD_KEYBOARD_FW_HW_KEYBOARD_H

#include "hardware.h"

#ifdef  __cplusplus
extern "C"
{
#endif

class HWKeyboard
{
public:
    static const uint8_t IO_NUMBER = 1 * 8;     // Used 1 pcs 74HC165
    static const uint8_t SPI_KEY_NUMBER = 8;
    static const uint8_t OK_KEY_INDEX = SPI_KEY_NUMBER;
    static const uint8_t KEY_NUMBER = SPI_KEY_NUMBER + 1;

    // 按键ID
    enum KeyID_t : uint8_t
    {
        KEY00 = 0, KEY01, KEY02,
        KEY10,     KEY11, KEY12,
        /*   */    KEY20, KEY21,
        KEY_KNOB_OK,     // 旋钮OK按键
    };

private:
    // "2"表示: KEY_1_1键对应spiBuffer的第2个bit
    const int8_t SPIKeyMap[SPI_KEY_NUMBER] = {
            2, 1, 0,
            7, 4, 3,
            6, 5
    };


public:
    void Update();
    bool KeyPressed(KeyID_t keyId);

private:
    void ScanKeyStates();
    void ApplyDebounceFilter(uint32_t _filterTimeUs = 100);
    void Remap();

    uint8_t spiBuffer[IO_NUMBER / 8 + 1]={};         // 按下为0
    uint8_t debounceBuffer[IO_NUMBER / 8 + 1]={};
    bool keySta_OK = false;     // 按下为true
    bool keySta_OK_Last;
    uint8_t keyBuffer[(SPI_KEY_NUMBER + 1)/8 + 1]={0};  // OK键放SPI键后面, KeyID_t为下标, 1为按下
    uint8_t keyBufferLast[(SPI_KEY_NUMBER + 1)/8 + 1]={0};
};

#ifdef  __cplusplus
}
#endif

#endif  // HELLO_WORD_KEYBOARD_FW_HW_KEYBOARD_H
