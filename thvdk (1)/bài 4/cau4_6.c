#include<AT89X52.H>
#define tang P3_2
#define giam P3_3
int dem =0;
int a = 5;
void delay_ms(int ms)
{
int x, y;
for(x=0; x<ms; x++)
 for(y=0; y<125; y++);
}
void main()
{
TMOD=0x01;
	EA=ET0=EX0=EX1=IT0=IT1=1;
	PT1=PX1=1;
	TR0=1;
	while(1)
	{
	TH0=0x3C;
		TL0=0xB0;
		while(1);
	}
}
void N_N0() interrupt 0 {
    delay_ms(20);
    if (tang == 0) 
			{ 
			if (a<15) a++;
    }
		while(tang==0);
}
void N_N1() interrupt 2 {
    delay_ms(20);
    if (giam == 0) 
			{ 
	  if (a>1) a--;
    }
		while(giam==0);
}
void N_T0() interrupt 1
{
  dem++;
  delay_ms(200);
		if(dem>=a){
			P2_4=~P2_4;
			dem = 0;
		}
}
