#include <reg51.h>
#define uchar unsigned char
#define uint  unsigned int
sbit D1=P0^0;
uchar code TAB[]={��};   //���ݷ���ͼ����LED�������ʾ����


void delay(uchar time)
{
   uint i,j,k;
   for(i=0;i<=time;i++)
      for(j=0;j<=100;j++);
			for(k=0;k<=100;k++);
   }

void int0svr() interrupt ? using 1    //�����жϺţ�ע���ж�Ƕ��ʹ�ò�ͬͨ�üĴ�����
{
	��;     //ע�ⴥ���ⲿ�жϺ�Ҫִ�еĹ���
	delay(255);
	
}

void int1svr() interrupt ? using 2
{
   uchar i;
   for(i=0;i<16;i++){
    ��; 
		 delay(255);
	
   };
 
}

void main(void)
 { 
    ��;
    ��;
    ��;
    ��;//���������жϳ�ʼ����ע���жϴ�����ʽ���ж��������ȼ�����
    while(1){
			��;
			��;   //û�д����ж�ʱ��Ƭ����״̬
		}
 }
