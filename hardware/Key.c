#include <REGX52.H>
#include "Delay.h"
unsigned char KeyNum()
{
    unsigned char Key=0;
    if(!P3_1){Delay(20);while(!P3_1);Key = 1;Delay(20);}
    if(!P3_0){Delay(20);while(!P3_0);Key = 2;Delay(20);}
    if(!P3_2){Delay(20);while(!P3_2);Key = 3;Delay(20);}
    if(!P3_3){Delay(20);while(!P3_3);Key = 4;Delay(20);}
    return Key;
}
    