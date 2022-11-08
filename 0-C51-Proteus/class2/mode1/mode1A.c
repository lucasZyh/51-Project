#include"at89x52.h"
void main()
{
	unsigned char i;
	SCON=0x40;
	TMOD=0x20;
	TH1=0xE6;
	TL1=0xE6;
	TR1=1;
	P1=0xFF;
	while(1)
	{
	i=P1;
	SBUF=i;
	while(TI==0);				  //µÈ´ý·¢ËÍÍê±Ï
	TI=0;

	}

}