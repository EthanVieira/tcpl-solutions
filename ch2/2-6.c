#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main()
{
    // 0b01000000 -> 0b01001100
    printf("%d\n", setbits(64, 3, 2, 3));
    return 0;
}


unsigned setbits(unsigned x, int p, int n, int y)
{
    return ((y & ~(~0 << n)) << (p + 1 - n)) | (x & ~(~(~0 << n) << (p + 1 - n)));
}

