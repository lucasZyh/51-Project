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
	nSendByte=1;
	for(;;){
	 SBUF=nSendByte;          //��������
	 P1_0=0;				 //�����ڷ���������74LS164
	 while(!TI){;}			 //�ȴ��������
	 P1_0=1;				  //����74LS164�������
	 SBUF=nSendByte;
	 delay(500);
	 P1_0=0;
	 nSendByte=nSendByte<<1;
	 if(nSendByte==0)nSendByte=1;
 	SBUF=nSendByte;			  //��������
	TI=0;
	RI=0;
	}

	
 }
 