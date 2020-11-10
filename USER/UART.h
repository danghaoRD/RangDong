

#ifndef _UART_
#define _UART_


#define UART_BAURATE    9600


extern char UART1_Buffer[32];
extern char UART1_OutBuffer[32];
extern unsigned int UART1_Count;
extern char UART1_Start;
extern char UART1_Done;



extern void Fn_UART_Init (void);

extern void Fn_UART1_SendChar (char _vruc_Data);
extern void Fn_UART1_Pustf (char *_vruc_String);
extern void Fn_UART3_SendChar (char _vruc_Data);
extern void Fn_UART3_Pustf (char *_vruc_String);


#endif