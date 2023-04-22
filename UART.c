#include "UART.h"

/**
  * @brief  串口初始化，115200bps@12.000MHz
  * @param  无
  * @retval 无
  */
void UartInit(void)		//115200bps@11.0592MHz
{
    PCON &= 0x7F;		//Baudrate no doubled
    SCON = 0x50;		//8 bits and variable baudrate
    AUXR |= 0x40;		//imer clock is 1T mode
    AUXR &= 0xFE;		//UART 1 use Timer1 as baudrate generator
    TMOD &= 0x0F;		//Set timer work mode
    TMOD |= 0x20;		//Set timer work mode
    TL1 = 0xFD;			//Initial timer value
    TH1 = 0xFD;			//Set reload value
    ET1 = 0;			//Disable Timer%d interrupt
    TR1 = 1;			//Timer1 start run
    EA=1;
    ES=1;
}




/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
void UART_SendString(const char * str)
{
    char* t=str;

    do {
        UART_SendByte(*t);
        t++;
    } while (t!='\0');


}