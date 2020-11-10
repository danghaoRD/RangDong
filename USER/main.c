/**
  ******************************************************************************
  * @file    GPIO_Toggle\main.c
  * @author  MCD Application Team
  * @version V2.0.4
  * @date    26-April-2018
  * @brief   This file contains the main function for GPIO Toggle example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 
/*
 *   UART1 - Touch
 *   UART3 - Wifi
 *   
 */
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_conf.h"
#include "stm8s_tim2.h"
#include "UART.h"
#include "Delay.h"
#include "LED.h"
#include "RD_LED_Ctr.h"
/**
  * @addtogroup GPIO_Toggle
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Evalboard I/Os configuration */


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Delay (uint16_t nCount);
void UART1_Config(void);

/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/



/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

void main(void)  
{
  
  while(!CLK_ICKR_HSIRDY);
  CLK->CKDIVR = 0;
  CLK->PCKENR1 = 0xff;
  CLK->PCKENR2 = 0xff;
  LED_Init();
  LED_PWM_Config();
  Fn_UART_Init();
  enableInterrupts();
  RangDong_Config();
  wifi_protocol_init();
  while (1)
  {
    wifi_uart_service();
    RangDong_System_Proc();                // xu li nut an Touch va dieu khien den
    RD_WIFI_ProcessUpdate();
     checkPWM();
    //Fn_DELAY_Short(1000);
  }

}

void checkPWM()
{
    if(vrui_RealYellow_Pre != vrui_RealYellow)
  {
    //  delay timer 3  voi 10 unit
      if(vrui_Timer4_Count >=10)
      {
        vrui_Timer4_Count=0; // reset Timer
        
          // Neu muon anh sang tang len
          if( vrui_RealYellow_Pre < vrui_RealYellow)  
          {
            vrui_RealYellow_Pre++;
          }
          
          // Neu muon anh sang giam di
          if( vrui_RealYellow_Pre > vrui_RealYellow)  
          {
            vrui_RealYellow_Pre--;
          } 
      }
  }
  TIM2_SetCompare1(vrui_RealYellow_Pre);
   TIM2_SetCompare3(_vrui_Dim - vrui_RealYellow_Pre);
}
/**
  * @brief Delay
  * @param nCount
  * @retval None
  */
void Delay(uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
