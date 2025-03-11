/* =====================================================
    TÓM TẮT CÁC CHẾ ĐỘ (MODE) CỦA TIMER/COUNTER 8051
=====================================================

1. TIMER 0: (Hỗ trợ 4 chế độ)
-------------------------------------
| Chế độ (Mode) | Giải thích                                | Giá trị đếm       |
|---------------|-------------------------------------------|-----------------  |
| Mode 0        | 13-bit Timer/Counter                      | 0x0000 - 0x1FFF   |
| Mode 1        | 16-bit Timer/Counter                      | 0x0000 - 0xFFFF   |
| Mode 2        | 8-bit Auto-reload (nạp lại từ TH0 khi tràn)| 0x00 - 0xFF      |
| Mode 3        | Chia thành 2 Timer 8-bit độc lập (TL0, TH0)| 0x00 - 0xFF      |

Lưu ý:
- Mode 3: Timer0 tách làm 2 Timer 8-bit, Timer1 bị khóa.

-------------------------------------

2. TIMER 1: (Hỗ trợ 3 chế độ)
-------------------------------------
| Chế độ (Mode) | Giải thích                                | Giá trị đếm      |
|---------------|-------------------------------------------|----------------- |
| Mode 0        | 13-bit Timer/Counter                      | 0x0000 - 0x1FFF  |
| Mode 1        | 16-bit Timer/Counter                      | 0x0000 - 0xFFFF  |
| Mode 2        | 8-bit Auto-reload (nạp lại từ TH1 khi tràn)| 0x00 - 0xFF     |
------------------------------------
3. SO SÁNH TIMER 0 VÀ TIMER 1
-------------------------------------
| Thuộc tính             | Timer 0                          | Timer 1             |
|------------------------|----------------------------------|---------------------|
| Số Mode hỗ trợ         | 4 (Mode 0, 1, 2, 3)              | 3 (Mode 0, 1, 2)    |
| Chia đôi 2 Timer 8-bit | Có (Mode 3)                      | Không               |
| Hoạt động độc lập      | Có                               | Có                  |
| Tạo ngắt riêng biệt    | Có (TF0/ET0)                     | Có (TF1/ET1)        |
| Đếm xung ngoài         | Có (chân P3.4 - T0)              | Có (chân P3.5 - T1) |
-------------------------------------
4. THANH GHI LIÊN QUAN
-------------------------------------
- TMOD: Chọn chế độ cho Timer (8 bit)
    Bit 7   : GATE (Timer1) - Kích hoạt qua INT1
    Bit 6   : C/T (Timer1)  - Chọn Timer (0) hay Counter (1)
    Bit 5-4 : M1, M0 (Timer1) - Chọn mode
    Bit 3   : GATE (Timer0) - Kích hoạt qua INT0
    Bit 2   : C/T (Timer0)  - Chọn Timer (0) hay Counter (1)
    Bit 1-0 : M1, M0 (Timer0) - Chọn mode

- TCON: Điều khiển Timer, External Interrupt
    Bit 7   : TF1 (Flag tràn Timer1)
    Bit 6   : TR1 (Bật/tắt Timer1)
    Bit 5   : TF0 (Flag tràn Timer0)
    Bit 4   : TR0 (Bật/tắt Timer0)

- TH0, TL0: Giá trị đếm của Timer0
- TH1, TL1: Giá trị đếm của Timer1
-------------------------------------
5. CÁCH CHỌN MODE CHO TIMER (TRONG TMOD)
-------------------------------------
| M1 | M0 | Mode                         |
|----|----|------------------------------|
| 0  | 0  | Mode 0 (13-bit)               |
| 0  | 1  | Mode 1 (16-bit)               |
| 1  | 0  | Mode 2 (8-bit Auto-reload)   |
| 1  | 1  | Mode 3 (Chỉ Timer0, tách Timer) |

Ví dụ:
TMOD = 0x01; // Timer0, Mode 1 (16-bit)
TMOD = 0x20; // Timer1, Mode 2 (8-bit auto-reload)

===================================================== */
#include <stdio.h>
#define BUFFER_SIZE 10

unsigned char buffer[BUFFER_SIZE];
unsigned char head = 0;
unsigned char tail = 0;

// Ghi dữ liệu vào buffer
void write_buffer(unsigned char data)
{
    buffer[head] = data;
    head = (head + 1) % BUFFER_SIZE;
}

// Đọc dữ liệu từ buffer
unsigned char read_buffer()
{
    unsigned char data = buffer[tail];
    tail = (tail + 1) % BUFFER_SIZE;
    return data;
}

int main()
{
    int i;

    // Ghi từ 1 đến 10
    for (i = 1; i <= 10; i++)
    {
        write_buffer(i);
    }

    // Đọc và in ra từ 1 đến 10
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", read_buffer());
    }

    return 0;
}
