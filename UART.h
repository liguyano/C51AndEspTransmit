#ifndef __UART_H__
#define __UART_H__
#include "SSS.h"
#include <STC15F2K60S2.H>
void UartInit(void);	//115200bps@11.0592MHz
void UART_SendByte(unsigned char Byte);

#endif
