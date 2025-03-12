#include <AT89X52.H>
#define led1 P0_0
#define led2 P0_1
#define led3 P0_2
#define led4 P0_3
#define led5 P0_4
#define led6 P0_5
#define led7 P0_6
#define led8 P0_7
#define nutnhan P3_2
int dem = 0;
void delay_ms(int ms)
{
int x, y;
for(x=0; x<ms; x++)
for(y=0; y<125; y++);
}
void phai_trai(int so_lan)
{
	int i, s;
	for(s=0;s<so_lan;s++)
	{
			P0=0x01;
	for(i=0;i<8;i++)
	{
			delay_ms(200);
	P0=P0<<1;
	}
}
	}
void trai_phai(int so_lan)
{
	int i, s;
	for(s=0;s<so_lan;s++)
	{
			P0=0x80;
	for(i=0;i<8;i++)
	{
			delay_ms(200);
	P0=P0>>1;
	}
}
	}
void hai_ben(int so_lan)
{
int i;
for(i=0; i<so_lan; i++){
P0=0x18;
	delay_ms(250);
	P0=0x24;
	delay_ms(250);
	P0=0x42;
	delay_ms(250);
	P0=0x81;
	delay_ms(250);
} }
void main()
{ EA=EX0=1;
	nutnhan=1;
	while(1)
	{
	switch(dem)
	{
		case 0:
		trai_phai(1);
    phai_trai(1);
    hai_ben(1);
		break;
		case 1:
		trai_phai(1);
		break;
		case 2:
		phai_trai(1);
		break;
		case 3:
		hai_ben(1);
		break;
	}
}
}
void N_N0 () interrupt 0
{ delay_ms(20);
	if(nutnhan==0)
	{ dem++;
		if(dem==4)
			dem=0;
	}
		while (nutnhan==0);
	}
