#include <REGX51.H>
#include "Key.h"
#include "Delay.h"

unsigned char Number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Shu(unsigned char location, number);//数码管调用函数

void main(){
	unsigned char i,j,sec=0,keynum;
	keynum =  Key();
	if(keynum == 1)//开始
	{
		while(1)
		{
			keynum =  Key();
			Shu(1,sec/10);
			Shu(2,sec%10);
			i++;
			if(i==100)
			{
				i=0;
				j++;
			}
			if(j==5)
			{
				i=j=0;
				sec++;
			}
			if(sec == 60)
			{
				sec = 0;
			}
			if(keynum == 2)//清零
				sec = 0;
			if(keynum == 3)//结束
				break;
		}
	}
	
}

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
