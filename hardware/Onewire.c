#include <REGX52.H>
sbit One_wire=P3^7;

unsigned char Onewire_Init()
{
    unsigned char i;
    unsigned char Ack;
    One_wire=1;
    i = 5;while (--i);
    One_wire=0;
    i = 225;while (--i);    //500us的延时
    One_wire=1;
    i = 25;	while (--i);    //70us的延时
    Ack=One_wire;
    i = 225;while (--i);    //500us的延时
    return Ack;
}

void Onewire_Write(unsigned char Bit)
{
    unsigned char i;
    One_wire=0;
    i = 3;	while (--i);    //10us延时
    One_wire=Bit;
    i = 22;	while (--i);    //50us延时
    One_wire=1;
    i = 1;while (--i);      //Delay 5us
}

unsigned char Onewire_Read()
{
    unsigned char i;
    unsigned char Read;
    One_wire=0;
    i = 1;while (--i);      //Delay 5us
    One_wire=1; 
    i = 1;while (--i);      //Delay 5us
    Read=One_wire;
    i = 22;	while (--i);    //50us延时
    
    return Read;
}

void Onewire_WriteByte(unsigned char Bit)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        Onewire_Write(Bit&(0x01<<i));
    }
}

unsigned char Onewire_ReadByte()
{
    unsigned char ReadByte=0x00;
    unsigned char i;
    for(i=0;i<8;i++)
    {
        if(Onewire_Read()){ReadByte|=(0x01<<i);}
    }
    return ReadByte;
}