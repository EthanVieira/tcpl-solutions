#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char s[]);

int main()
{
    printf("%d\n", htoi("0xffFF"));

    return 0;
}

int htoi(char s[])
{
    // assume it is a valid hex string
    int i = 0;

    if (strlen(s) > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }

    int value = 0;

    for (i; isalnum(s[i]); i++)
    {
        int c = s[i];

        if (c >= '0' && c <= '9')
        {
            value = 16 * value + (c - '0');
        }
        else if (c >= 'a' && c <= 'f')
        {
            value = 16 * value + (c - 'a' + 10);
        }
        else if (c >= 'A' && c <= 'F')
        {
            value = 16 * value + (c - 'A' + 10);
        }
    }

    return value;
}

