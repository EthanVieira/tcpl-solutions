#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int i1 = -12;
    int i2 = -2147483648;
    int i3 = 2147483647;

    char resultStr1[100];

    itob(i1, resultStr1, 2);
    printf("%s\n", resultStr1);

    itob(i2, resultStr1, 16);
    printf("%s\n", resultStr1); // This one will fail. Keeping to make the flaw obvious

    itob(i3, resultStr1, 16);
    printf("%s\n", resultStr1);
    return 0;
}

// doesnt handle min signed int nuance that is handled in 3-4
void itob(int n, char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;
    int temp;
    do {
        temp = n % b;
        if (temp > 10)
        {
            s[i++] = (temp - 9) + 'A';
        }
        else
        {
            s[i++] = temp + '0';
        }
    }
    while ((n /= b) > 0);


    if (sign < 0)
    {
        s[i++] = '-';
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