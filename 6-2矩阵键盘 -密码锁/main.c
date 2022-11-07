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
			if(KeyNum <= 10 && count <4){ //������ȡ��Ч��Χ 1~10�����ж��Ƿ񳬳���λ
				PassWord =PassWord * 10;//��������
				PassWord =PassWord+KeyNum%10;//��ȡ��һλ����
				LCD_ShowNum(2,1,PassWord,4);
				count++;//����
			}
			if(KeyNum == 11){//�������S11��ȷ��
				if(PassWord == 2345){//��֤����
					LCD_ShowString(1,14,"OK ");
					//����
					PassWord = 0;
					count = 0;
					LCD_ShowNum(2,1,PassWord,4);
				}else{//��֤����
					LCD_ShowString(1,14,"ERR");
					PassWord = 0;
					count = 0;
					LCD_ShowNum(2,1,PassWord,4);
				}
			}
			if(KeyNum == 12){//�������S12��ȡ��
				//����
				PassWord = 0;
				count = 0;
				LCD_ShowNum(2,1,PassWord,4);
			}
		}		
	}
}
