#include <REGX51.H>
#include "Key.h"
#include "Shu.h"
#include "Buzzer.h"

unsigned char KeyNumber;


void main(){
	
	while(1){
		KeyNumber = Key();
		if(KeyNumber){
			Buzzer_Time(100);
			Shu(1,KeyNumber);
		}
	}
}
