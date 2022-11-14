#include <REGX51.H>

sbit D1=P0^0;
unsigned char Number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
						  0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

unsigned char i;
						  
void Delay(unsigned int t)		//延时函数
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

	//中断初始化
	EX0 = 1;//允许外部中断0中断
	EX1 = 1;//允许外部中断0中断
	
	IT0 = 1;//外部中断0为跳沿触发
	IT1 = 1;//外部中断1为跳沿触发
	IE0 = 0;//外部中断0的请求标志位
	IE1 = 0;//外部中断1的请求标志位
	
	EA = 1;//中断总允许
	
	PX0 = 0;//外部中断0为低优先级
	PX1 = 0;//外部中断1为高优先级
	
	while(1){
		P2 = 0x00;//数码管初始化
	}
}

void Int0_Routine(void) interrupt 0 using 1//外部中断0中断服务函数
{
	D1 = ~D1;//LED灯状态取反
}

void Int1_Routine(void) interrupt 2 using 2//外部中断1中断服务函数
{
	unsigned char count = 3;
	while(count != 0)//中断开始执行，数码管循环显示0~F 3次
	{
		for(i = 0;i<16;i++)
	{
		P2 = Number[i];
		Delay(100);
	}
	count--;
	}
	
}
