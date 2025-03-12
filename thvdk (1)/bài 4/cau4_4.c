#include <AT89x51.H>
#define button P3_2
void delay_ms (int ms)
{
int x,y;
for (x=0;x<ms;x++)
for (y=0;y<125;y++);
}
void main ()
{
	P2=0x00;
	EA=EX0=1;
	while(1);
}
void N_N0() interrupt 0
{	
if (button==0){
   delay_ms (20);
 	if (button==0)
	{ 
	P2=~P2;
	while(button==0);	
		 }
	}
}
