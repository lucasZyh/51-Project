#include <REGX52.H>

/**
  * @brief  ���ڳ�ʼ�� //4800bps@11.0592MHz
  * @param  ��
  * @retval ��
  */
void UART_Init(){
	SCON=0x40;
	PCON &= 0x7F;		//4800bps@11.0592MHz
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFA;		//�趨��ʱ��ֵ
	TH1 = 0xFA;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
}
/**
  * @brief  ��������
  * @param  
  * @retval 
  */
void UART_SendByte(unsigned char byet){
	SBUF = byet;
	while(TI==0);
	TI=0;
}