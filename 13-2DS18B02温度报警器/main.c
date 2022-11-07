#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B20.h"
#include "Keyplus.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Timer0.h"

float T,temp;
char TLow,THigh;
unsigned char KeyNum;

void main(){
	/*DS18B20_ConvertT();
	Delay(1000);*/
	THigh = AT24C02_ReadByte(0);
	TLow = AT24C02_ReadByte(1);
	if(THigh>125 || TLow <-55 || THigh<=TLow){
		THigh = 20;
		TLow  = 15;
	}
	
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	while(1){
		KeyNum = Key();
		//温度读取及显示
		DS18B20_ConvertT();
		T = DS18B20_ReadT();
		temp=T;
		if(T<0){
			LCD_ShowChar(1,3,'-');
			T = -T;
		}else{
			LCD_ShowChar(1,3,'+');
		}
		LCD_ShowNum(1,4,T,3);
		LCD_ShowChar(1,7,'.');
		LCD_ShowNum(1,8,(unsigned long)(T*100)%100,2);
		
		//阈值判断及显示
		if(KeyNum){
			if(KeyNum == 1){THigh++;if(THigh>125){THigh = 125;}}
			if(KeyNum == 2){THigh--;if(THigh<=TLow){THigh++;}}
			if(KeyNum == 3){TLow++;if(THigh<=TLow){TLow--;}}
			if(KeyNum == 4){TLow--;if(THigh<-55){THigh = -55;}}
		}
		LCD_ShowSignedNum(2,4,THigh,3);
		LCD_ShowSignedNum(2,12,TLow,3);
		
		AT24C02_WriteByte(0,THigh);
		Delay(5);
		AT24C02_WriteByte(1,TLow);
		Delay(5);
		
		if(temp>THigh){
			LCD_ShowString(1,13,"OV:H");
		}else if(temp<TLow){
			LCD_ShowString(1,13,"OV:L");
		}else{
			LCD_ShowString(1,13,"    ");
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count0++;
	if(count0 == 20){
		Key_Loop();
	}
		
}
