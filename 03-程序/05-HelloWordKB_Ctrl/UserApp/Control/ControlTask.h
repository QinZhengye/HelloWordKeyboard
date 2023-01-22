//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_CONTROLTASK_H
#define HELLOWORDKB_CTRL_CONTROLTASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "KeyboardControl.h"


void Control_Init();
void Control_Task(void *arg);

class CSystemControl
{
public:


    CSystemControl();
    enum WorkMode_t: int8_t
    {
        WM_UNDEF = -1,
        WM_POWER_OFF = 0,
        WM_NORMAL,
        WM_QUICK_LOOK,
        WM_VOLUME,
        WM_SETTING,
        WM_LAYER,
    };

    enum PageType_t: int8_t
    {
        PAGE_UNDEF = -1,
        PAGE_OFF = 0,
        PAGE_CLOCK,     // 1.时钟
        PAGE_BILI,      // 2.B站数据
        PAGE_STOCK,     // 3.股票
        PAGE_PHOTO,     // 4.相册
        PAGE_VOLUME,    // 5.音量调节
        PAGE_SETTING,   // 6.设置

        PAGE_SETTING_LIGHT, // 设置灯效
        PAGE_SETTING_KNOB,  // 设置旋钮
        PAGE_SETTING_SEL_COLOR, // 选择颜色

        PAGE_LAYER,
    };

    WorkMode_t currWorkMode;
    WorkMode_t lastWorkMode = WM_UNDEF;
    PageType_t currPageType;
    PageType_t lastPageType = PAGE_UNDEF;

    WorkMode_t saveWorkMode;
    PageType_t savePageType;
    uint8_t showTimeCnt;

    CKeyMap::KeyCode_t lastKeyCode = CKeyMap::RESERVED;

    void Tick();
    void WorkMode_Set(WorkMode_t wm);
    void Page_Set(PageType_t page);

    void Setting_Process();
    void Volume_Process();
    void SelColor_Enter();
    void ShowLayer_Enter();

private:
    int8_t volume_state;
};

extern CSystemControl sysControl;


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //HELLOWORDKB_CTRL_CONTROLTASK_H
