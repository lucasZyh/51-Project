#include <REGX51.H>
#include <INTRINS.H>

//蜂鸣器端口
sbit Buzzer = P2^5;
/**
  * @brief  蜂鸣器私有延迟函数，延迟500um
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
  * @brief  蜂鸣器发生时长
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