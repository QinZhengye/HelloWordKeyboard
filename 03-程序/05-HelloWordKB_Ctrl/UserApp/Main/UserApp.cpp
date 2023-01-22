//
// Created by QZY on 2022/11/20.
//

#include <stdio.h>
#include "UserApp.h"
#include "hardware.h"
#include "KeyboardControl.h"
#include "KnobTask.h"
#include "GUITask.h"
#include "USBTask.h"
#include "ControlTask.h"
#include "LightTask.h"
#include "Clock.h"
#include "StockManager.h"
#include "Bilibili.h"
#include "Monitor.h"


osSemaphoreId semSPI3;
bool SystemReady = false;


void Object_Init();
void Task_Init();
void Task_Create();

void UserMain()
{
    printf("Hardware initialize\r\n");
    hardware_Init();

    printf("Task initialize\r\n");
    Object_Init();
    Task_Init();
    printf("Task start\r\n");
    Task_Create();

    // 退出
    osThreadExit();
}

void Object_Init()
{
    osSemaphoreDef(semSPI3);
    semSPI3 = osSemaphoreNew(1, 1, osSemaphore(semSPI3));
}

void Task_Init()
{
    AppEvent_Init();
    Clock_Init();
    StockMgr_Init();
    Bilibili_Init();
    GUI_Init();
    Control_Init();
    USB_Init();
    Knob_Init();
    Light_Init();
    Keyboard_Init();    // Keyboard在Knob之后
}

void Task_Create()
{
    // Monitor
    const osThreadAttr_t monitorTask_attributes = {
            .name = "MonitorTask",
            .stack_size = 1024 * 2,
            .priority = (osPriority_t) osPriorityLow1,
    };
    osThreadNew(Monitor_Task, nullptr, &monitorTask_attributes);

    // GUI
    const osThreadAttr_t guiTask_attributes = {
            .name = "GUITask",
            .stack_size = 1024 * 8,
            .priority = (osPriority_t) osPriorityAboveNormal1,
    };
    osThreadNew(GUI_Task, nullptr, &guiTask_attributes);

    // Clock
    const osThreadAttr_t clockTask_attributes = {
            .name = "ClockTask",
            .stack_size = 512,
            .priority = (osPriority_t) osPriorityLow3,
    };
    osThreadNew(Clock_Task, nullptr, &clockTask_attributes);

    // USB收发
    const osThreadAttr_t usbTask_attributes = {
            .name = "USBTask",
            .stack_size = 1024 * 1,
            .priority = (osPriority_t) osPriorityHigh1,
    };
    osThreadNew(USB_Task, nullptr, &usbTask_attributes);

    // 键盘扫描
    const osThreadAttr_t keyboardTask_attributes = {
            .name = "keyboardTask",
            .stack_size = 1024 * 2,
            .priority = (osPriority_t) osPriorityHigh2,
    };
    osThreadNew(Keyboard_Task, nullptr, &keyboardTask_attributes);

    // 灯效 RGB
    const osThreadAttr_t lightTask_attributes = {
            .name = "RGBTask",
            .stack_size = 1024 * 1,
            .priority = (osPriority_t) osPriorityHigh3,
    };
    osThreadNew(Light_Task, nullptr, &lightTask_attributes);

    // 逻辑控制
    const osThreadAttr_t controlTask_attributes = {
            .name = "ControlTask",
            .stack_size = 1024 * 4,
            .priority = (osPriority_t) osPriorityAboveNormal,
    };
    osThreadNew(Control_Task, nullptr, &controlTask_attributes);

    // 旋钮 Knob Foc
    const osThreadAttr_t knobTask_attributes = {
            .name = "KnobTask",
            .stack_size = 1024 * 3,
            .priority = (osPriority_t) osPriorityRealtime, // robot control thread is critical, should be the highest
    };
    osThreadNew(Knob_Task, nullptr, &knobTask_attributes);
}
