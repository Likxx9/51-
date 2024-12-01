#include <REGX52.H>
#include "DS1302.h"
#include "LCD1602.h"
Timer0_Init()
{
	//AUXR &= 0x7F;		//定时器时钟12T模式
	//TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFc;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
    ET0=1;          //中断开始
    EA=1;
    PT0=0;
}



Timer1_Init()
{
//    AUXR &= 0xBF;		//定时器时钟12T模式
//	TMOD &= 0x0F;		//设置定时器模式
	TMOD = 0x10;		//设置定时器模式
	TL1 = 0x33;		//设置定时初值
	TH1 = 0xFE;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
    EA =1;
    ET1 = 1;
}

//void Timer0_Rountine() interrupt1;