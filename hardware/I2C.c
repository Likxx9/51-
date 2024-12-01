#include <REGX52.H>
#define SDA 
#define SCL
void I2C_Init()
{
    SDA = 1;
    SCL = 1;
    
}

void I2C_Start()
{
    SCL = 1;
    SDA = 0;
    
    SCL = 0;
}

void I2C_Stop()
{
    SDA = 0;
    SCL = 0;
    
    SCL = 1;
    SDA = 1;
}

void I2C_Send(unsigned char Data)
{
    unsigned char i;
    SCL = 0;
    for(i=0;i<8;i++)
    {
        SDA = Data&(0x80>>i)
        SCL = 1;
        SCL = 0;
    }
}

unsigned char I2C_Receive()
{
    unsigned char i,Data=0x00;
    SDA = 1;
    for(i=0;i<8;i++)
    {
        SCL = 1;
        if(SDA){Data |= (0x80>>i)}
        SCL = 0;
    }   
}

void I2C_SendAck(unsigned char Ack)
{
    SDA = Ack;
    SCL = 1;
    SCL = 0;
}

unsigned char I2C_ReAck()
{
    unsigned char Ack;
    SDA = 1;
    SCL = 1;
    Ack = SDA;
    SCL = 0;
    return Ack;
}