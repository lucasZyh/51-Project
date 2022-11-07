#ifndef __TIMER0_H__
#define __TIMER0_H__

void Timer0_Init(void);	
void Timew0_SetCount(unsigned int Value);
unsigned int Timew0_GetCount();
void Timer0_Run(unsigned char Flag);
#endif
