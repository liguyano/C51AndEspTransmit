//
// Created by kurum on 西暦2023年4月12日.
//

#ifndef CAR_DRIVER_TRANSPORT_H
#define CAR_DRIVER_TRANSPORT_H
#include "STC15F2K60S2.H"
#include "INTRINS.H"
#include "UART.h"
#include "SSS.h"
#define sn(p,v) DIAPlaySMG_Bit(SMG_duanma[v],p); Delay10ms()
#define snd(p,v) DIAPlaySMG_Bit(SMG_duanma[v]&0x7f,p); Delay10ms()
#define RT P32
#define TT P33

        /*用于数码管段选*/

        void Tr_init();
void Delay10ms();
void Delay100ms();
        void TR_send(unsigned char dat);
unsigned char TR_recv();
void Delay1000ms();
#endif //CAR_DRIVER_TRANSPORT_H
