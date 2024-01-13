#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int i1 = 5706;

    char resultStr1[100];

    itoa(i1, resultStr1, 10);
    printf("%s\n", resultStr1);

    itoa(i1, resultStr1, 5);
    printf("%s\n", resultStr1);

    itoa(i1, resultStr1, 1);
    printf("%s\n", resultStr1);
    return 0;
}

void itoa(int n, char s[], int w)
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
    // pad blanks on left to make it width w including the trailing null
    while (i < w)
    {
        s[i++] = ' ';
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