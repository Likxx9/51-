#ifndef  __I2C_H__
#define __I2C_H__
void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Send(unsigned char Data);
unsigned char I2C_Receive();
void I2C_SendAck(unsigned char Ack);
unsigned char I2C_ReAck();

#endif 