#include <REGX52.H>

void Timer0_Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xAE;		//设置定时初值
	TH0 = 0xFB;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

/* 定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0xAE;		//设置定时初值
	TH0 = 0xFB;		//设置定时初值
	count0++;
	if(count0 == 1000){
		count0 = 0;
	}
		
}
*/