#include <REGX51.H>
#include <Thu_Vien_LCD.h>

#define LCD_RS  P1_7
#define LCD_RW  P1_5
#define LCD_EN  P1_6
#define LCD_D4  P0_4
#define LCD_D5  P0_5
#define LCD_D6  P0_6
#define LCD_D7  P0_7

void delay_us(unsigned int t){
        unsigned int i;
        for(i=0;i<t;i++);
}
void delay_ms(unsigned int t){
        unsigned int i,j;
        for(i=0;i<t;i++)
        for(j=0;j<125;j++);}
void LCD_Enable(void){
        LCD_EN =1;
        delay_us(3);
        LCD_EN =0;
        delay_us(50); 
}
void LCD_Send4Bit(unsigned char Data){
        LCD_D4=Data & 0x01;
        LCD_D5=(Data>>1)&1;
        LCD_D6=(Data>>2)&1;
        LCD_D7=(Data>>3)&1;
}
void LCD_SendCommand(unsigned char command){
        LCD_Send4Bit(command >>4);/* Send 4 bit high */
        LCD_Enable();
        LCD_Send4Bit(command); /* Send 4 bit low*/
        LCD_Enable();
}
void LCD_Clear(){// Xoa man hinh
        LCD_SendCommand(0x01); 
        delay_us(10);
}
void LCD_Init(){
        LCD_Send4Bit(0x00);	  //turn on LCD
        delay_ms(20);
        LCD_RS=0;
        LCD_RW=0;
        LCD_Send4Bit(0x03);	  //function setting
        LCD_Enable();
        delay_ms(5);
        LCD_Enable();
        delay_us(100);
        LCD_Enable();
        LCD_Send4Bit(0x02);	  //di chuyen con tro ve dau man hnh
        LCD_Enable();
        LCD_SendCommand( 0x28 ); //lua chon che do 4 bit
        LCD_SendCommand( 0x0c);  // bat hien thi va tat con tro di
        LCD_SendCommand( 0x06 );
        LCD_SendCommand(0x01);
}
void LCD_Gotoxy(unsigned char x, unsigned char y){
        unsigned char address;
        if(!y)address=(0x80+x);
        else address=(0xc0+x);
        delay_us(1000);
        LCD_SendCommand(address);
        delay_us(50);
}
void LCD_PutChar(unsigned char Data){
        LCD_RS=1;
        LCD_SendCommand(Data);
        LCD_RS=0 ;
}
void LCD_Puts(char *s){
        while (*s){
                LCD_PutChar(*s);
                s++;
        }
}
void LCD_PutNumber(int number)
{
	if(number <= 9)
	{
		LCD_PutChar(number + 48);
	}
	else if(number > 9 && number < 100)
	{
		LCD_PutChar(number/10 + 48);
		LCD_PutChar(number%10 + 48);
	}
	else if(number > 99 && number < 1000)
	{
		LCD_PutChar(number/100 + 48);
		LCD_PutChar(number/10%10 + 48);
		LCD_PutChar(number%10 + 48);
	}
	else if(number > 999 && number < 10000)
	{
		LCD_PutChar(number/1000 + 48);
		LCD_PutChar(number/100%10 + 48);
		LCD_PutChar(number/10%10 + 48);
		LCD_PutChar(number%10 + 48);
	}
	
}





#define B P2
#define button_tang P3_2
#define button_giam P3_3
#define button_choose P3_4

int b=10;
int i=1, count=0, choose=0,so_vong=0;
//unsigned char motor_degrees_half[] = {0x03, 0x06, 0x0C, 0x09};
//unsigned char code motor_degrees_half_n[] = {0x01, 0x09, 0x08, 0x0C, 0x04, 0x06, 0x02, 0x03};

void StepMotor(int i) {
    switch(i) {
        case 0:
            B=0x03;
            break;
        case 1:
            B=0x06;
            break;
        case 2:
            B=0x0C;
            break;
        case 3:
            B=0x09;
            break;
    }
}

void timer0_ISR() interrupt 1
	{
			TH0=0xFE;
			TL0=0x0C;
			count++;
			if (count>=b){
				StepMotor(i);
				count=0;
				if(choose==0)
					i++;	
				else 
					i--;
				if(i>4){
				i=0;
				}
				else if(i<0){
				i=3;				
				}
		}
	}

void ISR_INT0() interrupt  0
{		
		delay_ms(20);
		if(button_tang==0)
		{
			if(b<15)
			b+=2;
		}
		while(button_tang==0);
} 

void ISR_INT1() interrupt 2 
{
    delay_ms(20);
		if (button_giam==0)
		{
			if (b>5)
			b-=2;
		}
		while(button_giam==0);
}
	
void main()
{
  P0=0xFF;
	TMOD = 0x01;
	EA=ET0=TR0=1;
	EX0=EX1=1;
	LCD_Init();
	LCD_Gotoxy(0,0);
	LCD_Puts("toc do:");							
	LCD_Gotoxy(0,1);
	LCD_Puts("Sovongquay:");

	while(1)
	{
		if(button_choose==0)
				{
					delay_ms(20);
					if(button_choose==0){
						choose++;
						if(choose==2){
							choose=0;
						}
					}
					while(button_choose==0);
				}							
	}
}