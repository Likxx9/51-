#include <REGX52.H>
#include "Delay.h"
sbit LCD_RS = P2^6;
sbit LCD_RW = P2^5;
sbit LCD_EN = P2^7;
#define Receive P0

void LCD_W_Cmd(unsigned char cmd)
{
    
    LCD_RS=0;
    LCD_RW=0;
    LCD_EN=0;
    Receive=cmd;
    LCD_EN=1;
    Delay(1);
    LCD_EN=0;
    Delay(1);
}
void LCD_W_Data(unsigned char Data)
{
    LCD_RS=1;
    LCD_RW=0;
    LCD_EN=0;
    Receive=Data;
    LCD_EN=1;
    Delay(1);
    LCD_EN=0;
    Delay(1);
}
void LCD1602_Init()
{
    LCD_W_Cmd(0x38);
    LCD_W_Cmd(0x06);
    LCD_W_Cmd(0x0c);
    LCD_W_Cmd(0x01);
}
void LCD_Cursor(unsigned char Line,unsigned char Column)
{
    if(Line==1)
    {
        LCD_W_Cmd(0x80|(Column-1));
    }
    else if(Line==2)
    {
        LCD_W_Cmd(0xC0|(Column-1));
    }
}

void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)
{
    LCD_Cursor(Line,Column);
    LCD_W_Data(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char *String )
{
    unsigned char i;
    LCD_Cursor(Line,Column);
    for(i=0;String[i]!='\0';i++)
    {
        LCD_W_Data(String[i]);
    }
}

unsigned int Pow(int x,int y)
{
    unsigned char i;
    int res=1;
    for(i=0;i<y;i++)
    {
        res*=x;
    }
    return res;
}

void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int num,unsigned char Length)
{
     unsigned char i;
    LCD_Cursor(Line,Column);
    for(i=Length;i>0;i--)
    {
        LCD_W_Data(num/Pow(10,i-1)%10+'0');
        
    }
}

void LCD_ShowSignNum(unsigned char Line,unsigned char Column, int num,unsigned char Length)
{
    unsigned char i;
    unsigned char unnum;
    LCD_Cursor(Line,Column);
    if(num>0)
    {
            LCD_W_Data('+');
            unnum=num;
    }
    else
    {
            LCD_W_Data('-');
            unnum=-num;
    }
    for(i=Length;i>0;i--)
    {
        LCD_W_Data(unnum/Pow(10,i-1)%10+'0'); 
    }
}