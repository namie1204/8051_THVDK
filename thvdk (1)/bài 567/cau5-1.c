#include<AT89X52.H>	
void delay_ms (int ms)
{
	int x,y;
	for (x=0;x<ms;x++) 
	for (y=0;y<125;y++);
}
unsigned char hienled[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char chonled[6]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};
void main() 
	{
 	while(1){
		P1=chonled[3];	   //chon led
		P2=hienled[13];	   //hien led
		delay_ms(3);
		P1=chonled[1];	   //chon led
		P2=hienled[8];	   //hien led
		delay_ms(3);
	}
}
