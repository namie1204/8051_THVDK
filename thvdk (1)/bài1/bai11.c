#include <AT89x51.H>
void delay_ms (int ms)
{
	int x,y;
	for (x=0;x<ms;x++) 
	for (y=0;y<125;y++);
}
void main ()
{
	while (1)
	{
		P2_0=~P2_0;
		delay_ms (250);
	}
}
