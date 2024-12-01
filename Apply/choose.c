#include <REGX52.H>
#include "Matrix.h"
#include "Delay.h"
unsigned char num[]={0x3f,0x06,0x40};

void Choose_digital(unsigned char x,unsigned char num)
{
    switch(x)
    {
        case 7: P2_4=1;P2_3=1;P2_2=1;break;
        case 6: P2_4=1;P2_3=1;P2_2=0;break;
        case 5: P2_4=1;P2_3=0;P2_2=1;break;
        case 4: P2_4=1;P2_3=0;P2_2=0;break;
        case 3: P2_4=0;P2_3=1;P2_2=1;break;
        case 2: P2_4=0;P2_3=1;P2_2=0;break;
        case 1: P2_4=0;P2_3=0;P2_2=1;break;
        case 0: P2_4=0;P2_3=0;P2_2=0;break;
    }
    P0=num;
    Delay(5);
    
}

void Choose_Loop(unsigned char i)
{
    unsigned char j;
    
    for(j=i;j<6;j++)
    {
        Choose_digital(j,num[0]);
    }
    for(j=0;j<i;j++)
    {
         Choose_digital(j,num[2]);
    }

    
}
