#include <REGX52.H>
#include "LCD1602.H"
#include "Timer0.H"
#include "Key.H"

unsigned char sec,min,hou,keynum,flag;
void main(){
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	
	while(1){
		
		keynum =  Key();
		if(keynum==1){
			flag=1;
			LCD_ShowString(1,13,"star");
		}
		if(keynum==2)sec=min=hou=0;
		if(keynum==3){
			flag=0;
			LCD_ShowString(1,13,"stop");
		}
		if(keynum==4)break;
		
		
		LCD_ShowNum(2,1,hou,2);
		LCD_ShowString(2,3,":");
		LCD_ShowNum(2,4,min,2);
		LCD_ShowString(2,6,":");
		LCD_ShowNum(2,7,sec,2);
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	if(flag==1){
		count0++;
		if(count0 == 1000){
			count0=0;
			sec++;
			if(sec==60){
				sec==0;
				min++;
			}
			if(min==60){
				min=0;
				hou++;
			}
			if(hou==24)
				hou=0;
		}
	}	
}