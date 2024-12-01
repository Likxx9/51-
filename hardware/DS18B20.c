#include <REGX52.H>
#include "Onewire.h"
#include "LCD1602.h"
#define DS_READ_SCRATCHPAD      0xBE//读暂存器操作
#define DS_CONVERT_T            0x44//进行温度转换
#define DS_ROM_SKIP             0xCC//允许总线不提供64位ROM码而访问存储器操作节省时间

void DS_ConverT()
{
    Onewire_Init();
    Onewire_WriteByte(DS_ROM_SKIP);
    Onewire_WriteByte(DS_CONVERT_T);
}



float DS_ReadT()
{
    unsigned char TH,TL;
    int temp;
    float T;
    Onewire_Init();
    Onewire_WriteByte(DS_ROM_SKIP);
    Onewire_WriteByte(DS_READ_SCRATCHPAD);
    
    TL=Onewire_ReadByte();
    TH=Onewire_ReadByte();

    temp=(TH<<8)|TL;

    T=temp/16.0;

    return T;
}