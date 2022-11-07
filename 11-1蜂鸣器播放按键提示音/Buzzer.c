#include <REGX51.H>
#include <INTRINS.H>

//�������˿�
sbit Buzzer = P2^5;
/**
  * @brief  ������˽���ӳٺ������ӳ�500um
  * @param  
  * @retval 
  */
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 6;
	j = 93;
	do
	{
		while (--j);
	} while (--i);
}

/**
  * @brief  ����������ʱ��
  * @param  
  * @retval 
  */
void Buzzer_Time(unsigned int ms){
	unsigned int i;
	for(i=0;i<ms*2;i++){
		Buzzer = !Buzzer;
		Buzzer_Delay500us();
	}
}