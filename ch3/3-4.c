#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void itoa(int n, char s[]);
void reverse(char s[]);

// the reason why the implementation of itoa provided in K&R does not work for the smallest negative number is because
// when it gets converted to a positive number, it is now too large to be held by the signed data type and it overflows.


int main()
{
    int i1 = -12;
    int i2 = -2147483648;
    int i3 = 2147483647;

    char resultStr1[100];

    itoa(i1, resultStr1);
    printf("%s\n", resultStr1);

    itoa(i2, resultStr1);
    printf("%s\n", resultStr1);

    itoa(i3, resultStr1);
    printf("%s\n", resultStr1);
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    bool isMinInt = false;

    if ((sign = n) < 0)
    {
        if (n == INT_MIN)
        {
            isMinInt = true;
            n++;
        }
        n = -n;
    }

    i = 0;
    do {
       s[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';

        if (isMinInt)
        {
            // don't have to worry about tens place incrementing because this will never be a 9
            s[0]++;
        }
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int length;
    char temp;

    for (length = 0; s[length] != '\0'; length++)
        ;

    for (int i = length; i > length / 2; i--)
    {
        temp = s[length - i];
        s[length - i] = s[i - 1];
        s[i - 1] = temp;
    }
}