#include <REGX52.H>

void Timer1_Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x10;		//���ö�ʱ��ģʽ
	TL1 = 0xAE;		//���ö�ʱ��ֵ
	TH1 = 0xFB;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}

/* ��ʱ���жϺ���ģ��
void Timer1_Routine() interrupt 3
{
	static unsigned int count1 = 0;
	TL1 = 0xAE;		//���ö�ʱ��ֵ
	TH1 = 0xFB;		//���ö�ʱ��ֵ
	count1++;
	if(count1 == 1000){
		count1 = 0;
	}
		
}
*/