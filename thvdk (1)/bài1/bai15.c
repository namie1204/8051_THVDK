#include <AT89X51.h>
int s,t;
void delay_ms(int ms)
{
  int x,y;
  for(x=0;x<ms;x++)
   for(y=0;y<125;y++);
 }
 void phai_trai (unsigned int dem )
 { for(s=0;s<dem;s++)
	 {
    P2=0x01;
   for(t=0;t<8;t++)
  {
    delay_ms(250);
    P2=P2<<1;
  }
 }
	 }
  void trai_phai ( unsigned int count )
{ for(s=0;s<count;s++)
	{
    P2=0x80;
   for(t=0;t<8;t++)
   {

    delay_ms(250);
    P2=P2>>1;
	}
}
	}
  void giua_ben ( unsigned int so_lan )
{	  for(s=0;s<so_lan;s++)
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
  void main ()
{
	while (1)
	{
  phai_trai(1);
  trai_phai(3);
  giua_ben (2);
	}
}
