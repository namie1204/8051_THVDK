#include <AT89x51.H>
	int dem=0;
	int dam=0;
void main ()
{
	P0=0x00;
	TMOD=0x12;
	EA=ET0=ET1=TR0=TR1=1;
	while(1)
	{
	TH0=0x06;
	TL1=0xB0;
	TH1=0x3C;
  while(1);
}
	}
void N_T0() interrupt 1
{
	dem++;
	if(dem==2000)
	{
  P2_3=~P2_3;
		dem=0;
	}

}
void N_T1() interrupt 3
{
	dam++;
	if(dam==5)
	{
  P2_4=~P2_4;
		dam=0;
	}
		
}
