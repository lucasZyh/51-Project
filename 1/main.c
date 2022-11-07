#include <reg51.h>
sbit LED1 = P0^1;
unsigned char idata Port1;
unsigned char data Port2;
unsigned char code b{} = {0x01,0x02,0x04};
unsigned char xdata a{2};
void Delay();

void main()
{
	while(1)
	{
		Port1 = 0xe3;
		Port2 = 0x23;
		p2 = b{1};
		a{1} = p2;
		LED1 = 0;
		Delay();
		LED1 = 1;
	}
}
void Delay()
{
uchar i,j;
for(i=0;i<255;i++)
for(j=0;j<255;j++);
}