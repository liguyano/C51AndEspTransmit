#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "SSS.h"
#include "Transport.h"

void Timer0_Init(void)		//5ms@11.0592MHz
{
    AUXR |= 0x80;			//imer clock is 1T mode
    TMOD &= 0xF0;			//Set timer work mode
    TL0 = 0x00;				//Initial timer value
    TH0 = 0x28;				//Initial timer value
    TF0 = 0;				//Clear TF0 flag
    TR0 = 1;				//Timer0 start run
    EA=1;
    ET0=1;
}
void main()
{
    UartInit();
    Tr_init();
    //Timer0_Init();
    UART_SendByte('h');
    UART_SendByte('a');
    UART_SendByte('e');
    UART_SendByte('l');
    UART_SendByte('l');
    UART_SendByte('o');

    while (1)
    {
        UART_SendByte(TR_recv());
      // Delay1000ms();
    }
}
void time0() interrupt NUM1
{
    static uchar t;
    t++;
    if (t>=200)
    {
        UART_SendByte('h');
        UART_SendByte('e');
        UART_SendByte('l');
        UART_SendByte('l');
        UART_SendByte('o');
        TR_send('A');
       // Delay100ms();
        TR_send('B');
        //Delay100ms();
        TR_send('C');
       // Delay100ms();
        TR_send('D');
        t=0;
    }
    TL0 = 0x00;				//Initial timer value
    TH0 = 0x28;				//Initial timer value
}

