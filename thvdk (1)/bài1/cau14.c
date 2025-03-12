#include <AT89x51.H>
void delay_ms (int ms)
{
int x,y;
for(x=0;x<ms;x++)
for (y=0;y<125;y++);
}
void main ()
{	
	while (1)
	{
   P2=0x18;
   delay_ms(250);
   P2= 0x24;
   delay_ms(250);
   P2= 0x42;
   delay_ms(250);
   P2=0x81;
   delay_ms(250);
	}
 }
