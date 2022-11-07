#include <REGX52.H>
#include <intrins.h>

sbit LCD_RS = P2^6; 
sbit LCD_RW = P2^5; 
sbit LCD_E = P2^7; 

#define LCD_DataPort P0
void LCD_Delay1ms();
void LCD_SetCursor(unsigned char Line,unsigned char Colum);

void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_DataPort = Command;
	LCD_E = 1;
	LCD_Delay1ms();
	LCD_E = 0;
	LCD_Delay1ms();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_DataPort = Data;
	LCD_E = 1;
	LCD_Delay1ms();
	LCD_E = 0;
	LCD_Delay1ms();
}

void LCD_Init()
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}

/**
  * @brief  显示字符
  * @param  
  * @retval 
  */
void LCD_ShowChar(unsigned char Line,unsigned char Colum,unsigned char Char)
{
	LCD_SetCursor(Line,Colum);
	LCD_WriteData(Char);
}

/**
  * @brief  显示字符串
  * @param  
  * @retval 
  */
void LCD_ShowString(unsigned char Line,unsigned char Colum,unsigned char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Colum);
	for(i = 0; String[i] != 0 ; i++)
	{
		LCD_WriteData(String[i]);
	}
}

/**
  * @brief  次方函数
  * @param  
  * @retval 
  */
int LCD_Pow(int x, int y)
{
	unsigned char i;
	int result = 1;
	for(i=0;i<y;i++)
	{
		result = result * x;
	}
	return result;
}

/**
  * @brief  显示数字
  * @param  
  * @retval 
  */
void LCD_ShowNum(unsigned char Line,unsigned char Colum,unsigned int Number,unsigned char Lenght)
{
	unsigned char i;
	LCD_SetCursor(Line,Colum);
	for(i = Lenght; i>0 ; i--)
	{
		LCD_WriteData('0'+ Number/LCD_Pow(10,i-1)%10);
	}
}

/**
  * @brief  显示有符号数字
  * @param  
  * @retval 
  */
void LCD_ShowSignedNum(unsigned char Line,unsigned char Colum, int Number,unsigned char Lenght)
{
	unsigned char i;
	unsigned int Num;
	LCD_SetCursor(Line,Colum);
	if(Number>0)
	{
		LCD_WriteData('+');
		Num = Number;
	}
	else
	{
		LCD_WriteData('-');
		Num = - Number;
	}
	for(i = Lenght; i>0 ; i--)
	{
		LCD_WriteData('0'+ Num/LCD_Pow(10,i-1)%10);
	}
}

/**
  * @brief  显示16进制数字
  * @param  
  * @retval 
  */
void LCD_ShowBinNum(unsigned char Line,unsigned char Colum, unsigned int Number, unsigned char Lenght)
{
	unsigned char i;
	LCD_SetCursor(Line,Colum);
	for(i = Lenght; i>0 ; i--)
	{
		LCD_WriteData('0'+ Number/LCD_Pow(2,i-1)%2);
	}
}

/**
  * @brief  显示2进制数字
  * @param  
  * @retval 
  */
void LCD_ShowHexdNum(unsigned char Line,unsigned char Colum, unsigned int Number, unsigned char Lenght)
{
	unsigned char i;
	unsigned char SingleNumber;
	LCD_SetCursor(Line,Colum);

	for(i = Lenght; i>0 ; i--)
	{
		SingleNumber = Number/LCD_Pow(16,i-1)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData('0'+ SingleNumber);
		}
		else
		{
			LCD_WriteData('A'+ SingleNumber - 10);
		}
	}
}


/**
  * @brief  设置光标位置
  * @param  
  * @retval 
  */
void LCD_SetCursor(unsigned char Line,unsigned char Colum)
{
	if(Line == 1)
	{
		LCD_WriteCommand(0x80|(Colum-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Colum-1)+0x40);
	}
}



void LCD_Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

