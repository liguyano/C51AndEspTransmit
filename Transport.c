//
// Created by kurum on 西暦2023年4月12日.
//

#include "Transport.h"

void Delay1000ms()		//@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    i = 8;
    j = 1;
    k = 243;
    do
    {
        do
        {while (--k);
        } while (--j);
    } while (--i);
}
void Tr_init()
{
    TT=1;
    RT=1;
}
void TR_send(unsigned char dat)
{
    unsigned char i;
    TT=0;
    RT=1;
    while (RT);//wait for receive
    RT=0;
    for (i=0;i<8;i++)
    {
        TT=dat&(0x80>>i);
        RT=1;
        RT=0;
        UART_SendByte(TT);
        Delay1000ms();
    }
    Tr_init();
}
unsigned char TR_recv()
{unsigned char re,i;
    TT=0;// ready to receive
    for (i=0;i<8;i++)
    {
        while (!TT);
        if (RT)
        {
            re |= (0x80>>i);
        }
    }
    Tr_init();
    return re;
}