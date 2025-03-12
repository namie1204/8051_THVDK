#include <AT89x51.H>
void delay_700ms(int t)
{
int i;
	for(i=0;i<t;i++)
{
	TL1=0xB0;
	TH1=0x3C;
		 while(TF1==0);
		 TF1=0;
	 }
    }
void delay_1s(int t)
{
int i;
	for(i=0;i<t;i++)
{
	TH0=6;
		 while(TF0==0);
		 TF0=0;
	 }
    }
	void main ()
	{
	TMOD=0x12;
	TR0=1;
	TR1=1;
	while (1)
	{ 
	P2=0xFF;
	delay_700ms(14);
	P2=0x00;
	delay_1s(2000);
}
}