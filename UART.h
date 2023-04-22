#ifndef __UART_H__
#define __UART_H__
#include "SSS.h"
#include <STC89C5xRC.H>
void UartInit(void);	//115200bps@11.0592MHz
void UART_SendByte(unsigned char Byte);
void UART_SendString(const char * str);

#endif
