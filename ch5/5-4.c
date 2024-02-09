#include <stdio.h>

int strend(char *s, char *t)
{
    // consider strings to always end with an empty string
    if (!*t)
    {
        return 1;
    }

    while (*s && *t)
    {
        if (*s++ == *t)
        {
            t++;
        }
    }

    return *s == *t;
}

int main()
{
    char s1[32] = "Hello";
    char s2[32] = " World!";
    char s3[32] = "Hello World!";
    char s4[32] = "";

    printf("'%s' ends '%s'?: %d\n", s1, s1, strend(s1, s1));
    printf("'%s' ends '%s'?: %d\n", s2, s1, strend(s1, s2));
    printf("'%s' ends '%s'?: %d\n", s3, s1, strend(s1, s3));
    printf("'%s' ends '%s'?: %d\n", s1, s2, strend(s2, s1));
    printf("'%s' ends '%s'?: %d\n", s3, s2, strend(s2, s3));
    printf("'%s' ends '%s'?: %d\n", s1, s3, strend(s3, s1));
    printf("'%s' ends '%s'?: %d\n", s2, s3, strend(s3, s2));
    printf("'%s' ends '%s'?: %d\n", s1, s4, strend(s4, s1));
    printf("'%s' ends '%s'?: %d\n", s4, s1, strend(s1, s4));
    printf("'%s' ends '%s'?: %d\n", s4, s4, strend(s4, s4));

    return 0;
}
