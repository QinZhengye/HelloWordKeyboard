//
// Created by QZY on 2022/12/4.
//
#include <stdio.h>
#include <Platform/Sensor/Encoder/encoder.h>
#include <Platform/Driver/driver.h>
#include "KnobTask.h"
#include "timer.hpp"
#include "cmsis_os2.h"
#include "cmsis_os.h"


KnobSimulator knob;         // 旋钮
Motor motor = Motor(7);     // 电机
Encoder encoder(&hspi2);    // 编码器
Driver driver(12);          // 驱动器
Timer timerKnobLoop(&htim7, 5000);
bool IsKnobTaskReady = false;
osThreadId_t knobThreadID;

void OnTimerCallback();


void Knob_Init()
{
    // 初始化旋钮
    motor.AttachDriver(&driver);
    motor.AttachEncoder(&encoder);
    knob.Init(&motor);
    knob.SetEnable(true);
    knob.SetMode(KnobSimulator::MODE_ENCODER);

    timerKnobLoop.SetCallback(OnTimerCallback);
}

void Knob_Start()
{
    timerKnobLoop.Start();
}

void Knob_Task(void *arg)
{
    knobThreadID = osThreadGetId();
    IsKnobTaskReady = true;
    printf("Knob_Task ready\r\n");
    while (1)
    {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        knob.Tick();
    }
}

/* Timer Callbacks -------------------------------------------------------*/

void OnTimerCallback()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // Wake & invoke thread IMMEDIATELY.
    vTaskNotifyGiveFromISR(TaskHandle_t(knobThreadID), &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
