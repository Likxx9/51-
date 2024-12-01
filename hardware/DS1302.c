#include <REGX52.H>
#include "LCD1602.h"
sbit DS_CE = P3^5;
sbit DS_SDA = P3^4;
sbit DS_SCLK = P3^6;

#define DS1302_SECOND  0x80
#define DS1302_MINUTE  0x82
#define DS1302_HOUR  0x84
#define DS1302_DATE 0x86
#define DS1302_MONTHE  0x88
#define DS1302_DAY  0x8A
#define DS1302_YEAR  0x8C
#define DS1302_WP  0x8E                 //写保护寄存器地址

unsigned char Time_D[] = {24,1,1,23,59,55};   //要转换成BCD码

 unsigned char HCD(unsigned char H)
{
    return H/16*10+H%16;
}

void DS1302_Init()
{
    DS_CE = 0;
    DS_SCLK = 0;
}

void DS1302_Write(unsigned char Command,Data)
{
    unsigned char i;
    DS_CE = 1;
    for(i=0;i<8;i++)
    {
        DS_SDA = Command&(0x01<<i);
        DS_SCLK = 1;
        DS_SCLK = 0;
    }
    for(i=0;i<8;i++)
    {
        DS_SDA = Data&(0x01<<i);
        DS_SCLK = 1;
        DS_SCLK = 0;
    }
    DS_CE = 0;
    DS_CE = 1;
}

unsigned char DS1302_Read(unsigned char Command)
{
    unsigned char i,Data=0x00;
    Command|=0x01;                          //读时序指令在写上加0x01
    DS_CE = 1;
    for(i=0;i<8;i++)
    {
        DS_SDA = Command&(0x01<<i);
        DS_SCLK = 0;
        DS_SCLK = 1;
    }
    for(i=0;i<8;i++)
    {
        DS_SCLK = 1;
        DS_SCLK = 0;
        if(DS_SDA)
        {
            Data|=(0x01<<i);
        }
    }
    DS_CE = 0;
    DS_SDA = 0;
    DS_CE = 1;
    return Data;
}

void DS1302_Set()
{
    DS1302_Write(DS1302_WP,0x00);
    DS1302_Write(DS1302_YEAR,(Time_D[0]/10*16+Time_D[0]%10));
    DS1302_Write(DS1302_MONTHE,(Time_D[1]/10*16+Time_D[1]%10));
    
    DS1302_Write(DS1302_DATE,(Time_D[2]/10*16+Time_D[2]%10));
    DS1302_Write(DS1302_HOUR,(Time_D[3]/10*16+Time_D[3]%10));
    DS1302_Write(DS1302_MINUTE,(Time_D[4]/10*16+Time_D[4]%10));
    DS1302_Write(DS1302_SECOND,(Time_D[5]/10*16+Time_D[5]%10));
    DS1302_Write(DS1302_WP,0x80);
}
    
void DS1302_Get()
{
    Time_D[0]=HCD(DS1302_Read(DS1302_YEAR));
    Time_D[1]=HCD(DS1302_Read(DS1302_MONTHE));
    Time_D[2]=HCD(DS1302_Read(DS1302_DATE));
    Time_D[3]=HCD(DS1302_Read(DS1302_HOUR));
    Time_D[4]=HCD(DS1302_Read(DS1302_MINUTE));
    Time_D[5]=HCD(DS1302_Read(DS1302_SECOND));
}

void Time_Show()
{
    LCD_ShowString(2,1,"  -       :  :  ");
    LCD_ShowNum(2,1,Time_D[0],2);
    LCD_ShowNum(2,4,Time_D[1],2);
    LCD_ShowNum(2,6,Time_D[2],2);
    LCD_ShowNum(2,9,Time_D[3],2);
    LCD_ShowNum(2,12,Time_D[4],2);
    LCD_ShowNum(2,15,Time_D[5],2);
}
    
    