#include <REGX52.H>

#define DS1302_SECOND    0x80
#define DS1302_MINUTE	 0x82
#define DS1302_HOUR		 0x84
#define DS1302_DATE	 	 0x86
#define DS1302_MONTH	 0x88
#define DS1302_DAY		 0x8A
#define DS1302_YEAR		 0x8C
#define DS1302_WP		 0x8E

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

unsigned char DS1302_Time[]={22,10,11,23,45,45,2}; 

/**
  * @brief BCD转10进制 
  * @param  
  * @retval 
  */

unsigned char BCD_10(unsigned char Num){
	unsigned char Temp;
	Temp = Num/10*16+Num%10;
	return Temp;
}

/**
  * @brief 10进制转BCD码 
  * @param  
  * @retval 
  */

unsigned char Ten_BCD(unsigned char Num){
	unsigned char Temp;
	Temp = Num/16*10+Num%16;
	return Temp;
}

/**
  * @brief  初始化DS1302
  * @param  
  * @retval 
  */

void DS1302_Init(){
	DS1302_SCLK=0;
	DS1302_CE=0;
}

/**
  * @brief  写入字节
  * @param  
  * @retval 
  */

void DS1302_WriteByte(unsigned char Command,Data){
	unsigned char i;
	DS1302_CE=1;
	
	for(i=0;i<8;i++){
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++){
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}

/**
  * @brief  读取字节
  * @param  
  * @retval 
  */

unsigned char DS1302_ReadByte(unsigned char Command){

	unsigned char i,Data=0x00;
	Command|=0x01;
	DS1302_CE=1;
	for(i=0;i<8;i++){
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}   
	for(i=0;i<8;i++){
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;
	return Data;
}

/**
  * @brief  将数组内容写入
  * @param  
  * @retval 
  */

void DS1302_SetTime(){
	DS1302_WriteByte(DS1302_WP,0x00);
	DS1302_WriteByte(DS1302_YEAR,BCD_10(DS1302_Time[0]));
	DS1302_WriteByte(DS1302_MONTH,BCD_10(DS1302_Time[1]));
	DS1302_WriteByte(DS1302_DATE,BCD_10(DS1302_Time[2]));
	DS1302_WriteByte(DS1302_HOUR,BCD_10(DS1302_Time[3]));
	DS1302_WriteByte(DS1302_MINUTE,BCD_10(DS1302_Time[4]));
	DS1302_WriteByte(DS1302_SECOND,BCD_10(DS1302_Time[5]));
	DS1302_WriteByte(DS1302_DAY,BCD_10(DS1302_Time[6]));
	DS1302_WriteByte(DS1302_WP,0x80);
}

/**
  * @brief  读出数组内容
  * @param  
  * @retval 
  */

void DS1302_ReadTime(){
	
	DS1302_Time[0]=Ten_BCD(DS1302_ReadByte(DS1302_YEAR));
	DS1302_Time[1]=Ten_BCD(DS1302_ReadByte(DS1302_MONTH));
	DS1302_Time[2]=Ten_BCD(DS1302_ReadByte(DS1302_DATE));
	DS1302_Time[3]=Ten_BCD(DS1302_ReadByte(DS1302_HOUR));
	DS1302_Time[4]=Ten_BCD(DS1302_ReadByte(DS1302_MINUTE));
	DS1302_Time[5]=Ten_BCD(DS1302_ReadByte(DS1302_SECOND));
	DS1302_Time[6]=Ten_BCD(DS1302_ReadByte(DS1302_DAY));
}

