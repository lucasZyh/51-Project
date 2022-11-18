#include <REGX51.H>
#include "LCD1602.h"//调用LCD1602文件

void main(){
	LCD_Init();//初始化LCD1602
	LCD_ShowString(1,4,"Welcome To");//调用LCD_ShowString函数
	LCD_ShowString(2,6,"ZZULI");//调用LCD_ShowString函数
	while(1);
}
