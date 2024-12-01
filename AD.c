#include <REGX52.H>
#include <XPT2046.h>
#include "LCD1602.h"
#include "Delay.h"
#define XPT2046_VBAT_12 0xA4
#define XPT2046_VBAT_8  0xAC
sbit LED = P2^3;
unsigned int Value1;
unsigned char GR[] = {5,10};
void GR_Get()
{

    XPT_Start();
    Value1 = XPT_SendCommand(XPT2046_VBAT_12);
    LCD_ShowString(1,8,"GR:");
    LCD_ShowString(1,12,"LED:");
    Value1=(Value1/4096.0)*100;
    if(!LED)
    {
        LCD_ShowString(2,12,"ON ");
    }
    else
    {
        LCD_ShowString(2,12,"OFF");
    }
    LCD_ShowNum(2,8,Value1,3);
    Delay(10);
}

void LED_State()
{
    
    XPT_Start();
    Value1 = XPT_SendCommand(XPT2046_VBAT_12);
    Value1=(Value1/4096.0)*100;
    if(Value1<GR[0])
    {
         LED = 0;
    }
    else if(Value1>GR[1])
    {
         LED = 1;
    }
}

