#include <reg52.h>//����51��Ƭ��ͷ�ļ�
#define uchar unsigned char//����uchar ��unsigned char
	
//�ӳٺ���	
void delay( )
{
	uchar i,j;//�������i,j
	for(i=0;i<255;i++)//ѭ��Ƕ�ף��ﵽ�ӳ�Ŀ��
	for(j=0;j<255;j++);
}

void main( )
{
	while(1)
{
	uchar temp;//�������temp
	
	P1=0xff;//��P1���ж˿ڸ���ֵ
	temp=P1&0xf0;//��������㣬��ÿ��ص���Ϣ
	temp=temp>>4;//������4λ�������ص���Ϣ��λ��LED��
	P1=temp;//��temp��ֵ����P1
	
	delay( );
}

}
