#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t temp = x;   \
        x = y;        \
        y = temp;     \
    }

int main()
{
    char s1 = 'a';
    char s2 = 'b';
    int i1 = 1;
    int i2 = 2;

    printf("%c\n", s1);
    printf("%c\n", s2);
    swap(char, s1, s2);
    printf("%c\n", s1);
    printf("%c\n", s2);

    printf("%d\n", i1);
    printf("%d\n", i2);
    swap(int, i1, i2);
    printf("%d\n", i1);
    printf("%d\n", i2);

    return 0;
}
