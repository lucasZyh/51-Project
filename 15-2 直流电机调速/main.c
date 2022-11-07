#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include "Shu.h"

sbit Motor = P1^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main(){
	Timer0_Init();
	while(1){
		KeyNum = Key();
		if(KeyNum == 1)
		{
			Speed++;
			Speed = Speed % 4;
			if(Speed==0){Compare = 0;}
			if(Speed==1){Compare = 50;}
			if(Speed==2){Compare = 75;}
			if(Speed==3){Compare = 100;}
		}
		Shu(1,Speed);
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0xAE;		//设置定时初值
	TH0 = 0xFB;		//设置定时初值
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