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



sbit IN1 = P2^1;       // chieu thuan
sbit IN2 = P2^2;	  // chieu nghich
sbit ENA = P2^0;       // chan chinh toc do, ENA =1 CANG LAU TOC DO CANG NHANH
#define button_tang P3_3
#define button_giam P3_2		  ///////////
#define button_dc P3_4

char dutyCycle = 5, choose=0; 

unsigned char counter = 0;     

void Timer0_ISR(void) interrupt 1 {
		
		TH0 = 6; 
		counter++;            
    if(counter <= dutyCycle) {
        ENA = 1;      			   // duty tang tuc ENA =1 duoc lau hon nen quay nhanh hon
    } else {
        ENA = 0;       
    }

    if(counter >= 10) {
        counter = 0;   
    }
}

void ISR_INT0() interrupt  0
{
	delay_ms(20);
	if(button_giam==0){
		if (dutyCycle>0)
				dutyCycle-=1;		
	while(button_giam==0);
	}   
}
void ISR_INT1() interrupt 2 {
    delay_ms(20);
	if (button_tang==0){
		if (dutyCycle<10)
				dutyCycle+=1;
	while(button_tang==0);
	}
}

void main() {
    TMOD |= 0x02; 
		TH0=6;
    TR0 = 1;           
    ET0 = 1;           
    EA = 1;     
		EX0=EX1=1;
		LCD_Init();
    while(1) {
        if(button_dc==0) {
					delay_ms(20);
					if(button_dc==0) {
						choose++;
						if(choose==2)
							choose=0;
					}
						while(button_dc==0);					
				}
				switch(choose)
				{
					case 0: 
						IN1=1;	  // thuan
						IN2=0;
						LCD_Gotoxy(10,1);
						LCD_Puts(" ");
						LCD_Gotoxy(5,1);
						LCD_Puts("thuan");
					break;
					case 1: 
						IN1=0;
						IN2=1;	   // nghich
						LCD_Gotoxy(5,1);
						LCD_Puts("nghich");
					break;
				}
				LCD_Gotoxy(0,0);
				LCD_Puts("Toc do:");			
				LCD_PutNumber(dutyCycle*10);
				LCD_Puts("%");
				LCD_Gotoxy(0,1);
				LCD_Puts("Quay");			
    }
}