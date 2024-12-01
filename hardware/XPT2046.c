#include <REGX52.H>
#include "Delay.h"
sbit XPT_CS = P3^5;
sbit XPT_DCLK = P3^6;
sbit XPT_DIN = P3^4;
sbit XPT_DOUT = P3^7;


void XPT_Start()
{
    XPT_CS = 1;
    XPT_CS = 0;
}

unsigned int XPT_SendCommand(unsigned char Command)
{
    unsigned char i;
    unsigned int Data=0X0000;
    XPT_DCLK = 0;
    for(i=0;i<8;i++)
    {
        XPT_DIN = Command&(0x80>>i);
        XPT_DCLK = 1;
        Delay(1);
        XPT_DCLK = 0;
    }
    XPT_DCLK = 1;
    Delay(1);
    XPT_DCLK = 0;
    for(i=0;i<16;i++)
    {
        if(XPT_DOUT==1){Data|=(0x8000>>i);}
        XPT_DCLK = 1;
        Delay(1);
        XPT_DCLK = 0;  
    }
    XPT_CS = 1;
    if(Command&0x08)
    {
        return Data>>4;
    }
    else
    {
        return Data>>4;
    }
}


