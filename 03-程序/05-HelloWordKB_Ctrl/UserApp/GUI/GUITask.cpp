//
// Created by QZY on 2022/12/4.
//
#include <stdio.h>
#include "cmsis_os2.h"
#include "GUITask.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "ui.h"
#include "UserApp.h"
#include "Clock.h"
#include "ControlTask.h"
#include "Bilibili.h"
#include "StockManager.h"
#include "Volume.h"
#include "KnobTask.h"
#include "LightTask.h"


void GUI_Process();
void GUI_AppInit();
void GUI_UpdateStock();
void GUI_UpdateClockDate();
void GUI_UpdateClockTime();
void GUI_UpdateVolume();
void GUI_UpdateBili();
void GUI_UpdateLightSetting();
float ToDegree(float radian);
void GUI_Setting_Light_Focus();
void GUI_UpdateLightColor();


#define UI_GIF_FRAME_NUM    4
uint8_t gifFrameIdx = 0;
static const lv_img_dsc_t *imgArray[UI_GIF_FRAME_NUM] = {
        &ui_img_bili1_png,
        &ui_img_bili2_png,
        &ui_img_bili3_png,
        &ui_img_bili4_png,
};

#define UI_STOCK_LABEL_NUM  7
static  lv_obj_t ** const stockLabelArray[UI_STOCK_LABEL_NUM] = {
        &ui_ScnStockLabel1,
        &ui_ScnStockLabel2,
        &ui_ScnStockLabel3,
        &ui_ScnStockLabel4,
        &ui_ScnStockLabel5,
        &ui_ScnStockLabel6,
        &ui_ScnStockLabel7,
};

LV_FONT_DECLARE(zhfont);
uint16_t settingSelectedIdx = 0;


void GUI_Init()
{
    lv_init();
    lv_port_disp_init();
    ui_init();
}

void GUI_Task(void *arg)
{
    printf("GUI_Task ready\r\n");
    while (!SystemReady)
        osDelay(10);

    GUI_AppInit();
    while (1)
    {
        GUI_Process();
        lv_task_handler();
        osDelay(10);
    }
}

void GUI_Process()
{
    // 当前页面
    CSystemControl::PageType_t currPage = sysControl.currPageType;

    // 页面改变
    if (AppEvent_GLB_Has(EVENT_GLB_PAGE_CHG))
    {
        settingSelectedIdx = 0;
        switch (currPage) {
            case CSystemControl::PAGE_CLOCK:
                lv_disp_load_scr(ui_ScnClock);
                break;
            case CSystemControl::PAGE_BILI:         // B站数据
                GUI_UpdateBili();
                lv_disp_load_scr(ui_ScnBiliData);
                break;
            case CSystemControl::PAGE_STOCK:
                lv_disp_load_scr(ui_ScnStock);
                break;
            case CSystemControl::PAGE_PHOTO:
                lv_disp_load_scr(ui_ScnPhoto);
                break;
            case CSystemControl::PAGE_VOLUME:
                GUI_UpdateVolume();
                lv_disp_load_scr(ui_ScnVolume);
                break;
            case CSystemControl::PAGE_SETTING:
                lv_disp_load_scr(ui_ScnSetting);
                break;
            case CSystemControl::PAGE_SETTING_LIGHT:
                GUI_UpdateLightSetting();
                GUI_Setting_Light_Focus();
                lv_disp_load_scr(ui_ScnLightSetting);
                break;
            case CSystemControl::PAGE_SETTING_KNOB:
                lv_disp_load_scr(ui_ScnSettingKnob);
                break;
            case CSystemControl::PAGE_SETTING_SEL_COLOR:
                lv_disp_load_scr(ui_ScnSelColor);
                break;
            case CSystemControl::PAGE_LAYER:
                lv_label_set_text_fmt(ui_ScnVolumeValue1, "%d", keyboardControler.settingLayer);
                lv_disp_load_scr(ui_ScnLayer);
                break;
            default:
                break;
        }
    }

    // 各个页面的各自处理
    // 时钟
    if (currPage == CSystemControl::PAGE_CLOCK)
    {
        if (AppEvent_GLB_Has(EVENT_GLB_CLOCK_DAY))
            GUI_UpdateClockDate();
        if (AppEvent_GLB_Has(EVENT_GLB_CLOCK_SEC))
            GUI_UpdateClockTime();
    }
    // 动画
    else if (currPage == CSystemControl::PAGE_PHOTO)
    {
        static uint8_t cnt = 0;
        if (++cnt >= 12)
        {
            cnt = 0;
            if (++gifFrameIdx >= UI_GIF_FRAME_NUM)
                gifFrameIdx = 0;

            lv_img_set_src(ui_ScnPhotoImage, imgArray[gifFrameIdx]);
        }
    }
    // B站数据
    else if (currPage == CSystemControl::PAGE_BILI)
    {

    }
    // 股票数据
    else if (currPage == CSystemControl::PAGE_STOCK)
    {
        if (AppEvent_GLB_Has(EVENT_GLB_STOCK_UPDATE))
            GUI_UpdateStock();
    }
    // 音量
    else if (currPage == CSystemControl::PAGE_VOLUME)
    {
        if (AppEvent_GLB_Has(EVENT_GLB_VOLUME_CHG))
            GUI_UpdateVolume();
    }
    // 设置首页
    else if (currPage == CSystemControl::PAGE_SETTING)
    {

    }
    // 旋钮设置
    else if (currPage == CSystemControl::PAGE_SETTING_KNOB)
    {
        static uint8_t cnt = 0;
        if (++cnt >= 10)
        {
            cnt = 0;
            // 角速度
            float vel = knob.GetVelocity();
            lv_label_set_text_fmt(ui_ScnSKnobOrig, "%.3f", vel);
            // 编码器角度
            float magLapAngle = motor.GetEstimateLapAngle();
            lv_label_set_text_fmt(ui_ScnSKnobAdjust, "%.3f", ToDegree(magLapAngle));
            // 旋钮角度
            float knobAngle = ToDegree(knob.GetLapPosition());
            lv_label_set_text_fmt(ui_ScnSKnobPosition, "%.3f", knobAngle);
            lv_arc_set_value(ui_ScnSettingKnob_Arc1, (int16_t)knobAngle);
            // 旋钮累计角度
            float posi = knob.GetPosition();
            lv_label_set_text_fmt(ui_ScnSKnobStrength, "%.1f", ToDegree(posi));
            // 模式,
            lv_label_set_text_fmt(ui_ScnSKnobMode, "%d, %d", knob.GetMode(), motor.config.controlMode);
        }
    }
    // 灯效设置
    else if (currPage == CSystemControl::PAGE_SETTING_LIGHT)
    {

    }
    // 灯颜色
    else if (currPage == CSystemControl::PAGE_SETTING_SEL_COLOR)
    {
        if (AppEvent_GLB_Has(EVENT_GLB_LIGHT_SET))
            GUI_UpdateLightColor();
    }
    else if (currPage == CSystemControl::PAGE_LAYER)
    {
        if (AppEvent_GLB_Has(EVENT_GLB_LAYER_CHG))
            lv_label_set_text_fmt(ui_ScnVolumeValue1, "%d", keyboardControler.settingLayer);
    }
}

// 应用初始化
void GUI_AppInit()
{
    // 时钟
    GUI_UpdateClockDate();
    GUI_UpdateClockTime();

    // 股票数据
    GUI_UpdateStock();

}

void GUI_UpdateLightSetting()
{
    if (isKnobEnable)
        lv_obj_add_state(ui_ScnLightKnob, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(ui_ScnLightKnob, LV_STATE_CHECKED);

    if (isPadEnable)
        lv_obj_add_state(ui_ScnLightPad, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(ui_ScnLightPad, LV_STATE_CHECKED);

    // 颜色
    lv_obj_set_style_bg_color(ui_ScnLightColor,
                              lv_color_make(Color_R, Color_G, Color_B),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
}

void GUI_UpdateClockDate()
{
    uint16_t year;
    uint8_t month, day;
    lock.GetDate(&year, &month, &day);
    lv_label_set_text_fmt(ui_ScnClockDate, "%04d-%02d-%02d", year, month, day);
}

void GUI_UpdateClockTime()
{
    uint8_t hour, min, sec;
    lock.GetTime(&hour, &min, &sec);
    // 时
    lv_img_set_angle(ui_ScnClockHour, ((int16_t)(hour%12) * 60 + min)*5);
    // 分
    lv_img_set_angle(ui_ScnClockMin, (int16_t)60*min);
    // 秒
    lv_img_set_angle(ui_ScnClockSec, (int16_t)60*sec);
}

void GUI_UpdateBili()
{
    uint32_t fans, likes, play, follow;
    bilibili.GetDate(&fans, &likes, &play, &follow);
    lv_label_set_text_fmt(ui_ScnBiliFans, "%d", fans);
    lv_label_set_text_fmt(ui_ScnBiliLikes, "%d", likes);
    lv_label_set_text_fmt(ui_ScnBiliPlay, "%.1fw", (float)play / 10000.0f);
}

void GUI_UpdateStock()
{
    int8_t stockIdx = 0;
    int8_t labelIdx = 0;
    for (;labelIdx < UI_STOCK_LABEL_NUM; stockIdx++, labelIdx++)
    {
        if (stockIdx < 0 || stockIdx >= stockManager.StockNum)
            lv_label_set_text(*stockLabelArray[labelIdx],"");
        else
        {
            CStock *stock = &stockManager.ListStock[stockIdx];
            lv_label_set_text_fmt(*stockLabelArray[labelIdx], "[%s] %+.2f%%  %.2f ", stock->Name, stock->pc, stock->Price);

            uint32_t color = 0xFFFFFF;
            if (stock->pc > 0.0f)
                color = 0xE10000;
            else if (stock->pc < 0.0f)
                color = 0x00DA06;
            lv_obj_set_style_text_color(*stockLabelArray[labelIdx], lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(*stockLabelArray[labelIdx], &zhfont, 0);
        }
    }
}

void GUI_UpdateVolume()
{
    uint8_t vol = volume.Volume;
    lv_label_set_text_fmt(ui_ScnVolumeValue, "%d", vol);
    lv_slider_set_value(ui_ScnVolume_Slider1, vol, LV_ANIM_OFF);
}

float ToDegree(float radian)
{
    return radian * 180.0f / _PI;
}

void GUI_Setting_Next()
{
    if (sysControl.currPageType == CSystemControl::PAGE_SETTING)    // 设置首页
    {
        uint16_t sel = lv_roller_get_selected(ui_ScnSetting_Roller1);
        uint16_t total = lv_roller_get_option_cnt(ui_ScnSetting_Roller1);
        if (++sel < total)
        {
            lv_roller_set_selected(ui_ScnSetting_Roller1, sel, LV_ANIM_ON);
        }
    }
    else if (sysControl.currPageType == CSystemControl::PAGE_SETTING_LIGHT) // 灯效
    {
        if (settingSelectedIdx < 2)
            settingSelectedIdx++;
        GUI_Setting_Light_Focus();
    }
}

void GUI_Setting_Light_Focus()
{
    if (settingSelectedIdx == 0)
    {
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label4, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label5, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label1, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_ScnLightSetting_Label4, ">Light of Knob");
        lv_label_set_text(ui_ScnLightSetting_Label5, "Light of Pad");
        lv_label_set_text(ui_ScnLightSetting_Label1, "Select Color");
    }
    else if (settingSelectedIdx == 1)
    {
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label4, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label5, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label1, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_ScnLightSetting_Label4, "Light of Knob");
        lv_label_set_text(ui_ScnLightSetting_Label5, ">Light of Pad");
        lv_label_set_text(ui_ScnLightSetting_Label1, "Select Color");
    }
    else if (settingSelectedIdx == 2)
    {
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label4, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label5, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_decor(ui_ScnLightSetting_Label1, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_ScnLightSetting_Label4, "Light of Knob");
        lv_label_set_text(ui_ScnLightSetting_Label5, "Light of Pad");
        lv_label_set_text(ui_ScnLightSetting_Label1, ">Select Color");
    }
}

void GUI_Setting_Prev()
{
    if (sysControl.currPageType == CSystemControl::PAGE_SETTING)    // 设置首页
    {
        uint16_t sel = lv_roller_get_selected(ui_ScnSetting_Roller1);
        if (sel > 0)
        {
            lv_roller_set_selected(ui_ScnSetting_Roller1, sel - 1, LV_ANIM_ON);
        }
    }
    else if (sysControl.currPageType == CSystemControl::PAGE_SETTING_LIGHT) // 灯效
    {
        if (settingSelectedIdx > 0)
            settingSelectedIdx --;
        GUI_Setting_Light_Focus();
    }
}

void GUI_Setting_Enter()
{
    if (sysControl.currPageType == CSystemControl::PAGE_SETTING)
    {
        uint16_t sel = lv_roller_get_selected(ui_ScnSetting_Roller1);
        switch (sel)
        {
            case 0:     // Layer
                sysControl.showTimeCnt = 0;
                sysControl.WorkMode_Set(CSystemControl::WM_LAYER);
                break;
            case 1:     // Light
                sysControl.Page_Set(CSystemControl::PAGE_SETTING_LIGHT);
                break;
            case 2:     // Knob
                sysControl.Page_Set(CSystemControl::PAGE_SETTING_KNOB);
                break;
            case 3:     // Volume
                sysControl.WorkMode_Set(CSystemControl::WM_VOLUME);
                break;
            default:
                break;
        }
    }
    else if (sysControl.currPageType == CSystemControl::PAGE_SETTING_LIGHT)
    {
        if (settingSelectedIdx == 0)    // Knob light
        {
            Light_SetKnobEnable(!isKnobEnable);
            if (isKnobEnable)
                lv_obj_add_state(ui_ScnLightKnob, LV_STATE_CHECKED);
            else
                lv_obj_clear_state(ui_ScnLightKnob, LV_STATE_CHECKED);
        }
        else if (settingSelectedIdx == 1)   // Pad light
        {
            Light_SetPadEnable(!isPadEnable);
            if (isPadEnable)
                lv_obj_add_state(ui_ScnLightPad, LV_STATE_CHECKED);
            else
                lv_obj_clear_state(ui_ScnLightPad, LV_STATE_CHECKED);
        }
        else if (settingSelectedIdx == 2)   // Select color
        {
            sysControl.SelColor_Enter();
            GUI_UpdateLightColor();
        }
    }
}

inline void GUI_UpdateLightColor()
{
    lv_colorwheel_set_rgb(ui_Screen1_Colorwheel1, lv_color_make(Color_R, Color_G, Color_B));
}
