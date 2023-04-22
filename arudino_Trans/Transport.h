//
// Created by kurum on 西暦2023年4月12日.
//

#ifndef COLLISIONMODE_TRANSPORT_H
#define COLLISIONMODE_TRANSPORT_H

#include "Arduino.h"
class Transport {
public:
    Transport(unsigned char T,unsigned char R);
    void wait_send();
    void send(unsigned char dat);
    unsigned char recv();
private:
    unsigned char TT;
    unsigned char RT;
};


#endif //COLLISIONMODE_TRANSPORT_H
