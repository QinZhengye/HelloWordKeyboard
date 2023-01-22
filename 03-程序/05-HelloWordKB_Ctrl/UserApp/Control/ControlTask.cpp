//
// Created by QZY on 2022/12/4.
//
#include <stdio.h>
#include "ControlTask.h"
#include "cmsis_os2.h"
#include "UserApp.h"
#include "KnobTask.h"
#include "lv_port_disp.h"
#include "Volume.h"
#include "GUITask.h"
#include "LightTask.h"

CSystemControl sysControl;

inline bool IsTaskReady()
{
    if (IsKnobTaskReady)
        return true;
    return false;
}

void Control_Init()
{

}

void Control_Task(void *arg)
{
    // Waiting task ready
    printf("Control waiting Task ready\r\n");
    while (!IsTaskReady())
        osDelay(10);
    SystemReady = true;
    printf("SystemReady\r\n");

    Knob_Start();
    while (1)
    {
        sysControl.Tick();
        osDelay(10);
    }
}

CSystemControl::CSystemControl()
{
    currWorkMode = WM_NORMAL;
    currPageType = PAGE_CLOCK;
}

void CSystemControl::Tick()
{
    static bool waitRelease = false;    // 等待松开
    bool isEnter = false;      // 刚进入新模式
    bool isPressed = false;    // 刚按下
    bool isReleased = false;   // 刚松开
    CKeyMap::KeyCode_t actKeyCode = keyboardControler.fistFnKey;    // 操作按键

    if (lastKeyCode != actKeyCode)
    {
        if (actKeyCode == CKeyMap::RESERVED)
        {
            isReleased = true;
            waitRelease = false;
        }
        else
        {
            isPressed = true;
        }
        lastKeyCode = actKeyCode;
    }
    if (waitRelease)
        return;

    switch (actKeyCode) {
        case CKeyMap::FN_HOME:      WorkMode_Set(WM_NORMAL); break;
        case CKeyMap::FN_QUICK_LOOK:WorkMode_Set(WM_QUICK_LOOK); break;
        case CKeyMap::FN_VOLUME:    WorkMode_Set(WM_VOLUME); break;
        case CKeyMap::FN_SETTING:
            if (isPressed && currWorkMode != WM_SETTING) {
                WorkMode_Set(WM_SETTING);
                Page_Set(PAGE_SETTING);
            }
            break;
        case CKeyMap::FN_KNOB_SETTING:          // 旋钮配置
            WorkMode_Set(WM_SETTING);
            Page_Set(PAGE_SETTING_KNOB);
            waitRelease = true;
            break;
        case CKeyMap::FN_NEXT_LIGHT_EFFECT:     // 下一灯效
            if (isPressed)
            {
                printf("Next light effect\r\n");    // TODO
            }
            return;
        case CKeyMap::FN_PREV_LAYER:            // 上一层
            if (isPressed)
            {
                keyboardControler.PrevLayer();
                ShowLayer_Enter();
            }
            return;
        case CKeyMap::FN_NEXT_LAYER:            // 下一层
            if (isPressed)
            {
                keyboardControler.NextLayer();
                ShowLayer_Enter();
            }
            return;
        default:
            break;
    }

    // 新切换工作模式
    if (currWorkMode != lastWorkMode)
    {
        lastWorkMode = currWorkMode;
        isEnter = true;
    }

    // 页面改变
    if (lastPageType != currPageType)
    {
        lastPageType = currPageType;
        AppEvent_GLB_ClearAct();

        if (knob.GetMode() != KnobSimulator::MODE_ENCODER
                && currPageType != PAGE_SETTING_SEL_COLOR
                && currPageType != PAGE_SETTING_KNOB
                && currPageType != PAGE_VOLUME)
            knob.SetMode(KnobSimulator::MODE_ENCODER);
    }

    // ======首页模式========
    if (currWorkMode == WM_NORMAL)
    {
        if (isEnter)
        {
            keyboardControler.SetSendEnable(true, true);
            Page_Set(PAGE_CLOCK);
        }
        else if (isPressed)  // 切换主页
        {
            // PAGE_CLOCK ~ PAGE_PHOTO
            if (currPageType >= PAGE_PHOTO)
                Page_Set(PAGE_CLOCK);
            else
                Page_Set((PageType_t)(currPageType + 1));
        }
    }
    // 快看
    else if (currWorkMode == WM_QUICK_LOOK)
    {
        if (isEnter)
        {
            Page_Set(PAGE_STOCK);
        }
        else if (isReleased)        // 松开, 回首页
        {
            WorkMode_Set(WM_NORMAL);
        }
    }
    // 音量
    else if (currWorkMode == WM_VOLUME)
    {
        if (isEnter)
        {
            Page_Set(PAGE_VOLUME);
            keyboardControler.SetSendEnable(true, false);
            volume_state = 0;
        }
        else if (isPressed)
        {
            WorkMode_Set(WM_NORMAL);
            Page_Set(PAGE_CLOCK);
            waitRelease = true;
        }
        else
        {
            Volume_Process();
        }
    }
    // 设置
    else if (currWorkMode == WM_SETTING)
    {
        if (isEnter)
        {
            keyboardControler.SetSendEnable(false, false);
        }
        else if (isPressed)
        {
            if (currPageType != PAGE_SETTING)
            {
                Page_Set(PAGE_SETTING);
            }
            else
            {
                WorkMode_Set(WM_NORMAL);
                Page_Set(PAGE_CLOCK);
            }
            waitRelease = true;
        }
        else
        {
            Setting_Process();
        }
    }
    // 层
    else if (currWorkMode == WM_LAYER)
    {
        if (isEnter)
        {
            Page_Set(PAGE_LAYER);
        }
        if (showTimeCnt > 0)
        {
            if (--showTimeCnt == 0)
            {
                WorkMode_Set(saveWorkMode);
                Page_Set(savePageType);
            }
        }
    }
}

void CSystemControl::Setting_Process()
{
    // 设置首页
    if (currPageType == PAGE_SETTING || currPageType == PAGE_SETTING_LIGHT)
    {
        // 旋钮上下选择
        if (AppEvent_GLB_Has(EVENT_GLB_KNOB_CW))
        {
            GUI_Setting_Next();
        }
        if (AppEvent_GLB_Has(EVENT_GLB_KNOB_CCW))
        {
            GUI_Setting_Prev();
        }
        if (AppEvent_GLB_Has(EVENT_GLB_KEY_KNOB))
        {
            GUI_Setting_Enter();
        }
    }
    // 旋钮设置页
    else if (currPageType == PAGE_SETTING_KNOB)
    {
        // 按旋钮 --> 归零校准
        if (AppEvent_GLB_Has(EVENT_GLB_KEY_KNOB))
        {
            knob.ApplyZeroPos();
        }
        // 切换旋钮模式
        if (AppEvent_GLB_Has(EVENT_GLB_KEY_01))
        {
            KnobSimulator::Mode_t mode = knob.GetMode();
            if (mode >= KnobSimulator::MODE_SPIN)
                knob.SetMode(KnobSimulator::MODE_INERTIA);
            else
            {
                mode = (KnobSimulator::Mode_t)((int)mode + 1);
                knob.SetMode(mode);
            }
            printf("Mode=%d\r\n", mode+1);
        }
    }
    // 灯效颜色
    else if (currPageType == PAGE_SETTING_SEL_COLOR)
    {
        uint8_t r, g, b;
        float angle = knob.GetPosition();
        Light_Angle2RGB(angle, &r, &g, &b);
        if (r != Color_R || g != Color_G || b != Color_B)
        {
            Color_R = r;
            Color_G = g;
            Color_B = b;
            AppEvent_GLB_Set(EVENT_GLB_LIGHT_SET);
        }
    }
}

void CSystemControl::Volume_Process()
{
    if (volume_state == 0)
    {
        knob.SetMode(KnobSimulator::MODE_PROGRAM);
        float angle = volume.VolumeToAngle(volume.Volume);
        knob.SetMotorTarget(angle);
        volume_state = 1;
    }
    else if (volume_state == 1)
    {
        if (volume.AngleToVolume(knob.GetPosition()) == volume.Volume)
        {
            knob.SetLimitPos(CVolume::VOLUME_ANGLE_MIN - 0.05, CVolume::VOLUME_ANGLE_MAX + 0.1);
            knob.SetMode(KnobSimulator::MODE_DAMPED);
            volume_state = 2;
        }
    }
    else if (volume_state == 2)
    {
        uint8_t newVol = volume.AngleToVolume(knob.GetPosition());
        if (newVol != volume.Volume)
        {
            volume.Volume = newVol;
            volume.TriggerSend();
            AppEvent_GLB_Set(EVENT_GLB_VOLUME_CHG);
        }
    }
}

void CSystemControl::SelColor_Enter()
{
    // 页面
    Page_Set(PAGE_SETTING_SEL_COLOR);
    // 旋钮
    float angle = Light_RGB2Angle(Color_R, Color_G, Color_B);
    knob.SetMode(KnobSimulator::MODE_INERTIA);
    knob.SetMotorTarget(angle);
}

void CSystemControl::ShowLayer_Enter()
{
    if (currWorkMode != WM_LAYER)
    {
        saveWorkMode = currWorkMode;
        savePageType = currPageType;
    }
    showTimeCnt = 150;
    WorkMode_Set(WM_LAYER);
    Page_Set(PAGE_LAYER);
}

void CSystemControl::WorkMode_Set(WorkMode_t wm)
{
    if (wm == WM_UNDEF)
        return;
    if (currWorkMode != wm)
    {
        currWorkMode = wm;
        AppEvent_GLB_Set(EVENT_GLB_WORKMODE_CHG);
        printf("Set WorkMode=%d\r\n", wm);
    }
}

void CSystemControl::Page_Set(PageType_t page)
{
    if (page == PAGE_UNDEF)
        return;
    if (currPageType != page)
    {
        currPageType = page;
        AppEvent_GLB_Set(EVENT_GLB_PAGE_CHG);
        printf("Set page=%d\r\n", page);
    }
}
