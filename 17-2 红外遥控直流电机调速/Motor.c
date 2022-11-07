#include <REGX52.H>
#include "Timer1.h"
sbit Motor = P1^0;

unsigned char Counter,Compare;

void Motor_Initn()
{
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char speed)
{
	Compare = speed;
}

void Timer1_Routine() interrupt 3
{
	TL1 = 0xAE;		//���ö�ʱ��ֵ
	TH1 = 0xFB;		//���ö�ʱ��ֵ
	Counter++;
	Counter = Counter % 100;
	if(Counter < Compare)
	{
		Motor = 1;
	}
	else
	{
		Motor = 0;
	}
}