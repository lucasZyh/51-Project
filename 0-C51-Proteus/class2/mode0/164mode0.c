 #include"at89x52.h"
 unsigned char nSendByte;
 void delay(unsigned int i)
 {
 	 unsigned char j;
	 for(;i>0;i--)
	 for(j=0;j<125;j++)
	 ;
 }
 void main()
 {
 	SCON=0x00;
	EA=1;
	ES=1;
	nSendByte=1;
	SBUF=nSendByte;		  //启动串口
	P1_0=0;				 //允许串口发送数据至74LS164
	while(1)
	{;}
 }
 void  SPort() interrupt 4 using 0
 {
 	if(TI)				 //一个字符串发送完毕
	{
	P1_0=1;				//允许74LS164并行输出
	SBUF=nSendByte;
	delay(500);
	P1_0=0;
	nSendByte=nSendByte<<1;
	if(nSendByte==0)nSendByte=1;
	SBUF=nSendByte;
	}
	TI=0;
	RI=0;
 }
