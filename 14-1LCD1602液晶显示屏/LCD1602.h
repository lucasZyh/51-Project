#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_WriteCommand(unsigned char Command);
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Colum,unsigned char Char);
void LCD_ShowString(unsigned char Line,unsigned char Colum,unsigned char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Colum,unsigned int Number,unsigned char Lenght);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Colum, int Number,unsigned char Lenght);
void LCD_ShowHexdNum(unsigned char Line,unsigned char Colum, unsigned int Number, unsigned char Lenght);
void LCD_ShowBinNum(unsigned char Line,unsigned char Colum, unsigned int Number, unsigned char Lenght);
#endif
