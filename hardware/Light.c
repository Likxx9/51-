#include <REGX52.H>
#include "Onewire.h"
sbit LIO = P3^1;

void Light_Init()
{
        SBUF = LIO;
}
