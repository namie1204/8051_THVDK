#include<AT89x51.H>
#define LED P2_3	
#define button P3_1

void delay_ms (int ms)
{
int x,y;
for (x=0;x<ms;x++)
for (y=0;y<125;y++);
}

void main ()
{
button=1;
LED=0;
while (1)
{
if (button==0)
{
delay_ms (20);
	if ( button==0)
	{ 
	LED=~LED;
	while(button==0);
}
}
}
}
