#include <reg51.h>
#define uchar unsigned char
#define uint  unsigned int
sbit D1=P0^0;
uchar code TAB[]={？};   //根据仿真图填入LED数码管显示段码


void delay(uchar time)
{
   uint i,j,k;
   for(i=0;i<=time;i++)
      for(j=0;j<=100;j++);
			for(k=0;k<=100;k++);
   }

void int0svr() interrupt ? using 1    //填入中断号，注意中断嵌套使用不同通用寄存器组
{
	？;     //注意触发外部中断后要执行的功能
	delay(255);
	
}

void int1svr() interrupt ? using 2
{
   uchar i;
   for(i=0;i<16;i++){
    ？; 
		 delay(255);
	
   };
 
}

void main(void)
 { 
    ？;
    ？;
    ？;
    ？;//以上填入中断初始化，注意中断触发方式，中断允许及优先级设置
    while(1){
			？;
			？;   //没有触发中断时单片机的状态
		}
 }
