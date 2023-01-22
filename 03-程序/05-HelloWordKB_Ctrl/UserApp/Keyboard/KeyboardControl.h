//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_KEYBOARDCONTROL_H
#define HELLOWORDKB_CTRL_KEYBOARDCONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "keyboard.h"
#include "KeyMap.h"


void Keyboard_Init();
void Keyboard_Task(void *arg);


class CKeyboardControler
{
public:
    static const uint8_t HID_KEY_REPORT_SIZE = 1 + 1 + 15;
    static const uint8_t HID_MOUSE_REPORT_SIZE = 1 + 4;
    static const uint8_t HID_REPORT_SIZE = HID_KEY_REPORT_SIZE;
    static const uint8_t HID_KEY_REPORT_ID = 1;
    static const uint8_t HID_MOUSE_REPORT_ID = 2;


    CKeyboardControler(HWKeyboard* hwKB, CKeyMap* map)
    {
        hwKeyboard = hwKB;
        keyMap = map;
    }

    void Init();
    void Tick();
    bool IsFnPressed();
    void NextLayer();
    void PrevLayer();
    void SetLayer(uint8_t ly);
    void SetSendEnable(bool keySend, bool mouseSend) {
        isSendKey = keySend;
        isSendMouse = mouseSend;
    }
    CKeyMap::KeyCode_t fistFnKey = CKeyMap::RESERVED;  // 按下的Fn功能, TODO 加锁
    bool lastKeyState_Knob = false;
    bool lastKeyState_01 = false;
    bool lastKeyState_02 = false;
    uint8_t settingLayer = 1;       // 当前设定的层

private:
    void KeyProcess();
    void KnobProcess();
    void HIDBuff_Prepare();
    void HIDBuff_SetKeyCode(CKeyMap::KeyCode_t keyCode, bool isPressed=true);

    bool isSendKey = true;
    bool isSendMouse = true;

    HWKeyboard* hwKeyboard;
    CKeyMap* keyMap;

    uint8_t hidKeyBuffer[HID_REPORT_SIZE]{};    // ReportID, Modifier, Key-Code
    /*
        字节1：无符号字符型，低三位分别表示鼠标的左、右、中键是否被按下，1按下，0抬起。
        字节2：有符号字符型，表示鼠标在x方向的移动。
        字节3：有符号字符型，表示鼠标在y方向的移动。
        字节4：有符号字符型，表示鼠标滚轮的移动。
    */
    uint8_t hidMouseBuffer[HID_REPORT_SIZE]{};  // ReportID
    int knobLastPos;
};

extern CKeyboardControler keyboardControler;
extern HWKeyboard keyboard;


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_KEYBOARDCONTROL_H
