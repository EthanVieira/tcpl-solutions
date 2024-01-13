#include <stdio.h>

// It deletes the rightmost bit because by subtracting 1,
// the rightmost set bit will change to a 0 while all of the
// following bits to the right will change from 0 to 1
// and the bits to the left will not be altered.
// This makes the & operation only change the rightmost set bit to a 0.

int bitcount(unsigned x);

int main()
{
    // 0b01001101 -> 4
    printf("%d\n", bitcount(77));

    return 0;
}

int bitcount(unsigned x)
{
    int b = 0;
    while (x != 0)
    {
        x &= (x - 1);
        b++;
    }

    return b;
}
