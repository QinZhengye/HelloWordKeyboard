//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_KEYREMAP_H
#define HELLOWORDKB_CTRL_KEYREMAP_H

#include "keyboard.h"

#ifdef  __cplusplus
extern "C"
{
#endif

class CKeyMap
{
public:
    static const HWKeyboard::KeyID_t KEYID_FN = HWKeyboard::KEY00;  // Fn键位
    static const uint8_t LAYER_FN = 0;  // 固定不可改
    static const uint8_t LAYER_NUM = 4; // 层数

    enum KeyCode_t : int16_t
    {
        // E0 - E7
        LEFT_CTRL = -8,LEFT_SHIFT = -7,LEFT_ALT = -6,LEFT_GUI = -5,
        RIGHT_CTRL = -4,RIGHT_SHIFT = -3,RIGHT_ALT = -2,RIGHT_GUI = -1,

        RESERVED = 0,ERROR_ROLL_OVER,POST_FAIL,ERROR_UNDEFINED,
        A,B,C,D,E,F,G,H,I,J,K,L,M,
        N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
        NUM_1/*1!*/,NUM_2/*2@*/,NUM_3/*3#*/,NUM_4/*4$*/,NUM_5/*5%*/,
        NUM_6/*6^*/,NUM_7/*7&*/,NUM_8/*8**/,NUM_9/*9(*/,NUM_0/*0)*/,
        ENTER,ESC,BACKSPACE,TAB,SPACE,
        MINUS/*-_*/,EQUAL/*=+*/,LEFT_U_BRACE/*[{*/,RIGHT_U_BRACE/*]}*/,
        BACKSLASH/*\|*/,NONE_US/**/,SEMI_COLON/*;:*/,QUOTE/*'"*/,
        GRAVE_ACCENT/*`~*/,COMMA/*,<*/,PERIOD/*.>*/,SLASH/*/?*/,
        CAP_LOCK,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,
        PRINT,SCROLL_LOCK,PAUSE,INSERT,HOME,PAGE_UP,DELETE,END,PAGE_DOWN,
        RIGHT_ARROW,LEFT_ARROW,DOWN_ARROW,UP_ARROW,PAD_NUM_LOCK,
        PAD_SLASH,PAD_ASTERISK,PAD_MINUS,PAD_PLUS,PAD_ENTER,
        PAD_NUM_1,PAD_NUM_2,PAD_NUM_3,PAD_NUM_4,PAD_NUM_5,
        PAD_NUM_6,PAD_NUM_7,PAD_NUM_8,PAD_NUM_9,PAD_NUM_0,
        PAD_PERIOD , NONUS_BACKSLASH,APPLICATION,POWER,PAD_EQUAL,
        F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24, EXECUTE,
        HELP,MENU,SELECT,STOP,AGAIN,UNDO,CUT,COPY,PASTE,FIND,MUTE,VOLUME_UP,VOLUME_DOWN,

        FN = 1000,
        FN_HOME,                        /* 首页, 切换首页功能 */
        FN_SETTING,                     /* 进入设置模式 */
        FN_QUICK_LOOK,                  /* 快速浏览 */
        FN_VOLUME,                      /* 音量调节 */
        FN_NEXT_LIGHT_EFFECT,           /* 下一灯效 */
        FN_PREV_LAYER, FN_NEXT_LAYER,   /* 上一层, 下一层*/
        FN_PREV_MODE, FN_NEXT_MODE,     /* 上一模式, 下一模式 */
        FN_KNOB_SETTING,                /* 进入旋钮配置/校准 */
    };

    // 9键
    KeyCode_t KeyMapLayout[LAYER_NUM][9] = {
        {   // Fn层固定在0层
            FN, FN_HOME, FN_QUICK_LOOK,
            FN_SETTING, FN_VOLUME, FN_NEXT_LIGHT_EFFECT,
            FN_PREV_LAYER, FN_NEXT_LAYER,
            FN_KNOB_SETTING,
        },
        {
            FN,        PAD_NUM_1, PAD_NUM_2,
            ENTER,     PAD_NUM_3, PAD_NUM_4,
                       PAD_NUM_5, PAD_NUM_6,
                       LEFT_CTRL,
        },
        {
            FN,    LEFT_SHIFT, LEFT_CTRL,
            ENTER, LEFT_GUI, LEFT_ALT,
                    TAB, ESC,
            RIGHT_ALT,
        },
        {
            FN,    A, B,
            ENTER, C, D,
                   E, F,
                   SPACE,
        },
    };
};

#ifdef  __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_KEYREMAP_H
