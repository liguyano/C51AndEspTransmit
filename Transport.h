//
// Created by kurum on 西暦2023年4月12日.
//

#ifndef CAR_DRIVER_TRANSPORT_H
#define CAR_DRIVER_TRANSPORT_H
#include "STC15F2K60S2.H"
#define RT P32
#define TT P33
void Tr_init();
void TR_send(unsigned char dat);
unsigned char TR_recv();
#endif //CAR_DRIVER_TRANSPORT_H
