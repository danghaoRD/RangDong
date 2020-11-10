#include "Button.h"


//  check Mode+Bar and create PWM
void Button_Onoff(void){
   if(vruc_MODE_Stt == TRUE){
     RangDong_LedBar(vruc_CCT);
     GPIO_WriteHigh(LED_MODE_PORT,LED_MODE_PIN);
     RangDong_PWM_LED(vruc_DIM,vruc_CCT);
     
  }
  else{
     RangDong_LedBar(vruc_DIM);
     GPIO_WriteLow(LED_MODE_PORT,LED_MODE_PIN);
     RangDong_PWM_LED(vruc_DIM,vruc_CCT);
  }
}

//  Check Mode +bar and create PWM
void Button_Mode(void){
  if(vruc_MODE_Stt == TRUE){
     RangDong_LedBar(vruc_CCT);
     GPIO_WriteHigh(LED_MODE_PORT,LED_MODE_PIN);
     RangDong_PWM_LED(vruc_DIM,vruc_CCT);
  }
  else{
     RangDong_LedBar(vruc_DIM);
     GPIO_WriteLow(LED_MODE_PORT,LED_MODE_PIN);
     RangDong_PWM_LED(vruc_DIM,vruc_CCT);
  }
}
void Button_HCL(void){
  if(vruc_HCL_Stt == FALSE){
    GPIO_WriteHigh(LED_HCL_PORT, LED_HCL_PIN);
  }
  else{
    GPIO_WriteLow(LED_HCL_PORT, LED_HCL_PIN);
  }
}

void Button_Tomato(void){
  if(vruc_Tomato == FALSE){
    GPIO_WriteHigh(LED_TOMATO_PORT, LED_TOMATO_PIN);
  }
  else{
    GPIO_WriteLow(LED_TOMATO_PORT, LED_TOMATO_PIN);
  }
}
void Button_TouchBar(void){
  
}

void RangDong_touch_PWM(void){
  if(vruc_MODE_Stt == TRUE){
    vruc_CCT = (unsigned int)vruc_TBAR_Value_new * 55;
    RangDong_PWM_LED(vruc_DIM,vruc_CCT);
    RangDong_LedBar(vruc_CCT);
    mcu_dp_value_update(DPID_TEMP_VALUE,vruc_CCT);
  }
  else{
    vruc_DIM = (unsigned int)vruc_TBAR_Value_new * 55;
    RangDong_PWM_LED(vruc_DIM,vruc_CCT);
    RangDong_LedBar(vruc_DIM);
    mcu_dp_value_update(DPID_BRIGHT_VALUE,vruc_DIM);
  }
}