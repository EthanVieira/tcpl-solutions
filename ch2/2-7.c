#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

int main()
{
    // 0b01001101 -> 0b01000011
    printf("%d\n", invert(77, 3, 3));
    return 0;
}


unsigned invert(unsigned x, int p, int n)
{
    return setbits(x, p, n, ~getbits(x, p, n));
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    return ((y & ~(~0 << n)) << (p + 1 - n)) | (x & ~(~(~0 << n) << (p + 1 - n)));
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
