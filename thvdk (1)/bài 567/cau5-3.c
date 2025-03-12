#include <REGX52.H>
unsigned char hienled[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char chonled[6]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};
int a = 243;
int b = 450;
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
		//bien a, hang tram
		chon=chonled[0];
		hien=hienled[a/100];	
		delay_ms(3);
		//bien a, hang chuc
		chon=chonled[1];
		hien=hienled[(a%100)/10];	// chia 100 lay du chia
		delay_ms(3);
    //bien a, hang don vi
		chon=chonled[2];
		hien=hienled[a%10];	
		delay_ms(3);

		//bien b, hang tram
		chon=chonled[3];
		hien=hienled[b/100];	
		delay_ms(3);
		//bien b, hang chuc
		chon=chonled[4];
		hien=hienled[(b%100)/10];	
		delay_ms(3);
    //bien b, hang don vi
		chon=chonled[5];
		hien=hienled[b%10];	
		delay_ms(3);

	}
}
