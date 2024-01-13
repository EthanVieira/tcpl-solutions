#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main()
{
    // 0b01001100 -> 0b11000100
    printf("%d\n", rightrot(76, 12));
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int shifts = n % 8;
    return (getbits(x, shifts-1, shifts) << (8 - shifts) | x >> (shifts));
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
