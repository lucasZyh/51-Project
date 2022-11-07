#include <REGX52.H>

sbit LED = P2^0;

void Delay(unsigned char time)
{
	while(time--);
}

void main(){
	unsigned char i,j;
	while(1){
		for(i=0;i<100;i++)
		{
			for(j=0;j<20;j++)
			{
				LED = 0;
				Delay(i);
				LED = 1;
				Delay(100-i);
			}
			
		}
		for(i=100;i>0;i--)
		{
			for(j=0;j<20;j++)
			{
				LED = 0;
				Delay(i);
				LED = 1;
				Delay(100-i);
			}
			
		}
	}
}
