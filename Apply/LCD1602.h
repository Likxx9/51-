#ifndef  __LCD1602_H__
#define __LCD1602_H__

void LCD1602_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char * String );
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int num,unsigned char Length);
void LCD_ShowSignNum(unsigned char Line,unsigned char Column, int num,unsigned char Length);
unsigned int Pow(int x,int y);
#endif 



