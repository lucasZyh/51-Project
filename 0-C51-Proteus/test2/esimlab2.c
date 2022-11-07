#include<reg51.h>	  //调用51头文件
#include<absacc.h>    //用于访问绝对地址头文件
#define port P1		  //宏定义，P1口

sbit led = P2^7;	  //位定义，led表示P2_7口

data unsigned char buffer1[17] _at_ 0x60;    //定义DATA区数组变量，首地址为60H
xdata unsigned char buffer2[17] _at_ 0x4000; //定义XDATA区数组变量，首地址为4000H

void delay()//延迟函数
{
	unsigned char i,j;
	for(i=0;i<255;i++)
	for(j=0;j<255;j++);
}


void main()
{
	unsigned char i,temp; //定义无符号变量
	for(i = 0; i < 17 ; i++)
	{
		buffer1[i] = 0x04 + i; //向片内RAM0x60地址存入04H-14H共17个字节
	}
	for(i = 0; i < 17 ; i++)
	{
		buffer2[i] = buffer1[i];//将片内RAM中的数据04H-14H传送到片外RAM中保存
		temp = buffer2[i];//依次取出片外RAM中的值
		port = ~temp;//将数据送到P1口，控制LED灯亮灭
		delay();
	}
	led = 0;//数据传送完毕，点亮LED灯
	while(1);
}
