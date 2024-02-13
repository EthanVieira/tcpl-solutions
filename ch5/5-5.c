#include <stdio.h>

void strncpy_(char *s, char *t, int n)
{
    for (int i = 0; (i < n) && (*s = *t); i++, s++, t++)
        ;

    *s = '\0';
}

int strncat(char *s, char *t, int n)
{
    while (*++s)
        ;

    strncpy_(s, t, n);
}

int strncmp(char *s, char *t, int n)
{
    for (int i = 1; *s == *t; s++, t++, i++)
    {
        if (*s == '\0' || i >= n)
        {
            return 0;
        }
    }

    return *s - *t;
}

int main()
{
    char s1[32] = "Hello";
    char s2[32] = " World!";
    char s3[32] = "Hello World!";
    char s4[32] = "";
    char s5[32] = "H!";

    printf("%d\n", strncmp(s3, s1, 5));

    strncpy_(s4, s3, 4);
    printf("%s\n", s4);

    strncat(s1, s3, 2);
    printf("%s\n", s1);

    return 0;
}
