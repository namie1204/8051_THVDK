#include <at89x52.h>
unsigned char hienled[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char chonled[6]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};
#define hien P2
#define chon P1
 int hour = 01;
 int minute =52;
 int second = 56;
unsigned int dem = 0;

void delay_ms(int ms)
{
  int x, y;
   for(x =0; x<ms; x++)
   for(y=0; y<125; y++);
}

void main()
{
	TMOD = 0x01;
	TR0 = 1;
	EA = ET0 = 1;
	TH0 = 0x3C;
	TL0 = 0xB0;
while(1)
{
	//hang chuc bien hour
		chon=chonled[0];
		hien=hienled[hour/10];	
		delay_ms(3);
		//hang donvi bien hour
		chon=chonled[1];
		hien=hienled[hour%10];	
		delay_ms(3);
		//hang chuc bien minute
		chon=chonled[2];
		hien=hienled[minute/10];	
		delay_ms(3);
		//hang donvi bien minute
		chon=chonled[3];
		hien=hienled[minute%10];	
		delay_ms(3);
		//hang chuc bien second
		chon=chonled[4];
		hien=hienled[second/10];	
		delay_ms(3);
		//hang donvi bien second
		chon=chonled[5];
		hien=hienled[second%10];	
		delay_ms(3);
	

}
}
	
void NT0 () interrupt 1
{
dem++;
	//while(TF0 == 0);
	if(dem==20)			 //chu ki 	   4000
	{
		second+=1;
		dem = 0;
	}
	if(second>=60)
	{		
		second = 0;
		minute++;
	}
	if(minute >= 60)
	{
	minute = 0;
		hour ++;
	}
	if (hour == 24) hour = 0;
	TH0 = 0x3C;				  // chu ki 1s	  th=6	thi x4000
	TL0 = 0xB0;
}
