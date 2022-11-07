#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
#include "Keyplus.h"
#include "Shuplus.h"
#include "AT24C02.h"

unsigned char KeyNu,Flag;
unsigned char Min,Sec,MinSec;

void main(){
	Timer0_Init();
	while(1){
		KeyNu = Key();
		if(KeyNu==1){
			Flag = !Flag;
		}
		if(KeyNu==2){
			Min=Sec=MinSec=0;
			Flag=0;
		}
		if(KeyNu==3){
			AT24C02_WriteByte(0,Min);
			Delay(5);
			AT24C02_WriteByte(1,Sec);
			Delay(5);
			AT24C02_WriteByte(2,MinSec);
			Delay(5);
		}
		if(KeyNu==4){
			Min=AT24C02_ReadByte(0);
			Sec=AT24C02_ReadByte(1);
			MinSec=AT24C02_ReadByte(2);
			Flag=0;
		}
		Shu_SetBuf(1,Min/10);
		Shu_SetBuf(2,Min%10);
		Shu_SetBuf(3,11);
		Shu_SetBuf(4,Sec/10);
		Shu_SetBuf(5,Sec%10);
		Shu_SetBuf(6,11);
		Shu_SetBuf(7,MinSec/10);
		Shu_SetBuf(8,MinSec%10);
	}
}

void Sec_Loop(){
	if(Flag)
	{
		MinSec++;
		if(MinSec>=100)
		{
			MinSec=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>=24)
					Min=0;
			}
		}
	}
	
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0,count1 = 0,count2 = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count0++;
	if(count0 == 20){
		count0 = 0;
		Key_Loop();
	}
	count1++;
	if(count1 == 2){
		count1 = 0;
		Shu_Loop();
	}
	count2++;
	if(count2 == 9){//此处本应为10，与手机对比后提高精度改为9
		count2 = 0;
		Sec_Loop();
	}
		
}