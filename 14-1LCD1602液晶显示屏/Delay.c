
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