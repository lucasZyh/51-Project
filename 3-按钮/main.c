#include <REGX51.H>

void Delay(unsigned int t);		//��ʱ����

void main()
{
	

	//��ť����LED�ƣ���12345678˳����
	unsigned int i = 0;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			if(i >= 8)
				i = 0;
			P2 = ~(0x01<<i);
			i++;
		}
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			
			if(i <= 0)
			{
				P2 = ~(0x01<<i);
				i = 8;
			}
			else
			{
				i--;
				P2 = ~(0x01<<i);
			}
			
		}
	}
	
	
	/*while(1){
		P2_0 = 0;
		Delay(500);
		P2_0 = 1;
		Delay(500);
	}*/
	
	
	//��ť����LED��
	/*while(1){
		unsigned char ledNum;
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			ledNum++;
			P2 = ~ledNum;
		}
	}*/
}
void Delay(unsigned int t)		//��ʱ����
{
	
	unsigned char i, j;
	while(t){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}

	
}
