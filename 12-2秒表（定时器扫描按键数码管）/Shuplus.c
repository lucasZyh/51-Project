#include <REGX51.H>
#include "Delay.h"

unsigned char Shu_Buf[]={0,10,10,10,10,10,10,10,10};
unsigned char Number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};

void Shu_SetBuf(unsigned char location, number){
	Shu_Buf[location]=number;
}

void Shu_Scan(unsigned char location, number){
	P0=0x00;
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
}

void Shu_Loop(){
	static unsigned char i=1;
	Shu_Scan(i,Shu_Buf[i]);
	i++;
	if(i>=9)
		i=1;
}