#include <REGX51.H>

unsigned char Number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Shu(unsigned char location, number);//����ܵ��ú���
void Delay(unsigned int t);//��ʱ����


void main(){
	while(1){
		Shu(1,3);
//		Delay(500);
		Shu(2,6);
//		Delay(500);
		Shu(3,7);
//		Delay(1000);
	}
}

void Shu(unsigned char location, number){
	switch(location){
		case 1 : P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
		case 2 : P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
		case 3 : P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
		case 4 : P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
		case 5 : P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
		case 6 : P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
		case 7 : P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
		case 8 : P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
	}
	P0=Number[number];
	Delay(1);//��Ӱ
	P0=0x00;
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