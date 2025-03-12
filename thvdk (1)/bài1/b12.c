#include <AT89x51.H>
void delay_ms (int ms)
{
int x,y;
for(x=0;x<ms;x++)
for (y=0;y<125;y++);
}
void main ()
{
	int t;
	while (1)
	{
		P2=0x01;
		for (t=0;t<8;t++)
	 {
		 delay_ms(100);
		 P2=P2<<1;
	}
}
	}
