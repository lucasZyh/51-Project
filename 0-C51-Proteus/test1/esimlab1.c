#include <reg52.h>//调用51单片机头文件
#define uchar unsigned char//定义uchar 即unsigned char
	
//延迟函数	
void delay( )
{
	uchar i,j;//定义变量i,j
	for(i=0;i<255;i++)//循环嵌套，达到延迟目的
	for(j=0;j<255;j++);
}

void main( )
{
	while(1)
{
	uchar temp;//定义变量temp
	
	P1=0xff;//给P1所有端口赋初值
	temp=P1&0xf0;//进行与计算，获得开关的信息
	temp=temp>>4;//向右移4位，将开关的信息移位给LED灯
	P1=temp;//将temp的值赋给P1
	
	delay( );
}

}
