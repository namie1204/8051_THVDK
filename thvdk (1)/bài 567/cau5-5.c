#include <at89x52.h>
#define chonMode P3_4
#define tang P3_2
#define giam P3_3
#define hien P2
#define chon P1
unsigned char maled[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char TTled[6]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};
unsigned int hour = 5;
unsigned int minute = 10;
unsigned int second = 10;
unsigned int dem = 0;
unsigned int state = 0;

void delay_ms(int ms)
{
  int x, y;
   for(x =0; x<ms; x++)
   for(y=0; y<125; y++);
}

void mode()
{
	chonMode = 1;
if(chonMode==0)
{
delay_ms(20);
	if(chonMode==0)
	{
	state++;
		if(state>=2) state = 0;
		while(chonMode==0);
	}
}
while(chonMode==0);
}

void ledDisplay()
	{
		
	//hang chuc bien hour
		chon=TTled[0];
		hien=maled[hour/10];	
		delay_ms(3);
		//hang donvi bien hour
		chon=TTled[1];
		hien=maled[hour%10];	
		delay_ms(3);
		//hang chuc bien minute
		chon=TTled[2];
		hien=maled[minute/10];	
		delay_ms(3);
		//hang donvi bien minute
		chon=TTled[3];
		hien=maled[minute%10];	
		delay_ms(3);
		//hang chuc bien second
		chon=TTled[4];
		hien=maled[second/10];	
		delay_ms(3);
		//hang donvi bien second
		chon=TTled[5];
		hien=maled[second%10];	
		delay_ms(3);
	}
void main()
{
	TMOD = 0x01;
	TR0 = 1;
	EA = ET0 = EX0 = EX1 = 1;
	TH0 = 0x3C;
	TL0 = 0xB0;
while(1)
{
	mode();
	ledDisplay();
}
}
	
void NT0 () interrupt 1
{
dem++;
	//while(TF0 == 0);
	TH0 = 0x3C;
	TL0 = 0xB0;
		
		if(dem==20)	 // chu ki 1s
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
}

void NN0 () interrupt 0
{
delay_ms(20);
	if(tang==0)
	{
	if(state==0 && minute < 59)
	{
		minute++;
			if(minute==60)
		{
		 minute==0;
			hour++;
		}

	}
	if(state==1 && hour < 24)
	{
	hour++;
	}
	}
	while(tang==0);
}

void NN1 () interrupt 2
{
delay_ms(20);
	if(giam==0)
	{
	if(state==0 && minute > 0)
	{
		minute--;
		if(minute==0)
		{
		 minute=59;
			hour--;
		}
	}
	if(state==1 && hour > 0)
	{
	hour--;
	if(hour==0){ hour=23;}
	}
	}
	while(giam==0);
}
