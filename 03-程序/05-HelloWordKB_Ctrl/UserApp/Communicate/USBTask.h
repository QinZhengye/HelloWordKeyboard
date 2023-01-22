//
// Created by QZY on 2022/12/4.
//

#ifndef HELLOWORDKB_CTRL_APPUSB_H
#define HELLOWORDKB_CTRL_APPUSB_H

#ifdef __cplusplus
extern "C" {
#endif

#define USB_REPORT_BUFF_SIZE        17

#define USB_HID_REPORT_ID_KEY       1
#define USB_HID_REPORT_ID_MOUSE     2
#define USB_HID_REPORT_ID_VOLUME    3


extern osMessageQueueId_t queueHIDSendHandle;


void USB_Init();
void USB_Task(void *arg);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //HELLOWORDKB_CTRL_APPUSB_H
