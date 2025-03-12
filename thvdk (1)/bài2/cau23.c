#include <AT89X52.H>

#define nutnhan P3_0
	int i, s;
void delay_ms(int ms)
{
int x, y;
for(x=0; x<ms; x++)
for(y=0; y<125; y++);
}
void phai_trai(int so_lan)
{
	for(s=0;s<so_lan;s++)
	{
			P2=0x01;
	for(i=0;i<8;i++)
	{
			delay_ms(200);
	P2=P2<<1;
	}
}
	}
void trai_phai(int so_lan)
{
	for(s=0;s<so_lan;s++)
	{
			P2=0x80;
	for(i=0;i<8;i++)
	{
			delay_ms(200);
	P2=P2>>1;
	}
}
	}
void hai_ben(int so_lan)
{
for(i=0; i<so_lan; i++){
P2=0x18;
	delay_ms(250);
	P2=0x24;
	delay_ms(250);
	P2=0x42;
	delay_ms(250);
	P2=0x81;
	delay_ms(250);
}
}
void main()
{
	int dem =0;
	nutnhan = 1;
while(1)
{
	if(nutnhan==0)
	{
	delay_ms (20);
		if(nutnhan==0)
		{
		dem++;
		if(dem==5) 
			dem=1;
		while(nutnhan==0);
		}
	}
	switch(dem)
	{
		case 1:
		trai_phai(1);
    phai_trai(1);
    hai_ben(1);
		break;
		case 2:
		trai_phai(1);
		break;
		case 3:
		phai_trai(1);
		break;
		case 4:
		hai_ben(1);
		break;
	}
}
}
