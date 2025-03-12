#include <Thu_Vien_LCD.h>
#include <REGX52.H>
int gio=17;
int phut=1;
int giay=5;
int dem=0;
int a=0;
#define tang P3_2
#define giam P3_3
#define chon P3_4

void Delay(unsigned int ms)
{
		unsigned int x, y;
		for(x=0;x<ms;x++)
		{
			for(y=0;y<125;y++);
		}
}

void NgatTimer0() interrupt 1 
{
	TH0=0x3C;  
  TL0=0xB0;
  dem++;
  if(dem==20) 
		{
			dem=0;
      giay++;   
      if(giay==60)
				{ 
					giay=0;
					phut++;
					if(phut==60) 
						{
							phut=0;
							gio++;
              if(gio==24) 
                 gio=0;     
						}
        }
    }
}

void Tang() interrupt 0
{
	Delay(20);
	{
		if(tang==0)
		{
			 if(a==0)
			 {
			   	phut++;
			  	if(phut==60)
			  	{
		         phut=0;
				 gio++;
				  }
				}
			 if(a==1)
			 {
				  gio++;
			    if(gio==24)
				  {
				     gio=0;
			    }
		   }	
	   	  while(tang==0);	
	  } 
   }
}

void Giam() interrupt 2
{
	Delay(20);
	{
		if(giam==0)
		{
			 if(a==0)
			 {
			   	phut--;
			  	if(phut<0)
			  	{
		         phut=59;
				 gio--;
				  }
				}
			 if(a==1)
			 {
				  gio--;
			    if(gio<0)
				  {
				     gio=23;
			    }
		   }
		   	while(giam==0);		   
	  } 
   }
}

void chongiophut()
{
	if(chon==0)								
		{	
			Delay(20);
			if(chon==0)
				{
					a++;											
					if(a==2)
					{
					a=0;
					}
					while(chon==0);
				}
		}
}

void main()
{ 
	TMOD=0x01; 
  TH0=0x3C;  
  TL0=0xB0;     
  EA=ET0=EX0=EX1=1;
	IT0=IT1=1; 
	PT0=1;
  TR0=1;
	
	LCD_Init();	
	LCD_Gotoxy(3,0); 
	LCD_Puts("DONG HO SO");
	
	while(1)
	{	
		chongiophut();
		
		LCD_Gotoxy(4,1);
		LCD_PutNumber(gio/10);
		LCD_PutNumber(gio%10);
		LCD_PutChar(':');
		
		LCD_Gotoxy(7,1);
		LCD_PutNumber(phut/10);
		LCD_PutNumber(phut%10);
		LCD_PutChar(':');
		
		LCD_Gotoxy(10,1);
		LCD_PutNumber(giay/10);
		LCD_PutNumber(giay%10);
	}
}
