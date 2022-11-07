
void Delay(unsigned int t)		//ÑÓÊ±º¯Êý
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