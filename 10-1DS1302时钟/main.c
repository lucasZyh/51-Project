#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"

unsigned char Second,Minute;

void main(){
	LCD_Init();
	DS1302_Init();
	
	DS1302_SetTime();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	
	
	while(1){
		DS1302_ReadTime();	
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
	}
}

//void main(){
//	
//	LCD_Init();
//	DS1302_Init();
//	LCD_ShowString(1,1,"hhj");
//	DS1302_WriteByte(0x8E,0x00);   //解除芯片写保护
//	DS1302_WriteByte(0x80,0x10);
//	DS1302_WriteByte(0x82,0x00);
//	
//	
//	while(1){
//		Second=DS1302_ReadByte(0x81);				//BCD码转十进制：X/10*16+X%10
//		Minute=DS1302_ReadByte(0x83);
//		LCD_ShowNum(2,1,Minute/16*10+Minute%16,2);
//		LCD_ShowNum(2,4,Second/16*10+Second%16,2);	//十进制转BCD码：X/16*10+X%16
//		
//	}
//}
