#include <REGX52.H>

/**
  * @brief  串口初始化 //4800bps@11.0592MHz
  * @param  无
  * @retval 无
  */
void UART_Init(){
	SCON=0x40;
	PCON &= 0x7F;		//4800bps@11.0592MHz
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}
/**
  * @brief  发送数据
  * @param  
  * @retval 
  */
void UART_SendByte(unsigned char byet){
	SBUF = byet;
	while(TI==0);
	TI=0;
}