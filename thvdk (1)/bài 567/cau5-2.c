#include <REGX52.H>
unsigned char hienled[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char chonled[6]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};
#define hien P2
#define chon P1
void delay_ms(int ms)
{
int x, y;
for(x =0; x<ms; x++)
 for(y=0; y<125; y++);
}

void main()
{ 
	while(1){
		chon=chonled[0];
		hien=hienled[9];	
		delay_ms(3);
		
		chon=chonled[1];
		hien=hienled[10];	
		delay_ms(3);

		chon=chonled[2];
		hien=hienled[11];	
		delay_ms(3);

		chon=chonled[3];
		hien=hienled[12];	
		delay_ms(3);

		
		chon=chonled[4];
		hien=hienled[13];	
		delay_ms(3);

		chon=chonled[5];
		hien=hienled[14];	
		delay_ms(3);

	}
}
