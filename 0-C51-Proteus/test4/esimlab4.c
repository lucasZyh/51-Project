#include <REGX51.H>
#include "LCD1602.h"//����LCD1602�ļ�

void main(){
	LCD_Init();//��ʼ��LCD1602
	LCD_ShowString(1,4,"Welcome To");//����LCD_ShowString����
	LCD_ShowString(2,6,"ZZULI");//����LCD_ShowString����
	while(1);
}
