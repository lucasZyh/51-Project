#include "intrins.h"
void Delay(unsigned int t)		//ÑÓÊ±º¯Êý
{
	
	unsigned char i, j;
	while(t){
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}

	
}