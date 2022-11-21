#include <REGX51.H>

void Timer1_Init(void); //中断初始化函数


void main(){
	
	Timer1_Init();//中断初始化
	P1_0 = 0;
	while(1){
	}
}

void Timer1_Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x18;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;		
	EA = 1;			//中断总允许
	PT1 = 0;
}

void Timer1_Routine() interrupt 3 //定时器1中断函数
{
	static unsigned int count1 = 0;
	TL1 = 0x18;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值	
	count1++;
	if(count1 == 3000){ //每三秒转换一次状态
		count1 = 0;
		P1_0 = ~P1_0;
	}
		
}
