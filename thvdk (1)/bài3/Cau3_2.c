#include <AT89x51.H>
void delay_ms()
{ int i; 
	for(i=0;i<2000;i++)
	{
	TH0=6;
		 while(TF0==0);
		 TF0=0;
	 }
    }
void main()
{ TMOD=0x02;
	TR0=1;
	while (1)
	{
	P2_2=~P2_2;
	delay_ms();
	}
}
