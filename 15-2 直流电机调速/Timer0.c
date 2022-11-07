#include <REGX52.H>

void Timer0_Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xAE;		//���ö�ʱ��ֵ
	TH0 = 0xFB;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

/* ��ʱ���жϺ���ģ��
void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0xAE;		//���ö�ʱ��ֵ
	TH0 = 0xFB;		//���ö�ʱ��ֵ
	count0++;
	if(count0 == 1000){
		count0 = 0;
	}
		
}
*/