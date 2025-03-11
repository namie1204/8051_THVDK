#include <AT89x51.H>
void delay_ms()
{int i;
	for(i=0;i<5;i++)
{
	TL0=0xB0;
	TH0=0x3C;
		 while(TF0==0);
		 TF0=0;
	 }
    }
void main()
{ TMOD=0x01;
	TR0=1;
	while (1)
	{
	P2_2=~P2_2;
	delay_ms();
	}
}
