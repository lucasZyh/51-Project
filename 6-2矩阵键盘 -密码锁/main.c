#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int PassWord,count;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	while(1){
		KeyNum = MatrixKey();
		if(KeyNum!=0){
			if(KeyNum <= 10 && count <4){ //按键读取有效范围 1~10，并判断是否超出四位
				PassWord =PassWord * 10;//密码左移
				PassWord =PassWord+KeyNum%10;//获取新一位密码
				LCD_ShowNum(2,1,PassWord,4);
				count++;//计数
			}
			if(KeyNum == 11){//如果按下S11，确定
				if(PassWord == 2345){//验证密码
					LCD_ShowString(1,14,"OK ");
					//清零
					PassWord = 0;
					count = 0;
					LCD_ShowNum(2,1,PassWord,4);
				}else{//验证密码
					LCD_ShowString(1,14,"ERR");
					PassWord = 0;
					count = 0;
					LCD_ShowNum(2,1,PassWord,4);
				}
			}
			if(KeyNum == 12){//如果按下S12，取消
				//清零
				PassWord = 0;
				count = 0;
				LCD_ShowNum(2,1,PassWord,4);
			}
		}		
	}
}
