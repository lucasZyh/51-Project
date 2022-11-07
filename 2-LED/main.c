#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int t)		//yan_chi_han_shu
{
	unsigned char i, j;
	while(t > 0)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}
}


void main ()
{
	
	while(1)
	{
		P2 = 0xFE;
		Delay(200);
		P2 = 0xFD;
		Delay(200);
		P2 = 0xFB;
		Delay(200);
		P2 = 0xF7;
		Delay(200);
		P2 = 0xEF;
		Delay(200);
		P2 = 0xDF;
		Delay(200);
		P2 = 0xBF;
		Delay(200);
		P2 = 0x7F;
		Delay(200);
	}
}
/*void main ()   
{
	
	while(1)  //liu_shui_deng
	{
		P2 = 0xFE;
		Delay500ms();
		P2 = 0xFF;
		Delay500ms();
	}
}*/



