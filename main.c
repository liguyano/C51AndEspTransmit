#include<STC15F2K60S2.H>
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
    P32=1;
    UartInit();
    Timer0_Init();
    P33=1;//set a high firstly or that can't read
   // Timer0_Init();
    Tr_init();
    while (1)
    {
    }
}
void time0() interrupt NUM1
{
    static uchar t;
    t++;
    if (t>=200)
    {

        t=0;
    }
    TL0 = 0x00;				//Initial timer value
    TH0 = 0x28;				//Initial timer value
}

