#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Key.h"

unsigned char Number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char sec,flag,keynum;

void Shu(unsigned char location, number){
	switch(location){
		case 1 : P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
		case 2 : P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
		case 3 : P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
		case 4 : P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
		case 5 : P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
		case 6 : P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
		case 7 : P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
		case 8 : P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
	}
	P0=Number[number];
	Delay(1);//消影
	P0=0x00;
}

void main(){
	Timer0_Init();
	flag = 0;
	while(1){
		keynum =  Key();
		if(keynum==1) flag = 1; //开始
		if(keynum==2) sec = 0;	//清零
		if(keynum==3) flag = 0;	//暂停
		if(keynum==4) break;	//重新开始
		Shu(1,sec/10);
		Shu(2,sec%10);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	if(flag == 1){
		count0++;
		if(count0 == 1000){
			count0 = 0;
			sec++;
			if(sec == 60)
				sec =0;
		}
	}
	
		
}

