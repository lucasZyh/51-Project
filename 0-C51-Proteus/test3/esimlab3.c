#include <REGX51.H>//调用51单片机头文件

void main(){
	
	while(1){
		//判断按键是否按下
		if(P3_0 == 0)
		{
			P1_0 = 0;//按键按下，LED灯点亮
		}
		else
		{
			P1_0 = 1;//按键松开，LED灯熄灭
		}
	}
}
