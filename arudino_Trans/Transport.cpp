//
// Created by kurum on 西暦2023年4月12日.
//

#include "Transport.h"

Transport::Transport(unsigned char T, unsigned char R):TT(T),RT(R) {
    pinMode(TT,OUTPUT);
    digitalWrite(TT,HIGH);
    digitalWrite(RT,HIGH);
    pinMode(RT,INPUT);
}

void Transport::send(unsigned char dat) {
    digitalWrite(TT,HIGH);
    delay(1);
    digitalWrite(TT,LOW);
    pinMode(RT,OUTPUT);
    digitalWrite(RT,LOW);
    for (int i = 0; i < 8; ++i) {
        digitalWrite(TT,dat&(0x80>>i));
        digitalWrite(RT,HIGH);
        delay(1);
        digitalWrite(RT,LOW);
        delay(1);
    }
    pinMode(TT,OUTPUT);
    digitalWrite(TT,HIGH);
    digitalWrite(RT,LOW);
    pinMode(RT,INPUT);
    delay(10);
}

unsigned char Transport::recv() {
    this->wait_send();
    unsigned char re=0;
    pinMode(TT,INPUT);
    for (int i = 0; i < 8; ++i) {
      //  Serial.println("wait tt to be high");
        while (!digitalRead(TT))
        {
            //Serial.print('-');
            delay(1);
        }
       // Serial.println("tt is high");
        //Serial.print(digitalRead(RT));
        if (digitalRead(RT))
        {
            re |=(0x80>>i);
        }
        while (digitalRead(TT))
        {
            //Serial.print('\\');
            delay(1);
        }
    }
    //Serial.println(' ');
    pinMode(TT,OUTPUT);
    digitalWrite(TT,HIGH);
    digitalWrite(RT,LOW);
    pinMode(RT,INPUT);
    return re;
}

void Transport::wait_send() {
    //Serial.println("wait to be high");
    while (!digitalRead(RT)){
        delay(1);
    }
   // Serial.println("wait to be low");
    while (digitalRead(RT)){
        delay(1);
    }
}


