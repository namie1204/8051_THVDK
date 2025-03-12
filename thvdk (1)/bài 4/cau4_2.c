#include <AT89x51.H>
	int dem=0;
void main ()
{
	P2=0x00;
	TMOD=0x02;
	EA=ET0=TR0=1;
  while(1);
}
	
void N_T0() interrupt 1
{
	dem++;
	if(dem==2000)
	{
  P2_3=~P2_3;
  dem=0;
	}
		while(TF0==0);
}
