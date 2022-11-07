#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int a=0;

void main(){
	LCD_Init();

//	a=1+1l;
//	LCD_ShowChar(1,1,'C');
//	LCD_ShowString(1,3,"Hello World");
//	LCD_ShowNum(2,1,a,1);
	while(1){
		a++;
		LCD_ShowNum(2,1,a,3);
		Delay(1000);
	}
}
