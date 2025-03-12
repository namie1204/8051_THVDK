#include <AT89x51.H>
int dem = 0;
void main()
{
	P2 = 0x00;
	TMOD = 0x01;
	EA = ET0 = TR0 = 1;
	while (1)
		;
}

void N_T0() interrupt 1
{
	dem++;
	if (dem == 5)
	{
		P2 = ~P2;
		dem = 0;
		TL0 = 0xB0;
		TH0 = 0x3C;
	}
	while (TF0 == 0)
		;
}
