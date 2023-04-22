# C51AndEspTransmit
## update in 令和5年4月22日 9:25:46
delete the code can't be used.
And change the start and end signal.

## update in 令和5年4月16日 16:04:06
run succed. Just need delay slower than the slave.
```c
        Delay10ms();
        RT=0;
        Delay10ms();
```
```c++
  while (!digitalRead(TT))
        {
            //Serial.print('-');
            delay(1);
        }
        Serial.print(digitalRead(RT));
        if (digitalRead(RT))
        {
            re |=(0x80>>i);
        }
        while (digitalRead(TT))
        {
            //Serial.print('\\');
            delay(1);
        }
```
## update in 令和5年4月16日 15:30:05
The time control is correct but the Esp can't read the correct data.
The slave receive the data in the last momentum.
