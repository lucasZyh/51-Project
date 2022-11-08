#include"at89x52.h"
void main()
{
	//unsigned char i;
	SCON=0x50;
	TMOD=0x20;
	TH1=0xE6;
	TL1=0xE6;
	TR1=1;
	EA=1;
	ES=1;
	while(1)
	{
	;

	}

}
void SportR() interrupt 4
{
     if(RI){
	 RI=0;
	 P2=SBUF;
	 }
}