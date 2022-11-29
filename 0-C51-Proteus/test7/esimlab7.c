#include <REGX51.H>

sbit SW1 = P3^5;

void Delay(unsigned int t)//延时函数
{
	
	unsigned char i, j;
	while(t){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}
}

void send(unsigned char dat){
	SBUF = dat;//待发送数据写入发送缓冲寄存器
	while(TI == 0);//串口未发生完，等待
	;
	TI = 0;//1个字节发送完毕，等待
}
void main(){
	unsigned char i = 01;
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	
	PCON = 0x00;		//波特率不倍速
	SCON = 0x40;		//8位数据,可变波特率
	
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	TR1 = 1;		//启动定时器1
	
	while(1){
		
		if(SW1 == 0){
			send(i);
			Delay(200);
		}
	}
}
