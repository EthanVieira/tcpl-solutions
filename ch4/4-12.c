#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int itoa(int n, char s[]);

int main()
{
    int i1 = -12;
    int i2 = -2147483647;
    int i3 = 2147483647;
    int i4 = 5778;

    char resultStr1[100];

    resultStr1[0] = '\0';

    itoa(i1, resultStr1);
    printf("%s\n", resultStr1);

    resultStr1[0] = '\0';
    itoa(i2, resultStr1);
    printf("%s\n", resultStr1);

    resultStr1[0] = '\0';

    itoa(i3, resultStr1);
    printf("%s\n", resultStr1);

    resultStr1[0] = '\0';

    itoa(i4, resultStr1);
    printf("%s\n", resultStr1);
    return 0;
}

int itoa(int n, char s[])
{
    int i = 0;
    bool isNegative = n < 0;
    bool isMinInt = false;

    // assume this will never be the case by accident
    if (s[0] == '-')
    {
        i++;
    }
    else if (isNegative)
    {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
    {
        i = itoa(n / 10, s);
    }

    s[i++] = n % 10 + '0';
    s[i] = '\0';

    return i;
}
