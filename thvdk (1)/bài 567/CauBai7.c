#include <at89x52.h>
#include <intrins.h>
#include "D:\TH VDK\Bai6\Thu_vien_LCD.h"

#define PWM_Period 0xB1DF
#define button_tang P3_2
#define button_giam P3_3

int b=0, goc;

sbit Servo_Motor_Pin = P1^0;

unsigned int ON_Period, OFF_Period, DutyCycle;

void Timer0_ISR() interrupt 1 
{
 Servo_Motor_Pin = !Servo_Motor_Pin;
 if(Servo_Motor_Pin)
 {
  TH0 = (ON_Period >> 8);
  TL0 = ON_Period;
 } 
 else
 {
  TH0 = (OFF_Period >> 8);
  TL0 = OFF_Period;
 } 
   
}

void Set_DutyCycle_To(float duty_cycle)
{
 float period = 65535 - PWM_Period;
 ON_Period = ((period/100.0) * duty_cycle);
 OFF_Period = (period - ON_Period); 
 ON_Period = 65535 - ON_Period; 
 OFF_Period = 65535 - OFF_Period;
}

void ISR_INT0() interrupt  0
{		
		delay_ms(20);
		if(button_tang==0)
		{
			if(b<4)
			b+=1;
		}
		while(button_tang==0);
} 

void ISR_INT1() interrupt 2 
{
    delay_ms(20);
		if (button_giam==0)
		{
			if (b>0)
			b-=1;
		}
		while(button_giam==0);
}

void main()
{
		EA  = 1;    
    ET0 = 1;    
    EX0 = 1;     
    EX1 = 1;     
    IT0 = 1;     
    IT1 = 1;     
    TMOD = 0x01; 
    TR0 = 1; 
		LCD_Init();
		LCD_Gotoxy(0,0);
		LCD_Puts("Goc:");
while(1)
    {
			switch(b)
			{
				case 0:
					Set_DutyCycle_To(2.8);
					goc=0;
					LCD_Gotoxy(4,0);
					LCD_PutNumber(goc);
					LCD_PutChar(' ');
					LCD_PutChar(' ');
					break;
				case 1:
					Set_DutyCycle_To(4.9);
					goc=45;
					LCD_Gotoxy(4,0);
					LCD_PutNumber(goc);
					LCD_PutChar(' ');
					break;
				case 2:
					Set_DutyCycle_To(7.43);
					goc=90;
					LCD_Gotoxy(4,0);
					LCD_PutNumber(goc);
					LCD_PutChar(' ');
					break;
				case 3:
					Set_DutyCycle_To(9.65);
					goc=135;
					LCD_Gotoxy(4,0);
					LCD_PutNumber(goc);
					break;
				case 4:
					Set_DutyCycle_To(11.8);
					goc=180;
					LCD_Gotoxy(4,0);
					LCD_PutNumber(goc);
					break;					
			}				
    }
}