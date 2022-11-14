#include <REGX51.H>

sbit D1=P0^0;
unsigned char Number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
						  0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

unsigned char i;
						  
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

void main(){

	//�жϳ�ʼ��
	EX0 = 1;//�����ⲿ�ж�0�ж�
	EX1 = 1;//�����ⲿ�ж�0�ж�
	
	IT0 = 1;//�ⲿ�ж�0Ϊ���ش���
	IT1 = 1;//�ⲿ�ж�1Ϊ���ش���
	IE0 = 0;//�ⲿ�ж�0�������־λ
	IE1 = 0;//�ⲿ�ж�1�������־λ
	
	EA = 1;//�ж�������
	
	PX0 = 0;//�ⲿ�ж�0Ϊ�����ȼ�
	PX1 = 0;//�ⲿ�ж�1Ϊ�����ȼ�
	
	while(1){
		P2 = 0x00;//����ܳ�ʼ��
	}
}

void Int0_Routine(void) interrupt 0 using 1//�ⲿ�ж�0�жϷ�����
{
	D1 = ~D1;//LED��״̬ȡ��
}

void Int1_Routine(void) interrupt 2 using 2//�ⲿ�ж�1�жϷ�����
{
	unsigned char count = 3;
	while(count != 0)//�жϿ�ʼִ�У������ѭ����ʾ0~F 3��
	{
		for(i = 0;i<16;i++)
	{
		P2 = Number[i];
		Delay(100);
	}
	count--;
	}
	
}
