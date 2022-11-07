#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Key.h"
#include "Timer0.h"

unsigned char KeyNumber,MODE,TimeSetSelect,TimeSetFlashFlag;
unsigned char YEAR(unsigned char year,month);
void TimeShow();
void TimeSet();
	

void main(){
	LCD_Init();
	DS1302_Init();
	Timer0_Init();
	
	DS1302_SetTime();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	
	
	while(1){
		KeyNumber = Key();
		if(KeyNumber==1){
			if(MODE==0)MODE=1;
			else if(MODE==1){MODE=0;DS1302_SetTime();}
		}
		switch(MODE)
		{
			case 0: TimeShow();break;
			case 1: TimeSet();break;
		}
		
	}
}
//显示
void TimeShow(){
	DS1302_ReadTime();	
	LCD_ShowNum(1,1,DS1302_Time[0],2);
	LCD_ShowNum(1,4,DS1302_Time[1],2);
	LCD_ShowNum(1,7,DS1302_Time[2],2);
	LCD_ShowNum(2,1,DS1302_Time[3],2);
	LCD_ShowNum(2,4,DS1302_Time[4],2);
	LCD_ShowNum(2,7,DS1302_Time[5],2);
}
//修改
void TimeSet(){
	//选择需要更改的位
	if(KeyNumber == 2)
	{
		TimeSetSelect++;
		TimeSetSelect%=6;
	}
	//增加更改位的数，并判断是否越界
	if(KeyNumber == 3)
	{
		DS1302_Time[TimeSetSelect]++;
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}
		
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==31)
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==30)
		{
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==29)
		{
			if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
		}
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==28)
		{
			if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
		}
		
		if(DS1302_Time[3]>24){DS1302_Time[3]=0;}
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}
	}
	//减小更改位的数，并判断是否越界
	if(KeyNumber == 4)
	{
		DS1302_Time[TimeSetSelect]--;
		if(DS1302_Time[0]>100){DS1302_Time[0]=99;}
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}
		
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==31)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==30)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==29)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=29;}
			if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
		}
		if(YEAR(DS1302_Time[0]+2000,DS1302_Time[1])==28)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=28;}
			if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
		}
		
		if(DS1302_Time[3]>100){DS1302_Time[3]=24;}
		if(DS1302_Time[4]>100){DS1302_Time[4]=59;}
		if(DS1302_Time[5]>100){DS1302_Time[5]=59;}
	}
	//显示更改后的数据
	if(TimeSetSelect==0 && TimeSetFlashFlag==1){LCD_ShowString(1,1,"  ");}
	else{LCD_ShowNum(1,1,DS1302_Time[0],2);}
	
	if(TimeSetSelect==1 && TimeSetFlashFlag==1){LCD_ShowString(1,4,"  ");}
	else{LCD_ShowNum(1,4,DS1302_Time[1],2);}
	
	if(TimeSetSelect==2 && TimeSetFlashFlag==1){LCD_ShowString(1,7,"  ");}
	else{LCD_ShowNum(1,7,DS1302_Time[2],2);}
	
	if(TimeSetSelect==3 && TimeSetFlashFlag==1){LCD_ShowString(2,1,"  ");}
	else{LCD_ShowNum(2,1,DS1302_Time[3],2);}
	
	if(TimeSetSelect==4 && TimeSetFlashFlag==1){LCD_ShowString(2,4,"  ");}
	else{LCD_ShowNum(2,4,DS1302_Time[4],2);}
	
	if(TimeSetSelect==5 && TimeSetFlashFlag==1){LCD_ShowString(2,7,"  ");}
	else{LCD_ShowNum(2,7,DS1302_Time[5],2);}

	/*LCD_ShowNum(2,10,TimeSetSelect,2);
	LCD_ShowNum(2,13,TimeSetFlashFlag,2);*/
}

//闰年判断，月份天数判断
unsigned char YEAR(unsigned char year,month){
	if(year%400==0||year%4==0&&year%100!=0)
	{
		if(month==2)
			return 29;
	}
	else
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
			return 31;
		else if(month==4||month==6||month==9||month==11)
			return 30;
		else
			return 28;
	}
	return 0;
}
//定时器
void Timer0_Routine() interrupt 1
{
	static unsigned int count0 = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count0++;
	if(count0 == 300){
		count0 = 0;
		TimeSetFlashFlag=!TimeSetFlashFlag;
	}
		
}
