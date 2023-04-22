#include <Arduino.h>
#include "Transport.h"
Transport tr(5,16);
unsigned char i=0;
void setup()
{
    Serial.begin(115200);
    Serial.println("started");
    //pinMode(16,OUTPUT);
}
void loop()
{
    delay(1000);
Serial.println("Send");
tr.send('a');
tr.send('b');
tr.send('c');
}