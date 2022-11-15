#include<reg51.h>
sbit LED=P0^0;
unsigned char time=0;
void main(void)
{
    TMOD=0x01;
    TH0=15563/256;
    TL0=15536%256;
    TR0=1;
    while(1)
    {
        if(TF0==1)
        {
        TF0=0;
        TH0=15563/256;
        TL0=15536%256;
        if((time++)==20)
        {
            LED=!LED;
            time=0;

        }
        }
    }
}
