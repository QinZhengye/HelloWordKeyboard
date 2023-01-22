//
// Created by QZY on 2022/12/4.
//
#include <cstring>
#include <stdio.h>
#include "KeyboardControl.h"
#include "UserApp.h"
#include "cmsis_os2.h"
#include "KnobTask.h"
#include "USBTask.h"

HWKeyboard keyboard;
CKeyMap keyMap;
CKeyboardControler keyboardControler(&keyboard, &keyMap);

void Keyboard_Init()
{
    keyboardControler.Init();
}

void Keyboard_Task(void *arg)
{
    printf("Keyboard_Task ready\r\n");
    while (!SystemReady)
        osDelay(10);

    while (1)
    {
        keyboardControler.Tick();
        osDelay(2);
    }
}

void CKeyboardControler::Init()
{
    knobLastPos = knob.GetEncoderModePos();
}

void CKeyboardControler::Tick()
{
    HIDBuff_Prepare();
    keyboard.Update();

    KeyProcess();
    KnobProcess();
}

void CKeyboardControler::KeyProcess()
{
    // 当前层
    uint8_t currLayer = IsFnPressed()? keyMap->LAYER_FN: settingLayer;
    CKeyMap::KeyCode_t newFistFnKey = CKeyMap::RESERVED;
    for (uint8_t idx = 0; idx < hwKeyboard->KEY_NUMBER; idx++)
    {
        CKeyMap::KeyCode_t keyCode = keyMap->KeyMapLayout[currLayer][idx];
        bool isPressed = hwKeyboard->KeyPressed((HWKeyboard::KeyID_t)idx);
        // 不需发送处理
        if (keyCode == CKeyMap::RESERVED || keyCode == CKeyMap::FN)
            continue;

        // Fn功能键
        if (keyCode > CKeyMap::FN)
        {
            if (isPressed && newFistFnKey == CKeyMap::RESERVED)
                newFistFnKey = keyCode;
        }
        else
        {
            HIDBuff_SetKeyCode(keyCode, isPressed);
            // 内部操作按键处理
            if (idx == HWKeyboard::KEY01)
            {
                if (isPressed != lastKeyState_01 && isPressed)
                    AppEvent_GLB_Set(EVENT_GLB_KEY_01);
                lastKeyState_01 = isPressed;
            }
            else if (idx == HWKeyboard::KEY02)
            {
                if (isPressed != lastKeyState_02 && isPressed)
                    AppEvent_GLB_Set(EVENT_GLB_KEY_02);
                lastKeyState_02 = isPressed;
            }
            else if (idx == HWKeyboard::KEY_KNOB_OK)
            {
                if (isPressed != lastKeyState_Knob && isPressed)
                    AppEvent_GLB_Set(EVENT_GLB_KEY_KNOB);
                lastKeyState_Knob = isPressed;
            }
        }
    }
    fistFnKey = newFistFnKey;
    // 发送
    if (isSendKey)
        osMessageQueuePut(queueHIDSendHandle, hidKeyBuffer, 0, 0);
}

void CKeyboardControler::KnobProcess()
{
    int newPos = knob.GetEncoderModePos();

    if (newPos != knobLastPos)
    {
        // 发送事件
        AppEvent_GLB_Set((newPos > knobLastPos) ? EVENT_GLB_KNOB_CW : EVENT_GLB_KNOB_CCW);
        // 鼠标
        if (isSendMouse)
        {
            hidMouseBuffer[4] = newPos - knobLastPos;
            osMessageQueuePut(queueHIDSendHandle, hidMouseBuffer, 0, 0);
        }

        knobLastPos = newPos;
    }
}

void CKeyboardControler::HIDBuff_SetKeyCode(CKeyMap::KeyCode_t keyCode, bool isPressed)
{
    if (isPressed)
    {
        int16_t index, bitIndex;
        index = (int16_t) (keyCode / 8 + 1); // +1 for modifier
        bitIndex = (int16_t) (keyCode % 8);
        if (bitIndex < 0)
        {
            index -= 1;
            bitIndex += 8;
        } else if (index > 100)
            return;

        hidKeyBuffer[index + 1] |= 1 << (bitIndex); // +1 for Report-ID
    }
}

void CKeyboardControler::HIDBuff_Prepare()
{
    memset(hidKeyBuffer, 0, sizeof(hidKeyBuffer));
    memset(hidMouseBuffer, 0, sizeof(hidMouseBuffer));
    // Report ID
    hidKeyBuffer[0] = HID_KEY_REPORT_ID;
    hidMouseBuffer[0] = HID_MOUSE_REPORT_ID;
}

bool CKeyboardControler::IsFnPressed()
{
    return hwKeyboard->KeyPressed(CKeyMap::KEYID_FN);
}

void CKeyboardControler::NextLayer()
{
    if (++settingLayer >= CKeyMap::LAYER_NUM)
        settingLayer = 1;
    AppEvent_GLB_Set(EVENT_GLB_LAYER_CHG);
}

void CKeyboardControler::PrevLayer()
{
    if (settingLayer <= 1)
        settingLayer = CKeyMap::LAYER_NUM - 1;
    else
        settingLayer--;
    AppEvent_GLB_Set(EVENT_GLB_LAYER_CHG);
}

void CKeyboardControler::SetLayer(uint8_t ly)
{
    if (ly >= CKeyMap::LAYER_NUM)
        settingLayer = 1;
    else
        settingLayer = ly;
    AppEvent_GLB_Set(EVENT_GLB_LAYER_CHG);
}
