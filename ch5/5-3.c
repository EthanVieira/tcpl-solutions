#include <stdio.h>

int strcat(char *s, char *t)
{
    while (*++s)
        ;

    while (*s++ = *t++)
        ;
}

int main()
{
    // make sure s1 has enough space
    char s1[32] = "Hello";
    char s2[32] = " World!";
    printf("%s\n", s1);
    printf("%s\n", s2);
    strcat(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}
