
#include <REGX51.H>
#include "D:\Th.VDK\BAI6\Thu_Vien_LCD.h"

int dem=0;


void main()
{ 
	LCD_Init();
	LCD_Gotoxy(2,0);  //cot 2 hang 0
	LCD_Puts("223THVDK03");		  //in chuoi
	LCD_Gotoxy(2,1); 
	LCD_Puts("NHOM2");		
	while(1);		
}
