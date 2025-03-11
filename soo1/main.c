#include <AT89X51.H>

void delay_timer1(unsigned int n);
void delay_timer0(unsigned int n);

void main()
{
    while (1)
    {
        P1 = 0xFF;         // Bat tat ca LED
        delay_timer1(100); // Delay 1s (100ms x 10) bang Timer 1
        P1 = 0x00;         // Tat tat ca LED
        delay_timer0(100); // Delay 2s (100ms x 20) bang Timer 0
    }
}
// Ham delay (n x 100ms) su dung Timer 1 o che do 16-bit (Mode 1)
void delay_timer1(unsigned int n)
{
    unsigned int i;
    TMOD &= 0x0F; // Xoa 4 bit cao (giu nguyen Timer 0), cau hinh Timer 1
    TMOD |= 0x10; // Chon Timer 1, Mode 1 (16-bit)

    for (i = 0; i < n; i++)
    {
        TH1 = 0x3C; // Nap gia tri de tran sau ~100ms voi thach anh 11.0592MHz
        TL1 = 0xB0;
        TR1 = 1; // Bat Timer 1

        while (TF1 == 0)
            ;    // Cho Timer 1 tran
        TR1 = 0; // Tat Timer 1
        TF1 = 0; // Xoa co tran
    }
}

// Ham delay (n x 100ms) su dung Timer 0 o che do 8-bit Auto-reload (Mode 2)
void delay_timer0(unsigned int n)
{
    unsigned int i, j, k;

    TMOD &= 0xF0; // Xoa 4 bit thap (giu nguyen Timer 1), chon Timer 0 NOTE: &= AND
    // a &= b; tương đương với: a = a & b;
    TMOD |= 0x02; // Chon Mode 2: 8-bit tu nap lai (Auto-reload) |= OR
    // a |= b;  a = a | b
    TH0 = 0x1A; // Nap gia tri tu dong nap lai -> ~250us
    TL0 = 0x1A; // Gia tri khoi tao lan dau

    for (i = 0; i < n; i++)
    { // Lap n lan (n x 100ms)
        for (j = 0; j < 400; j++)
        {            // Moi lan 250us x 400 = 100ms
            TR0 = 1; // Bat Timer 0
            while (TF0 == 0)
                ;    // Cho khi tran xay ra
            TF0 = 0; // Xoa co tran
        }
        TR0 = 0; // Tat Timer 0 sau moi 100ms
    }
}
