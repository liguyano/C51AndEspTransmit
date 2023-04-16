#include<STC15F2K60S2.H>
#include <INTRINS.H>
#include "SSS.h"
#include "Transport.h"
unsigned char  SMG_duanma[18]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
                               0x80,0x90,0x88,0x80,0xc6,0xc0,0x86,0x8e,
                               0xbf,0x7f};
void SelectHC573(unsigned char channel)/*74HC573锁存器*/
{
    switch(channel)
    {
        /*
         * &0x1f 将前三位置0
         * | 0x80 将第一位置1
         * | 0xa0 1010 0000
         * */

        case 4:
            P2 = (P2 & 0x1f) | 0x80;
            break;
        case 5:
            P2 = (P2 & 0x1f) | 0xa0;
            break;
        case 6:
            P2 = (P2 & 0x1f)| 0xc0;//1100
            break;
        case 7:
            P2 = (P2 & 0x1f) | 0xe0;
            break;
    }
}


void DIAPlaySMG_Bit(unsigned char value, unsigned char pos)/*数码管显示*/
{
    P2&=0x1f;
    P0 = 0x00;
    /*段选*/
    SelectHC573(6);
    P0 = 0x01 << pos;
    P0=P0;
    P2&=0x1f;
    /*位选*/
    SelectHC573(7);
    P0 = value;
    P2&=0x1f;
}

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
    P32=1;
    UartInit();
    P33=1;//set a high firstly or that can't read
    Timer0_Init();
    Tr_init();

    while (1)
    {

        sn(0,10);
        sn(1,P32);
        sn(2,P33);
    }
}
void time0() interrupt NUM1
{
    static uchar t;
    t++;
    if (t>=200)
    {
        TR_send(89);
        t=0;
    }
    TL0 = 0x00;				//Initial timer value
    TH0 = 0x28;				//Initial timer value
}

