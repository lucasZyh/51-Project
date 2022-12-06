#include <reg52.h>
#include <absacc.h>

#define PA	 XBYTE[0x7FFC]   //PA端口地址
#define PB	 XBYTE[0x7FFD]		
#define PC	 XBYTE[0x7FFE]
#define COM	 XBYTE[0x7FFF]

char code dx516[3] _at_ 0x003b;

unsigned char Second[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10};  
unsigned char count = 0, total = 0;

/**************8255初始化******************************/
void init_8255(void)
{
	COM = 0x80;	// 方式0,C = out B=out A = out
	PA = 0xFF;
	PB = 0xFF;
}

/**************定时器1初始化******************************/
void init_T1(void)
{
	TMOD &= 0x0F;//设置定时器模式
	TMOD |= 0x10;//设置定时器模式
	TL1 = 0x00;	//设置定时初值
	TH1 = 0x4C;	//设置定时初值
	TF1 = 0;//清除TF1标志
	ET1 = 1; //允许定时器中断1
	EA = 1;	//开总中断
	TR1 = 0;//定时器1先不工作 
}

//-------------------
// 函数名称： void delay_s(unsigned t)
// 函数功能： 利用定时器延时t*0.5秒子程序
//-------------------
void delay_s(unsigned char t)
{  
	TR1 = 1;//启动定时器1
	total = t * 10;
	count = 0;
	while(1)
	{
	  if(count == total)//定时时间到
		{
			count = 0;	
			total = 0;
			TR1 = 0;
			return;
		}
	}
}

void timer1() interrupt 3       //定时器1
{     
	TR1 = 0;
	TL1 = 0x00;	//设置定时初值
	TH1 = 0x4C;	//设置定时初值
	count++;
	TR1 = 1;
}

void main(void)
{
	unsigned char i = 0;
	init_8255();//初始化8255
	init_T1();//初始化定时器1
	while(1)
	{	
		//东西方向->南北方向
		for(i = 10;i > 0;i--)
		{
			PC = Second[i];			
			if(i < 4)//东西方向绿灯/南北方向红灯闪烁3秒
			{
				PA = 0xFF;
				PB = 0xFF;				
				delay_s(1);
				PA =0xF6;
				PB =0xDB;
				delay_s(1); 	
			}
			else
			{
				PA = 0xF6;	//东西绿灯亮
				PB = 0xDB;	//南北红灯亮 
				delay_s(2);
			}
		}
		
		for(i = 3;i > 0; i--)
		{
			PC = Second[i];
			PA = 0xED;//东西黄灯亮
			PB = 0xED;//南北黄灯亮				
			delay_s(1);
			PA = 0xFF;
			PB = 0xFF;    
			delay_s(1); 
		}
	 
		//南北方向->东西方向
		for(i = 10;i > 0;i--)
		{
			PC = Second[i];			
			if(i < 4)//南北方向绿灯/东西方向红灯闪烁3秒
			{
				PA = 0xFF;
				PB = 0xFF;	
				delay_s(1);
				PA = 0xDB;  //东西红灯亮
				PB = 0xF6;  //南北绿灯亮
				delay_s(1); 	
			}
			else
			{
				PA = 0xDB;	 //东西红灯亮
				PB = 0xF6;   //南北绿灯亮
				delay_s(2);
			}
		}
		
		for(i = 3;i > 0;i--)
		{
			PC = Second[i];
			PA = 0xED;//东西黄灯亮
			PB = 0xED;//南北黄灯亮				
			delay_s(1);
			PA = 0xFF;
			PB = 0xFF;  
			delay_s(1); 
		}
	}	
}
