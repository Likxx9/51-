#include <REGX52.H>
#include "LCD1602.h"
#include "Lock.h"
#include "Delay.h"
#include "RTS.h"
#include "DS1302.h"
#include "Key.h"
#include "AD.h"
#include "Time0.h"
sbit PWM = P2^4;
unsigned char Key,Count1=0,Count2=0,Num1=0;
unsigned char Angle=0;
void main()
{

    unsigned char Flag=1;
    
    LCD1602_Init();
    DS1302_Init();
    
    DS1302_Set();
    LCD_ShowString(1,1,"Enter Password:");
    LCD_ShowNum(2,1,0,6);
    
    while(1)
    {
        if(!Flag)
        {
            Flag=Lock_Init();
        }
        else if(Flag==1)
        {
            
            Key = KeyNum();
            if(Key==1)
            {
                Count1++;
                Count1%=3;     
                LCD_ShowString(1,1,"                ");
                LCD_ShowString(2,1,"                ");
            }
            if(Count1==0)
                {
                    LCD_ShowString(1,1,"Welcome Home ! ");
                    LCD_ShowNum(1,15,Count2,2);
                    DS1302_Get();
                    Time_Show();
                    Delay(500);

                    if(Key==2)
                    {
                        Count2++;
                        Count2%=6;
                    }
                    if(Key==3)
                    {
                        Time_D[Count2]--;
                        
                        if(Time_D[0]>99){Time_D[0]=0;}
                        if(Time_D[1]>12){Time_D[1]=0;}
                        if(Time_D[2]>30){Time_D[2]=0;}
                        if(Time_D[3]>23){Time_D[3]=0;}
                        DS1302_Set();
                    }
                    if(Key==4)
                    {
                        Time_D[Count2]++;
                        
                        if(Time_D[0]>99){Time_D[0]=0;}
                        if(Time_D[1]>12){Time_D[1]=0;}
                        if(Time_D[2]>30){Time_D[2]=0;}
                        if(Time_D[3]>23){Time_D[3]=0;}
                        DS1302_Set();
                    }
                }
                else if(Count1==1)
                {
                    RTS();                          //温度
                    GR_Get();
                    if(Key==2)
                    {
                        LED=~LED;
                    }

                }
                else if(Count1==2)
                {
                    if(Key==2)
                    {
                        Count2++;
                        Count2%=3;
                        LCD_ShowNum(1,16,Count2,1);
                    }
                    if(Key==3 && Count2<2)
                    {
                        GR[Count2]--;
                        if(GR[Count2]>99){GR[Count2]=0;}
                    }
                    if(Key==4 && Count2<2)
                    {
                        GR[Count2]++;
                        if(GR[Count2]>99){GR[Count2]=0;}
                    }
                    if(Count2>=2 && Key==3)
                    {
                        Angle--;
                        Angle%=3;
                        Timer1_Init();
                        Delay(200);
                        EA=0;
                    }
                    if(Count2>=2 && Key==4)
                    {
                        Angle++;
                        Angle%=3;
                        Timer1_Init();
                        Delay(200);
                        EA=0;
                    }
                    LCD_ShowString(2,1,"GRL:");
                    LCD_ShowNum(2,5,GR[0],2);
                    LCD_ShowString(1,1,"GRH:");
                    LCD_ShowNum(1,5,GR[1],2);
                    
                    LCD_ShowString(1,8,"Win:");
                    LCD_ShowString(2,8,"Angle:");
                    LCD_ShowNum(2,14,Angle*45,3);
                    if(Angle==0)
                    {
                        LCD_ShowString(1,12,"OFF");
                    }
                    else if(Angle==1)
                    {
                        LCD_ShowString(1,12,"HON");
                    }
                    else
                    {
                        LCD_ShowString(1,12," ON");
                    }
                    
                }
                LED_State();

        }
   }
}

void Timer1_Routine() interrupt 3
{
    TL1 = 0x33;		//设置定时初值
	TH1 = 0xFE;		//设置定时初值
    
    
    if(Num1<=Angle)
    {
        PWM = 1;
    }
    else
    {
        PWM = 0;
    }
    Num1++;
    Num1%=40;
}
