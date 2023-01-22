// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: HelloWord

#include "ui.h"
#include "ui_helpers.h"


///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScnClock;
lv_obj_t * ui_ScnClock_Panel1;
lv_obj_t * ui_ScnClockDot1;
lv_obj_t * ui_ScnClockDot2;
lv_obj_t * ui_ScnClockDot3;
lv_obj_t * ui_ScnClockDot4;
lv_obj_t * ui_ScnClockDot5;
lv_obj_t * ui_ScnClockDot6;
lv_obj_t * ui_ScnClockDot7;
lv_obj_t * ui_ScnClockDot8;
lv_obj_t * ui_ScnClock_Label1;
lv_obj_t * ui_ScnClock_Label2;
lv_obj_t * ui_ScnClock_Label3;
lv_obj_t * ui_ScnClock_Label4;
lv_obj_t * ui_ScnClockHour;
lv_obj_t * ui_ScnClockMin;
lv_obj_t * ui_ScnClockSec;
lv_obj_t * ui_ScnClockDate;
lv_obj_t * ui_ScnClockDot9;
lv_obj_t * ui_ScnClock_Spinner1;
lv_obj_t * ui_ScnBiliData;
lv_obj_t * ui_ScnBiliData_Image5;
lv_obj_t * ui_ScnBiliData_Image6;
lv_obj_t * ui_ScnBiliFans;
lv_obj_t * ui_ScnBiliLikes;
lv_obj_t * ui_ScnBiliPlay;
lv_obj_t * ui_ScnStock;
lv_obj_t * ui_ScnSetting_Panel1;
lv_obj_t * ui_ScnStockLabel1;
lv_obj_t * ui_ScnStockLabel2;
lv_obj_t * ui_ScnStockLabel3;
lv_obj_t * ui_ScnStockLabel4;
lv_obj_t * ui_ScnStockLabel5;
lv_obj_t * ui_ScnStockLabel6;
lv_obj_t * ui_ScnStockLabel7;
lv_obj_t * ui_ScnPhoto;
lv_obj_t * ui_ScnPhotoImage;
lv_obj_t * ui_ScnVolume;
lv_obj_t * ui_ScnVolume_Slider1;
lv_obj_t * ui_ScnVolumeValue;
lv_obj_t * ui_ScnVolume_Label3;
lv_obj_t * ui_ScnSetting;
lv_obj_t * ui_ScnSetting_Roller1;
lv_obj_t * ui_ScnLightSetting;
lv_obj_t * ui_ScnLightKnob;
lv_obj_t * ui_ScnLightPad;
lv_obj_t * ui_ScnLightSetting_Label4;
lv_obj_t * ui_ScnLightSetting_Label5;
lv_obj_t * ui_ScnLightColor;
lv_obj_t * ui_ScnLightSetting_Label1;
lv_obj_t * ui_ScnSelColor;
lv_obj_t * ui_Screen1_Colorwheel1;
lv_obj_t * ui_ScnSettingKnob;
lv_obj_t * ui_ScnSettingKnob_Arc1;
lv_obj_t * ui_ScnSettingKnob_Label1;
lv_obj_t * ui_ScnSettingKnob_Label2;
lv_obj_t * ui_ScnSettingKnob_Label3;
lv_obj_t * ui_ScnSettingKnob_Label4;
lv_obj_t * ui_ScnSettingKnob_Label5;
lv_obj_t * ui_ScnSKnobOrig;
lv_obj_t * ui_ScnSKnobAdjust;
lv_obj_t * ui_ScnSKnobPosition;
lv_obj_t * ui_ScnSKnobStrength;
lv_obj_t * ui_ScnSKnobMode;
lv_obj_t * ui_ScnLayer;
lv_obj_t * ui_ScnVolumeValue1;
lv_obj_t * ui_ScnVolume_Label1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_ScnClock_screen_init(void)
{
    ui_ScnClock = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnClock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScnClock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClock_Panel1 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClock_Panel1, 180);
    lv_obj_set_height(ui_ScnClock_Panel1, 180);
    lv_obj_set_align(ui_ScnClock_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClock_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClock_Panel1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot1 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot1, 8);
    lv_obj_set_height(ui_ScnClockDot1, 8);
    lv_obj_set_x(ui_ScnClockDot1, 57);
    lv_obj_set_y(ui_ScnClockDot1, -98);
    lv_obj_set_align(ui_ScnClockDot1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot1, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot2 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot2, 8);
    lv_obj_set_height(ui_ScnClockDot2, 8);
    lv_obj_set_x(ui_ScnClockDot2, 99);
    lv_obj_set_y(ui_ScnClockDot2, -57);
    lv_obj_set_align(ui_ScnClockDot2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot2, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot3 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot3, 8);
    lv_obj_set_height(ui_ScnClockDot3, 8);
    lv_obj_set_x(ui_ScnClockDot3, 99);
    lv_obj_set_y(ui_ScnClockDot3, 57);
    lv_obj_set_align(ui_ScnClockDot3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot3, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot3, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot4 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot4, 8);
    lv_obj_set_height(ui_ScnClockDot4, 8);
    lv_obj_set_x(ui_ScnClockDot4, 57);
    lv_obj_set_y(ui_ScnClockDot4, 99);
    lv_obj_set_align(ui_ScnClockDot4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot4, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot4, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot5 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot5, 8);
    lv_obj_set_height(ui_ScnClockDot5, 8);
    lv_obj_set_x(ui_ScnClockDot5, -56);
    lv_obj_set_y(ui_ScnClockDot5, 98);
    lv_obj_set_align(ui_ScnClockDot5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot5, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot5, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot6 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot6, 8);
    lv_obj_set_height(ui_ScnClockDot6, 8);
    lv_obj_set_x(ui_ScnClockDot6, -98);
    lv_obj_set_y(ui_ScnClockDot6, 56);
    lv_obj_set_align(ui_ScnClockDot6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot6, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot6, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot7 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot7, 8);
    lv_obj_set_height(ui_ScnClockDot7, 8);
    lv_obj_set_x(ui_ScnClockDot7, -98);
    lv_obj_set_y(ui_ScnClockDot7, -57);
    lv_obj_set_align(ui_ScnClockDot7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot7, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot7, lv_color_hex(0x6234FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot8 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot8, 8);
    lv_obj_set_height(ui_ScnClockDot8, 8);
    lv_obj_set_x(ui_ScnClockDot8, -56);
    lv_obj_set_y(ui_ScnClockDot8, -98);
    lv_obj_set_align(ui_ScnClockDot8, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot8, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot8, lv_color_hex(0x6735FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClock_Label1 = lv_label_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClock_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClock_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnClock_Label1, 0);
    lv_obj_set_y(ui_ScnClock_Label1, 2);
    lv_obj_set_align(ui_ScnClock_Label1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_ScnClock_Label1, "12");
    lv_obj_set_style_text_font(ui_ScnClock_Label1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClock_Label2 = lv_label_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClock_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClock_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnClock_Label2, -9);
    lv_obj_set_y(ui_ScnClock_Label2, 0);
    lv_obj_set_align(ui_ScnClock_Label2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ScnClock_Label2, "3");
    lv_obj_set_style_text_font(ui_ScnClock_Label2, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClock_Label3 = lv_label_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClock_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClock_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ScnClock_Label3, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_ScnClock_Label3, "6");
    lv_obj_set_style_text_font(ui_ScnClock_Label3, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClock_Label4 = lv_label_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClock_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClock_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnClock_Label4, 9);
    lv_obj_set_y(ui_ScnClock_Label4, 0);
    lv_obj_set_align(ui_ScnClock_Label4, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnClock_Label4, "9");
    lv_obj_set_style_text_font(ui_ScnClock_Label4, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockHour = lv_img_create(ui_ScnClock);
    lv_img_set_src(ui_ScnClockHour, &ui_img_clock_hour_png);
    lv_obj_set_width(ui_ScnClockHour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClockHour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ScnClockHour, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnClockHour, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScnClockHour, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_ScnClockHour, 500);

    ui_ScnClockMin = lv_img_create(ui_ScnClock);
    lv_img_set_src(ui_ScnClockMin, &ui_img_clock_min_png);
    lv_obj_set_width(ui_ScnClockMin, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClockMin, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ScnClockMin, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnClockMin, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScnClockMin, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_ScnClockMin, 300);
    lv_img_set_zoom(ui_ScnClockMin, 550);

    ui_ScnClockSec = lv_img_create(ui_ScnClock);
    lv_img_set_src(ui_ScnClockSec, &ui_img_clock_sec_png);
    lv_obj_set_width(ui_ScnClockSec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClockSec, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ScnClockSec, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnClockSec, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScnClockSec, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_ScnClockSec, 600);
    lv_img_set_zoom(ui_ScnClockSec, 480);

    ui_ScnClockDate = lv_label_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDate, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnClockDate, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnClockDate, 0);
    lv_obj_set_y(ui_ScnClockDate, 34);
    lv_obj_set_align(ui_ScnClockDate, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnClockDate, "2022-09-02");
    lv_obj_set_style_text_font(ui_ScnClockDate, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClockDot9 = lv_obj_create(ui_ScnClock);
    lv_obj_set_width(ui_ScnClockDot9, 12);
    lv_obj_set_height(ui_ScnClockDot9, 12);
    lv_obj_set_align(ui_ScnClockDot9, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClockDot9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnClockDot9, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnClockDot9, lv_color_hex(0xA1009F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnClockDot9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnClockDot9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnClock_Spinner1 = lv_spinner_create(ui_ScnClock, 1000, 90);
    lv_obj_set_width(ui_ScnClock_Spinner1, 80);
    lv_obj_set_height(ui_ScnClock_Spinner1, 80);
    lv_obj_set_x(ui_ScnClock_Spinner1, 198);
    lv_obj_set_y(ui_ScnClock_Spinner1, 48);
    lv_obj_set_align(ui_ScnClock_Spinner1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnClock_Spinner1, LV_OBJ_FLAG_CLICKABLE);      /// Flags

}
void ui_ScnBiliData_screen_init(void)
{
    ui_ScnBiliData = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnBiliData, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScnBiliData, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnBiliData, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnBiliData_Image5 = lv_img_create(ui_ScnBiliData);
    lv_img_set_src(ui_ScnBiliData_Image5, &ui_img_profile_png);
    lv_obj_set_width(ui_ScnBiliData_Image5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnBiliData_Image5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnBiliData_Image5, 0);
    lv_obj_set_y(ui_ScnBiliData_Image5, -56);
    lv_obj_set_align(ui_ScnBiliData_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnBiliData_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScnBiliData_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScnBiliData_Image6 = lv_img_create(ui_ScnBiliData);
    lv_img_set_src(ui_ScnBiliData_Image6, &ui_img_dataitem_png);
    lv_obj_set_width(ui_ScnBiliData_Image6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnBiliData_Image6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnBiliData_Image6, -3);
    lv_obj_set_y(ui_ScnBiliData_Image6, 15);
    lv_obj_set_align(ui_ScnBiliData_Image6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnBiliData_Image6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScnBiliData_Image6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScnBiliFans = lv_label_create(ui_ScnBiliData);
    lv_obj_set_width(ui_ScnBiliFans, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnBiliFans, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnBiliFans, -78);
    lv_obj_set_y(ui_ScnBiliFans, 45);
    lv_obj_set_align(ui_ScnBiliFans, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnBiliFans, "123");
    lv_obj_set_style_text_color(ui_ScnBiliFans, lv_color_hex(0xFF77FA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnBiliFans, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnBiliFans, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnBiliLikes = lv_label_create(ui_ScnBiliData);
    lv_obj_set_width(ui_ScnBiliLikes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnBiliLikes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnBiliLikes, -3);
    lv_obj_set_y(ui_ScnBiliLikes, 45);
    lv_obj_set_align(ui_ScnBiliLikes, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnBiliLikes, "1234");
    lv_obj_set_style_text_color(ui_ScnBiliLikes, lv_color_hex(0xFF77FA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnBiliLikes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnBiliLikes, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnBiliPlay = lv_label_create(ui_ScnBiliData);
    lv_obj_set_width(ui_ScnBiliPlay, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnBiliPlay, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnBiliPlay, 70);
    lv_obj_set_y(ui_ScnBiliPlay, 45);
    lv_obj_set_align(ui_ScnBiliPlay, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnBiliPlay, "12.3w");
    lv_obj_set_style_text_color(ui_ScnBiliPlay, lv_color_hex(0xFF77FA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnBiliPlay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnBiliPlay, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScnStock_screen_init(void)
{
    ui_ScnStock = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnStock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScnStock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnStock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnSetting_Panel1 = lv_obj_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnSetting_Panel1, 250);
    lv_obj_set_height(ui_ScnSetting_Panel1, 24);
    lv_obj_set_align(ui_ScnSetting_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScnSetting_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScnSetting_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnStockLabel1 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel1, 20);
    lv_obj_set_y(ui_ScnStockLabel1, -66);
    lv_obj_set_align(ui_ScnStockLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel1, "+2.02% 3179.04 [ABCDEFG]");
    lv_obj_set_style_text_color(ui_ScnStockLabel1, lv_color_hex(0xE10000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnStockLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnStockLabel2 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel2, 20);
    lv_obj_set_y(ui_ScnStockLabel2, -45);
    lv_obj_set_align(ui_ScnStockLabel2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel2, "+2.02% 3179.04 [ABCDEFG]");
    lv_obj_set_style_text_color(ui_ScnStockLabel2, lv_color_hex(0x00DA06), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnStockLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnStockLabel3 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel3, 20);
    lv_obj_set_y(ui_ScnStockLabel3, -24);
    lv_obj_set_align(ui_ScnStockLabel3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel3, "+2.02% 3179.04 [ABCDEFG]");

    ui_ScnStockLabel4 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel4, 20);
    lv_obj_set_y(ui_ScnStockLabel4, 0);
    lv_obj_set_align(ui_ScnStockLabel4, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel4, "+2.02% 3179.04 [ABCDEFG]");

    ui_ScnStockLabel5 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel5, 20);
    lv_obj_set_y(ui_ScnStockLabel5, 24);
    lv_obj_set_align(ui_ScnStockLabel5, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel5, "+2.02% 3179.04 [ABCDEFG]");

    ui_ScnStockLabel6 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel6, 20);
    lv_obj_set_y(ui_ScnStockLabel6, 45);
    lv_obj_set_align(ui_ScnStockLabel6, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel6, "+2.02% 3179.04 [ABCDEFG]");

    ui_ScnStockLabel7 = lv_label_create(ui_ScnStock);
    lv_obj_set_width(ui_ScnStockLabel7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnStockLabel7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnStockLabel7, 20);
    lv_obj_set_y(ui_ScnStockLabel7, 66);
    lv_obj_set_align(ui_ScnStockLabel7, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnStockLabel7, "+2.02% 3179.04 [ABCDEFG]");

}
void ui_ScnPhoto_screen_init(void)
{
    ui_ScnPhoto = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnPhoto, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScnPhoto, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnPhoto, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnPhotoImage = lv_img_create(ui_ScnPhoto);
    lv_img_set_src(ui_ScnPhotoImage, &ui_img_bili1_png);
    lv_obj_set_width(ui_ScnPhotoImage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnPhotoImage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ScnPhotoImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnPhotoImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScnPhotoImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_ScnVolume_screen_init(void)
{
    ui_ScnVolume = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnVolume, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScnVolume_Slider1 = lv_slider_create(ui_ScnVolume);
    lv_slider_set_value(ui_ScnVolume_Slider1, 75, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScnVolume_Slider1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ScnVolume_Slider1, 0,
                                                                                                      LV_ANIM_OFF);
    lv_obj_set_width(ui_ScnVolume_Slider1, 240);
    lv_obj_set_height(ui_ScnVolume_Slider1, 241);
    lv_obj_set_align(ui_ScnVolume_Slider1, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_ScnVolume_Slider1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnVolume_Slider1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnVolume_Slider1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScnVolume_Slider1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnVolume_Slider1, lv_color_hex(0x5A24FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnVolume_Slider1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScnVolume_Slider1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScnVolume_Slider1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnVolume_Slider1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ScnVolumeValue = lv_label_create(ui_ScnVolume);
    lv_obj_set_width(ui_ScnVolumeValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnVolumeValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnVolumeValue, 0);
    lv_obj_set_y(ui_ScnVolumeValue, -11);
    lv_obj_set_align(ui_ScnVolumeValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnVolumeValue, "75");
    lv_obj_set_style_text_font(ui_ScnVolumeValue, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnVolume_Label3 = lv_label_create(ui_ScnVolume);
    lv_obj_set_width(ui_ScnVolume_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnVolume_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnVolume_Label3, 0);
    lv_obj_set_y(ui_ScnVolume_Label3, 24);
    lv_obj_set_align(ui_ScnVolume_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnVolume_Label3, "Volume");
    lv_obj_set_style_text_font(ui_ScnVolume_Label3, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScnSetting_screen_init(void)
{
    ui_ScnSetting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnSetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScnSetting_Roller1 = lv_roller_create(ui_ScnSetting);
    lv_roller_set_options(ui_ScnSetting_Roller1, "Layer\nLight\nKnob\nVolume", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_ScnSetting_Roller1, 240);
    lv_obj_set_height(ui_ScnSetting_Roller1, 240);
    lv_obj_set_align(ui_ScnSetting_Roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_ScnSetting_Roller1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScnSetting_Roller1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnSetting_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScnLightSetting_screen_init(void)
{
    ui_ScnLightSetting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnLightSetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScnLightSetting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnLightSetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnLightKnob = lv_switch_create(ui_ScnLightSetting);
    lv_obj_set_width(ui_ScnLightKnob, 50);
    lv_obj_set_height(ui_ScnLightKnob, 25);
    lv_obj_set_x(ui_ScnLightKnob, -62);
    lv_obj_set_y(ui_ScnLightKnob, -58);
    lv_obj_set_align(ui_ScnLightKnob, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_ScnLightKnob, LV_STATE_CHECKED);       /// States

    ui_ScnLightPad = lv_switch_create(ui_ScnLightSetting);
    lv_obj_set_width(ui_ScnLightPad, 50);
    lv_obj_set_height(ui_ScnLightPad, 25);
    lv_obj_set_x(ui_ScnLightPad, -62);
    lv_obj_set_y(ui_ScnLightPad, -15);
    lv_obj_set_align(ui_ScnLightPad, LV_ALIGN_CENTER);

    ui_ScnLightSetting_Label4 = lv_label_create(ui_ScnLightSetting);
    lv_obj_set_width(ui_ScnLightSetting_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnLightSetting_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnLightSetting_Label4, 91);
    lv_obj_set_y(ui_ScnLightSetting_Label4, -58);
    lv_obj_set_align(ui_ScnLightSetting_Label4, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnLightSetting_Label4, "Light of Knob");
    lv_obj_set_style_text_decor(ui_ScnLightSetting_Label4, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnLightSetting_Label5 = lv_label_create(ui_ScnLightSetting);
    lv_obj_set_width(ui_ScnLightSetting_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnLightSetting_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnLightSetting_Label5, 91);
    lv_obj_set_y(ui_ScnLightSetting_Label5, -15);
    lv_obj_set_align(ui_ScnLightSetting_Label5, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnLightSetting_Label5, "Light of Pad");

    ui_ScnLightColor = lv_btn_create(ui_ScnLightSetting);
    lv_obj_set_width(ui_ScnLightColor, 50);
    lv_obj_set_height(ui_ScnLightColor, 25);
    lv_obj_set_x(ui_ScnLightColor, -62);
    lv_obj_set_y(ui_ScnLightColor, 28);
    lv_obj_set_align(ui_ScnLightColor, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScnLightColor, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScnLightColor, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScnLightColor, lv_color_hex(0xE91FE9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnLightColor, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnLightSetting_Label1 = lv_label_create(ui_ScnLightSetting);
    lv_obj_set_width(ui_ScnLightSetting_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnLightSetting_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnLightSetting_Label1, 91);
    lv_obj_set_y(ui_ScnLightSetting_Label1, 28);
    lv_obj_set_align(ui_ScnLightSetting_Label1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnLightSetting_Label1, "Select Color");

}
void ui_ScnSelColor_screen_init(void)
{
    ui_ScnSelColor = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnSelColor, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Colorwheel1 = lv_colorwheel_create(ui_ScnSelColor, true);
    lv_obj_set_width(ui_Screen1_Colorwheel1, 180);
    lv_obj_set_height(ui_Screen1_Colorwheel1, 180);
    lv_obj_set_align(ui_Screen1_Colorwheel1, LV_ALIGN_CENTER);
    lv_obj_set_style_arc_width(ui_Screen1_Colorwheel1, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScnSettingKnob_screen_init(void)
{
    ui_ScnSettingKnob = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnSettingKnob, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScnSettingKnob_Arc1 = lv_arc_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSettingKnob_Arc1, 220);
    lv_obj_set_height(ui_ScnSettingKnob_Arc1, 220);
    lv_obj_set_align(ui_ScnSettingKnob_Arc1, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_ScnSettingKnob_Arc1, 0, 360);
    lv_arc_set_value(ui_ScnSettingKnob_Arc1, 90);
    lv_arc_set_bg_angles(ui_ScnSettingKnob_Arc1, 0, 360);
    lv_arc_set_rotation(ui_ScnSettingKnob_Arc1, 270);
    lv_obj_set_style_arc_color(ui_ScnSettingKnob_Arc1, lv_color_hex(0x3B3B3B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ScnSettingKnob_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ScnSettingKnob_Arc1, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ScnSettingKnob_Arc1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScnSettingKnob_Arc1, lv_color_hex(0xE91FE9), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScnSettingKnob_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ScnSettingKnob_Label1 = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSettingKnob_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSettingKnob_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSettingKnob_Label1, -145);
    lv_obj_set_y(ui_ScnSettingKnob_Label1, -60);
    lv_obj_set_align(ui_ScnSettingKnob_Label1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ScnSettingKnob_Label1, "Velocity:");

    ui_ScnSettingKnob_Label2 = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSettingKnob_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSettingKnob_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSettingKnob_Label2, -145);
    lv_obj_set_y(ui_ScnSettingKnob_Label2, -33);
    lv_obj_set_align(ui_ScnSettingKnob_Label2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ScnSettingKnob_Label2, "MagAgl:");

    ui_ScnSettingKnob_Label3 = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSettingKnob_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSettingKnob_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSettingKnob_Label3, -145);
    lv_obj_set_y(ui_ScnSettingKnob_Label3, 51);
    lv_obj_set_align(ui_ScnSettingKnob_Label3, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ScnSettingKnob_Label3, "Mode:");

    ui_ScnSettingKnob_Label4 = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSettingKnob_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSettingKnob_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSettingKnob_Label4, -145);
    lv_obj_set_y(ui_ScnSettingKnob_Label4, -5);
    lv_obj_set_align(ui_ScnSettingKnob_Label4, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ScnSettingKnob_Label4, "KnobAgl:");

    ui_ScnSettingKnob_Label5 = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSettingKnob_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSettingKnob_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSettingKnob_Label5, -145);
    lv_obj_set_y(ui_ScnSettingKnob_Label5, 23);
    lv_obj_set_align(ui_ScnSettingKnob_Label5, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ScnSettingKnob_Label5, "SumAgl:");

    ui_ScnSKnobOrig = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSKnobOrig, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSKnobOrig, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSKnobOrig, 100);
    lv_obj_set_y(ui_ScnSKnobOrig, -61);
    lv_obj_set_align(ui_ScnSKnobOrig, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnSKnobOrig, "123");
    lv_obj_set_style_text_color(ui_ScnSKnobOrig, lv_color_hex(0x0BFF56), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnSKnobOrig, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnSKnobOrig, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnSKnobAdjust = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSKnobAdjust, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSKnobAdjust, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSKnobAdjust, 100);
    lv_obj_set_y(ui_ScnSKnobAdjust, -33);
    lv_obj_set_align(ui_ScnSKnobAdjust, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnSKnobAdjust, "123");
    lv_obj_set_style_text_color(ui_ScnSKnobAdjust, lv_color_hex(0x0BFF56), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnSKnobAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnSKnobAdjust, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnSKnobPosition = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSKnobPosition, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSKnobPosition, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSKnobPosition, 100);
    lv_obj_set_y(ui_ScnSKnobPosition, -5);
    lv_obj_set_align(ui_ScnSKnobPosition, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnSKnobPosition, "123");
    lv_obj_set_style_text_color(ui_ScnSKnobPosition, lv_color_hex(0x0BFF56), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnSKnobPosition, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnSKnobPosition, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnSKnobStrength = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSKnobStrength, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSKnobStrength, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSKnobStrength, 100);
    lv_obj_set_y(ui_ScnSKnobStrength, 23);
    lv_obj_set_align(ui_ScnSKnobStrength, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnSKnobStrength, "123");
    lv_obj_set_style_text_color(ui_ScnSKnobStrength, lv_color_hex(0x0BFF56), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnSKnobStrength, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnSKnobStrength, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnSKnobMode = lv_label_create(ui_ScnSettingKnob);
    lv_obj_set_width(ui_ScnSKnobMode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnSKnobMode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnSKnobMode, 100);
    lv_obj_set_y(ui_ScnSKnobMode, 51);
    lv_obj_set_align(ui_ScnSKnobMode, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ScnSKnobMode, "123");
    lv_obj_set_style_text_color(ui_ScnSKnobMode, lv_color_hex(0x0BFF56), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnSKnobMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnSKnobMode, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScnLayer_screen_init(void)
{
    ui_ScnLayer = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScnLayer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScnVolumeValue1 = lv_label_create(ui_ScnLayer);
    lv_obj_set_width(ui_ScnVolumeValue1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnVolumeValue1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnVolumeValue1, 0);
    lv_obj_set_y(ui_ScnVolumeValue1, -11);
    lv_obj_set_align(ui_ScnVolumeValue1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnVolumeValue1, "2");
    lv_obj_set_style_text_color(ui_ScnVolumeValue1, lv_color_hex(0x34FF46), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScnVolumeValue1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_ScnVolumeValue1, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScnVolumeValue1, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScnVolume_Label1 = lv_label_create(ui_ScnLayer);
    lv_obj_set_width(ui_ScnVolume_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScnVolume_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScnVolume_Label1, 0);
    lv_obj_set_y(ui_ScnVolume_Label1, 27);
    lv_obj_set_align(ui_ScnVolume_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScnVolume_Label1, "Layer");
    lv_obj_set_style_text_font(ui_ScnVolume_Label1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScnClock_screen_init();
    ui_ScnBiliData_screen_init();
    ui_ScnStock_screen_init();
    ui_ScnPhoto_screen_init();
    ui_ScnVolume_screen_init();
    ui_ScnSetting_screen_init();
    ui_ScnLightSetting_screen_init();
    ui_ScnSelColor_screen_init();
    ui_ScnSettingKnob_screen_init();
    ui_ScnLayer_screen_init();
    lv_disp_load_scr(ui_ScnClock);
}
