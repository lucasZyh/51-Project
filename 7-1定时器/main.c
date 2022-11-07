#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h>

unsigned char KeyNum,LEDMode;

void main(){
	P2 = 0xFE;
	Timer0_Init();
	while(1){
		KeyNum = Key();
		if(KeyNum){
			if(KeyNum==1){
				LEDMode++;
				if(LEDMode==2)
					LEDMode = 0;
			}
			
		}
	}
}


void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	count0++;
	if(count0 == 1000){
		count0 = 0;
		if(LEDMode==0)
			P2 = _crol_(P2,1);
		if(LEDMode==1)
			P2 = _cror_(P2,1);
	}
		
}
