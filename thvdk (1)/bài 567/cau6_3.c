#include <REGX52.H>
#include "D:\Th.VDK\BAI6\Thu_Vien_LCD.h"
unsigned int dem = 0;
unsigned int hour = 15;
unsigned int minute = 8;
unsigned int second = 11;

void main() {
    LCD_Init();
TMOD = 0x01;
	TR0 = 1;
	EA = ET0 = 1;
	TH0 = 0x3C;
	TL0 = 0xB0;
    while (1) {
        LCD_Gotoxy(3, 0);
			        LCD_PutNumber(hour/10);
						        LCD_PutNumber(hour % 10);
        LCD_PutChar(':');
			        LCD_PutNumber(minute / 10);
						        LCD_PutNumber(minute % 10);
        LCD_PutChar(':');
			        LCD_PutNumber(second / 10);
						        LCD_PutNumber(second % 10);
        
        
            }
        }
    

void NT0 () interrupt 1
{
dem++;
	//while(TF0 == 0);
	if(dem==20)	
	{
		second++;
		dem = 0;
	}
	if(second==60)
	{		
		second =0;
		minute++;
	}
	if(minute == 60)
	{
	minute = 0;
		hour ++;
	}
	if (hour == 24) hour = 0;
	TH0 = 0x3C;
	TL0 = 0xB0;
}
