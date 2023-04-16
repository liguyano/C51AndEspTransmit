//
// Created by kurum on 西暦2023年4月12日.
//

#include "Transport.h"
void Tr_init()
{
    TT=0;
    RT=0;
}
void TR_send(unsigned char dat)
{
    unsigned char i;
    TT=1;
    while (!RT);//wait for receive
    for (i=0;i<8;i++)
    {
        TT=dat&(0x80>>i);
        RT=1;
        RT=0;
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