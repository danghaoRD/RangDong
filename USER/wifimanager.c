
#include "stm8s.h"
#include "wifimanager.h"
#include "RD_LED_Ctr.h"

unsigned char vruc_WIFI_OnOffUpdate;
unsigned char vruc_WIFI_DIMUpdate;
unsigned char vruc_WIFI_CCTUpdate;

void RD_WIFI_ProcessUpdate(void){
  if(vruc_WIFI_OnOffUpdate){
    vruc_WIFI_OnOffUpdate = 0;                   // reset  
    Fn_UART1_Pustf("Process 1\n");              // gui ve uart 1 ????
    
    if(vruc_OnOff == TRUE){                     // check on/off
      GPIO_WriteLow(LED_ON_OFF_PORT,LED_ON_OFF_PIN);
      if(vruc_MODE_Stt == TRUE){                // check Mode
        RangDong_LedBar(vruc_DIM);              //  chinh led tren nut
      }
      else{
        RangDong_LedBar(vruc_CCT);                      
      }
      RangDong_PWM_LED(vruc_DIM,vruc_CCT);      //  chinh led tren nut
    }
    else{                                       // off thi tat all
      GPIO_WriteHigh(LED_ON_OFF_PORT,LED_ON_OFF_PIN);
      RangDong_LedBar(0);
      RangDong_PWM_LED(0,0);
    }
  }
  
  if(vruc_WIFI_DIMUpdate){
    vruc_WIFI_DIMUpdate = 0;
    Fn_UART1_Pustf("Process 2\n");
    
    if( vruc_MODE_Stt == TRUE){
      RangDong_LedBar(vruc_DIM);
    }
    RangDong_PWM_LED(vruc_DIM,vruc_CCT);
  }
  
  if(vruc_WIFI_CCTUpdate){
    vruc_WIFI_CCTUpdate = 0;
    Fn_UART1_Pustf("Process 3\n");
    
    if( vruc_MODE_Stt == FALSE){
      RangDong_LedBar(vruc_CCT);
    }
    RangDong_PWM_LED(vruc_DIM,vruc_CCT);
  }
}
