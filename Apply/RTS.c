#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "DS18B20.h"

//sbit Motor=P1^0;
//unsigned char Tem_HL[]={20,28};
float T=0;

void RTS()
{ 
    LCD_ShowString(1,1,"Tem:");
//    LCD_ShowNum(1,14,Tem_HL[0],2);
//    LCD_ShowNum(2,14,Tem_HL[1],2);
    DS_ConverT();
    T=DS_ReadT();
    if(T>0)
    {
        LCD_ShowChar(2,1,'+');
    }
    else if(T<0)
    {
        LCD_ShowChar(2,1,'-');
        T=-T;
    }
    LCD_ShowNum(2,2,T,2);
    LCD_ShowChar(2,4,'.');
    LCD_ShowNum(2,5,(unsigned long)(T*10000)%100,2);
    Delay(500);
}

//void Motor_Init()
//{
//    if(T>Tem_HL[1])
//    {
//        Motor=1;
//        Delay(1000);
//        Motor=0;
//    }
//    else if(T<Tem_HL[0])
//    {
//        Motor=0;
//    }
//}