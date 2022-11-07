#include <REGX52.H>
#include <intrins.h>

sbit OneWire_DQ=P3^7;


unsigned char OneWire_Init(){
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	
	_nop_();i = 204;while (--i);	//@11.0592MHz Delay 500us
	
	OneWire_DQ=1;
	_nop_();i = 29;while (--i);		//@11.0592MHz Delay 70us
	 AckBit= OneWire_DQ;
	_nop_();i = 204;while (--i);	//@11.0592MHz Delay 500us
	
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit){
	unsigned char i;
	OneWire_DQ  = 1;
	OneWire_DQ = 0;
	_nop_();i = 3;while (--i);		//@11.0592MHz Delay 10us
	OneWire_DQ=Bit;
	i = 22;while (--i);				//@11.0592MHz Delay 50us
	OneWire_DQ = 1;
}

unsigned char OneWire_ReceiveBit(){
	unsigned char i;
	unsigned char Bit;
	OneWire_DQ = 0;
	_nop_();i = 2;while (--i);		//@11.0592MHz Delay 5us
	OneWire_DQ = 1;
	_nop_();i = 2;while (--i);		//@11.0592MHz Delay 5us
	Bit = OneWire_DQ;
	i = 22;while (--i);				//@11.0592MHz Delay 50us
	
	return Bit;
}
void OneWire_SendByte(unsigned char Byte){
	unsigned char i;
	for(i=0;i<8;i++){
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

unsigned char OneWire_ReceiveByte(){
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++){
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}

