#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3^5;	//RCLK
sbit SCK = P3^6;	//SRCLK
sbit SER = P3^4;	//SER

/**
  * @brief  74HC595写入一个字节
  * @param  要写入的字节
  * @retval 无
  */

void _74HC595_WriteByte(unsigned char byet){
	
	unsigned char i;
	for(i=0;i<8;i++){
		SER = byet&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

/**
  * @brief  点阵屏初始化
  * @param  无
  * @retval 无
  */

void LED_Init(){
	SCK=0;
	RCK=0;
}

/**
  * @brief LED 点阵显示一列数据 
  * @param  Data 为列显示数据/column为显示的列
  * @retval 无
  */

void LED(unsigned char Column,Data){
	_74HC595_WriteByte(Data);
	P0 = ~(0x80>>Column);
	Delay(1);
	P0=0xFF;
}