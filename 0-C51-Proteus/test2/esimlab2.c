#include<reg51.h>	  //����51ͷ�ļ�
#include<absacc.h>    //���ڷ��ʾ��Ե�ַͷ�ļ�
#define port P1		  //�궨�壬P1��

sbit led = P2^7;	  //λ���壬led��ʾP2_7��

data unsigned char buffer1[17] _at_ 0x60;    //����DATA������������׵�ַΪ60H
xdata unsigned char buffer2[17] _at_ 0x4000; //����XDATA������������׵�ַΪ4000H

void delay()//�ӳٺ���
{
	unsigned char i,j;
	for(i=0;i<255;i++)
	for(j=0;j<255;j++);
}


void main()
{
	unsigned char i,temp; //�����޷��ű���
	for(i = 0; i < 17 ; i++)
	{
		buffer1[i] = 0x04 + i; //��Ƭ��RAM0x60��ַ����04H-14H��17���ֽ�
	}
	for(i = 0; i < 17 ; i++)
	{
		buffer2[i] = buffer1[i];//��Ƭ��RAM�е�����04H-14H���͵�Ƭ��RAM�б���
		temp = buffer2[i];//����ȡ��Ƭ��RAM�е�ֵ
		port = ~temp;//�������͵�P1�ڣ�����LED������
		delay();
	}
	led = 0;//���ݴ�����ϣ�����LED��
	while(1);
}
