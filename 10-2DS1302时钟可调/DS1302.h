#ifndef __SD1302_H__
#define __SD1302_H__

extern unsigned char DS1302_Time[];

void DS1302_Init();
void DS1302_ReadTime();
void DS1302_SetTime();

#endif
