#include <REGX52.H>

void Timer1_Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0xAE;		//设置定时初值
	TH1 = 0xFB;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}

/* 定时器中断函数模板
void Timer1_Routine() interrupt 3
{
	static unsigned int count1 = 0;
	TL1 = 0xAE;		//设置定时初值
	TH1 = 0xFB;		//设置定时初值
	count1++;
	if(count1 == 1000){
		count1 = 0;
	}
		
}
*/