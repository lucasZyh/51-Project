#include <REGX52.H>
#include "Delay.h"
#include <intrins.h>//进行移位操作的头文件


void main(){
	//初始化外部中断0
	IT0 = 0;
	IE0 = 0;
	EX0 = 1;
	EA = 1;
	PX0 = 0;
	
	while(1){
		P1=0xF0;
		Delay(500);
		P1=0x0F;
		Delay(500);
	}
}

void Int0_Routine(void) interrupt 0
{
	unsigned char Count0;
	for(Count0=0;Count0<8;Count0++)
	{
		P1=_crol_(0xFE,Count0);
		Delay(500);
		
	}
}