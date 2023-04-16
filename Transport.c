//
// Created by kurum on 西暦2023年4月12日.
//

#include "Transport.h"
void Delay10ms()		//@11.0592MHz
{
    unsigned char i, j;

    i = 18;
    j = 235;
    do
    {
        while (--j);
    } while (--i);
}

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
        Delay10ms();
        RT=0;
        Delay10ms();
        UART_SendByte(TT);
    }
    Tr_init();
}
void Delay100ms()		//@11.0592MHz
{
    unsigned char i;

    _nop_();
    i = 43;
    while (--i);
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