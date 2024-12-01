#include <REGX52.H>
#include "Delay.h"
unsigned char Matrix_scan()
{
    unsigned char keynum;//给keynum 0否则无按键按下时不返回值
    P1=0xff;
    P1_3=0;
    if(!P1_5){Delay(10);while(!P1_5);Delay(10);keynum=9;}
    if(!P1_6){Delay(10);while(!P1_6);Delay(10);keynum=5;}
    if(!P1_7){Delay(10);while(!P1_7);Delay(10);keynum=1;}
    
    P1=0xff;
    P1_2=0;
    if(!P1_5){Delay(10);while(!P1_5);Delay(10);keynum=10;}
    if(!P1_6){Delay(10);while(!P1_6);Delay(10);keynum=6;}
    if(!P1_7){Delay(10);while(!P1_7);Delay(10);keynum=2;}
    
    P1=0xff;
    P1_1=0;
    if(!P1_5){Delay(10);while(!P1_5);Delay(10);keynum=11;}
    if(!P1_6){Delay(10);while(!P1_6);Delay(10);keynum=7;}
    if(!P1_7){Delay(10);while(!P1_7);Delay(10);keynum=3;}
    
    P1=0xff;
    P1_0=0;
    if(!P1_5){Delay(10);while(!P1_5);Delay(10);keynum=12;}
    if(!P1_6){Delay(10);while(!P1_6);Delay(10);keynum=8;}
    if(!P1_7){Delay(10);while(!P1_7);Delay(10);keynum=4;}
    
    return keynum;
}
    