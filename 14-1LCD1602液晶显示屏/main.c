#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main(){
	LCD_Init();
	//LCD_ShowChar(2,1,0x41);
	LCD_ShowString(1,1,"adas");
	LCD_ShowBinNum(2,1,0xA5,8);
	LCD_ShowString(1,16,"Welcome To China!");
	while(1){
		Delay(1000);
		LCD_WriteCommand(0x18);
		Delay(500);
		
	}
}
