//
// Created by QZY on 2022/12/4.
//
#include "UserApp.h"
#include "KeyboardControl.h"
#include "USBTask.h"
#include "cmsis_os2.h"
#include "usb_device.h"
#include "usbd_custom_hid_if.h"

/* Definitions for queueHIDSend */
typedef StaticQueue_t osStaticMessageQDef_t;
osMessageQueueId_t queueHIDSendHandle;
uint8_t myHIDSendBuffer[4 * CKeyboardControler::HID_REPORT_SIZE];
osStaticMessageQDef_t queueHIDSendControlBlock;
const osMessageQueueAttr_t queueHIDSend_attributes = {
        .name = "queueKeyboardSwitch",
        .cb_mem = &queueHIDSendControlBlock,
        .cb_size = sizeof(queueHIDSendControlBlock),
        .mq_mem = &myHIDSendBuffer,
        .mq_size = sizeof(myHIDSendBuffer)
};

uint8_t HIDSendBuff[CKeyboardControler::HID_REPORT_SIZE];

void USB_Init()
{
    queueHIDSendHandle = osMessageQueueNew(4, CKeyboardControler::HID_REPORT_SIZE, &queueHIDSend_attributes);
}

void USB_Task(void *arg)
{
    printf("USB_Task ready\r\n");
    while (!SystemReady)
        osDelay(10);

    while (1)
    {
        uint16_t len = CKeyboardControler::HID_REPORT_SIZE;
        if (osMessageQueueGet(queueHIDSendHandle, HIDSendBuff, 0, osWaitForever) == osOK)
        {
            while (USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HIDSendBuff, len) != USBD_OK
                    && HIDSendBuff[0] != CKeyboardControler::HID_KEY_REPORT_ID)
            {
                osDelay(1);
            }
        }
    }
}

extern "C"
void HID_RxCpltCallback(uint8_t *_data) {

}
