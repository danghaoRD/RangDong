#include "stm8s.h"
#include "UART.h"


char UART1_Buffer[32];                  // recever
char UART1_OutBuffer[32];
unsigned int UART1_Count = 0;
char UART1_Start;
char UART1_Done;


void Fn_UART_Init (void)
{
   
    UART1_DeInit();
    UART3_DeInit();
    
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, ENABLE);
    UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D,UART1_STOPBITS_1, UART1_PARITY_NO,
                     UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
    UART1_Cmd(ENABLE);
    enableInterrupts();
    
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART3, ENABLE);
    UART3_Init((uint32_t)9600, UART3_WORDLENGTH_8D,UART3_STOPBITS_1, UART3_PARITY_NO,
               UART3_MODE_TXRX_ENABLE);
    UART3_ITConfig(UART3_IT_RXNE_OR, ENABLE);
    UART3_Cmd(ENABLE);
}


void Fn_UART1_SendChar (char _vruc_Data)
{
    UART1->DR = _vruc_Data;
    while(!(UART1->SR & (1<<6)));
}
          


void Fn_UART1_Pustf (char *_vruc_String)
{
    while(*_vruc_String)
    {
        Fn_UART1_SendChar(*_vruc_String);
        _vruc_String++;
    }
}


void Fn_UART3_SendChar (char _vruc_Data)
{
    UART3_SendData8(_vruc_Data);
    while(!UART3_GetFlagStatus(UART3_FLAG_TC));
}
          

