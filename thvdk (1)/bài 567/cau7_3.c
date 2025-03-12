#include "D:\Th.VDK\BAI6\Thu_Vien_LCD.h"
#include <REGX52.H>
#define A P0_1
#define B P0_2
#define C P0_3
#define D P0_4
#define dao P3_0
#define tang P3_2
#define giam P3_3
int chieu = 1;
unsigned int dem = 0;
unsigned int count = 0;
unsigned int a = 5;
unsigned int check = 0;
 
void daoChieu()
{
	if(dao==0)
	{

	if(dao==0)
	{
if(chieu==0)
{	chieu = 1;
	} else {
		chieu = 0;}
	}
  }
}
void dongCo ()
{
if(dem>=a)
	{
		if(check==0)
		{
		count ++;
		} else if(check ==1)
		{
				count=count+2;
		} else {
		count =  count+3;
		}
		if(count >8) count = 1;
	switch( count)
	{
		case 1:
			A = 1;
		  B = C = D = 0;
		break;
		case 2:
			A = B = 1;
		  C = D = 0;
		break;
		case 3:
			A = C = D = 0;
		  B = 1;
		break;
		case 4:
			A = D = 0;
		  B = C = 1;
		break;
		case 5:
			A = B = D = 0;
		  C = 1;
		break;
		case 6:
			A = B = 0;
		  C = D = 1;
		break;
		case 7:
			A = B = C = 0;
		  D = 1;
		break;
		case 8:
			A = D = 1;
		  B = C = 0;
		break;
	}
	dem = 0;
}
	}
void main()
{
	LCD_Init();
	TMOD = 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	A=B=C=D=0;
	EA = EX0 = EX1 = ET0 = 1;
	TR0=1;
while(1)
{
dongCo();
daoChieu();
LCD_Gotoxy(0, 0);
LCD_Puts("gocQuay: ");
if(check ==0) 		LCD_Puts("45 do  ");
if(check ==1) 		LCD_Puts("90 do  ");
if(check ==2) 		LCD_Puts("135 do  ");
}
}

void NN0 () interrupt 0
{

	if(tang == 0 && check < 2)
	{
check++;
		while(tang == 0);
	}
}

void NN1 () interrupt 2
{

	if(giam == 0 && check > 0)
	{
check--;
		while(giam == 0);
	}
}
void NT0 () interrupt 1
{
dem++;
	TH0 = 0x3C;
	TL0 = 0xB0;
}
