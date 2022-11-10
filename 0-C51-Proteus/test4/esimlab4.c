//#include <REGX51.H>
//#include "LCD1602.h"//调用LCD1602文件

//void main(){
//	LCD_Init();//初始化LCD1602
//	LCD_ShowString(1,4,"Welcome To");//调用LCD_ShowString函数
//	LCD_ShowString(2,6,"ZZULI");//调用LCD_ShowString函数
//	while(1);
//}
#include <reg51.h>
#include <intrins.h>//??_nop_()?????????
#define uchar unsigned char
#define uint undigned int
#define out P0
sbit RS=P2^0;//???
sbit RW=P2^1;//???
sbit E=P2^2;//???
void lcd_initial(); //LCD?????
void write_command(uchar com); //?????
void write_data(uchar dat); //?????
void string(uchar ad,uchar *s); //???????LCD?????
void delay(uchar j); //??

void main(void)
{
 lcd_initial();
 while(1)
{
  string(0x85,"SGH"); //???????????SGH
  string(0xC2,"YMM"); //???????????YMM
  delay(100);//??
                                write_command(0x01);//??????
                                delay(100);//??
}
}

void delay(uchar j)
{
 uchar i = 250;
 for(; j>0; j--)
{
  while(--i);
  i = 249;
  while(--i);
  i = 250;
}
}

void write_command(uchar com)
{
 E=0;
 RS=0;
 RW=0;
 out=com;
 E=1; //???????,?????
 _nop_();
 E=0;
 delay(1);
}

void write_data(uchar dat)//???????
{
 E=0;
 RS=1;
 RW=0;
 out=dat;
 E=1; //???????,????
                _nop_();
 E=0;
 delay(1);
}

void lcd_initial(void)
{
 write_command(0x38);//8???,????,5X7?????
 write_command(0x0C);//?????,???,???
 write_command(0x06);//????
 write_command(0x01);//??
 delay(1);
}

void string(uchar ad,uchar *s)//??????????
{
 write_command(ad); //?????RAM??
 while(*s>0)
{
                write_data(*s++); //??????
                delay(100);
}
}