#include <REGX52.H>
#include "Matrix.h"
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"

sbit Buzzer=P2^5;
unsigned char flag,Count=0;
code unsigned int music[]=
{
    64655,64751,64837,64913,64981,65042,65070
};
unsigned char Lock_Init()
{
    unsigned char i,keynum,Password[6],key[7]={1,2,3,4,5,6,0};
    keynum=Matrix_scan();
    if(keynum<=10 && i<6)
    {
        Password[i]=keynum%10;
        LCD_ShowChar(2,i+1,'*');
        i++; 
    }
    else if(keynum==11&&i>0)
    {
            i--;
            LCD_ShowChar(2,i+1,'0');
            
    }
    else if(keynum==12&&i==6)
    {
            for(i;i>0;i--)
            {
                if(Password[i-1]==key[i-1])key[6]+=1;
            }
            if(key[6]==6)
            {
                    Timer0_Init();
                    LCD_ShowString(2,9,"True!");
                    flag=1;                             //标记声音
                                    
                    for(i=7;i>0;i--)
                    {                                   //改变音调
                        Delay(300);
                        Count++;
                    }
                    flag=0;
                    Delay(1000);
                    LCD_ShowString(2,1,"               ");
                    LCD_ShowString(1,1,"               ");
                    TR0=0;
                    Delay(100);
                    return 1;
            }
            else
            {
                    flag=2;
                    LCD_ShowString(2,8,"False.");
                    Delay(1000);
                    LCD_ShowString(2,8,"      ");
                    key[6]=0;
                    LCD_ShowNum(2,1,0,6);
                    
            }  
    }
    return 0;
}
void Timer0_Rountine() interrupt 1
{
    TL0 = 0x66;		//设置定时初值
	TH0 = 0xFc;		//设置定时初值
    if(flag==1)
    {
        Buzzer=!Buzzer;
        TL0=music[Count]%256;
        TH0=music[Count]/256;
    }
}