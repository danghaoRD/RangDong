#ifndef __RD_LED_CTR_
#define __RD_LED_CTR_


#include "stm8s.h"
#include "LED.h"
#include "UART.h"
#include "stdio.h"
#include "wifi.h"


#define RD_BID_ON_OFF   0x01
#define RD_BID_MODE     0x02
#define RD_BID_HCL      0x03
#define RD_BID_TOMATO   0x04
#define RD_BID_BAR      0x05
//#define TRUE            1
//#define FALSE           0

typedef struct{
	unsigned char BID;              // loai du lieu muon truyen
	unsigned char Val;              // gia tri
        unsigned char Future[4];
}RD_Touch_Data;

extern RD_Touch_Data    RD_Touch_data1;

extern unsigned char UART3_Buffer_send[64];
extern bool vruc_TOUCH1_Stt;
extern bool vruc_TOUCH2_Stt;
extern bool vruc_TOUCH3_Stt;
extern bool vruc_TOUCH4_Stt;
extern bool vruc_TBAR_Stt;

extern volatile char vrsc_Timer4_Flag;
extern volatile unsigned int  vrui_Timer4_Count;
extern char vrsc_BAR_Start;

extern bool vruc_MODE_Stt ;
extern bool vruc_HCL_Stt;
extern bool vruc_Tomato;
extern unsigned char vruc_OnOff;


extern unsigned int  vruc_TBAR_Value_old;
extern unsigned int  vruc_TBAR_Value_new;

extern volatile uint16_t vruc_DIM;
extern volatile uint16_t vruc_CCT;

// chinhr bam xung 2 kenh ve 0, bh khong su dung
void RangDong_LED_OnOff_Control(void);

void Rangdong_Send_datatouch(void);
void RangDong_System_Proc(void);
void RangDong_Data_touch(void);
void RangDong_Config(void);
void RangDong_touch_PWM(void);
void RangDong_PWM_LED(unsigned int _vrui_Dim, unsigned int _vrui_Cct );
void RangDong_LedBar(unsigned int _LedBar);
void RangDong_ButtonProcess (void);
void RangDong_Stt(void);
#endif